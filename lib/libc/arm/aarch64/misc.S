#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <platform_def.h>

    .global zeromem

func zeromem
    /* x2 is the address past the last zeroed address */
    add x2, x0, x1
    /*
     * Uses the fallback path that does not use DC ZVA instruction and
     * therefore does not need enabled MMU
     */
    b .Lzeromem_dczva_fallback_entry
endfunc zeromem

func zeromem_dczva
    /*
     * The function consists of a series of loops that zero memory one byte
     * at a time, 16 bytes at a time or using the DC ZVA instruction to
     * zero aligned block of bytes, which is assumed to be more than 16.
     * In the case where the DC ZVA instruction cannot be used or if the
     * first 16 bytes loop would overflow, there is fallback path that does
     * not use DC ZVA.
     * Note: The fallback path is also used by the zeromem function that
     *       branches to it directly.
     *       +--------+ 
     *       |        | 
     *       |        v 
     *       |   +-------+-------+ .Lzeromem_dczva_final_16bytes_aligned
     *       |   | 16 bytes loop |      |
     *       |   +-------+-------+      |
     *       |           |              |
     *       |           v              |
     *       |    +------+------+ .Lzeromem_dczva_final_1byte_aligned
     *       |    | 1 byte loop |       |
     *       |    +-------------+       |
     *       |           |              |
     *       |           v              |
     *       |       +---+--+           |
     *       |       | exit |           |
     *       |       +------+           |
     *       |           |
     *       |           +--------------+    +------------------+ zeromem
     *       |           |  +----------------| zeromem function |
     *       |           |  |                +------------------+
     *       |           v  v
     *       |    +-------------+ .Lzeromem_dczva_fallback_entry
     *       |    | 1 byte loop |
     *       |    +------+------+
     *       |           |
     *       +-----------+
     */

    /*
     * Readable names for registers
     *
     * Registers x0, x1 and x2 are also set by zeromem which
     * branches into the fallback path directly, so cursor, length and
     * stop_address should not be retargeted to other registers.
     */
    cursor       .req x0 /* Start address and then current address */
    length       .req x1 /* Length in bytes of the region to zero out */
    /* Reusing x1 as length is never used after block_mask is set */
    block_mask   .req x1 /* Bitmask of the block size read in DCZID_EL0 */
    stop_address .req x2 /* Address past the last zeroed byte */
    block_size   .req x3 /* Size of a block in bytes as read in DCZID_EL0 */
    tmp1         .req x4
    tmp2         .req x5
    /*
     * Fourth loop: zero 16 bytes at a time and then byte per byte the
     * remaining area
     */
.Lzeromem_dczva_final_16bytes_aligned:
    /*
     * Calculate the last 16 bytes aligned address. It is assumed that the
     * block size will never be smaller than 16 bytes so that the current
     * cursor is aligned to at least 16 bytes boundary.
     */
    bic tmp1, stop_address, #15

    cmp cursor, tmp1
    b.hs 2f
1:
    stp xzr, xzr, [cursor], #16
    cmp cursor, tmp1
    b.lo 1b
2:

    /* Fifth and final loop: zero byte per byte */
.Lzeromem_dczva_final_1byte_aligned:
    cmp cursor, stop_address
    b.eq 2f
1:
    strb wzr, [cursor], #1
    cmp cursor, stop_address
    b.ne 1b
2:
    ret

    /* Fallback for unaligned start addresses */
.Lzeromem_dczva_fallback_entry:
    /*
     * If the start address is already aligned to 16 bytes, skip this loop.
     */
    tst cursor, #0xf
    b.eq .Lzeromem_dczva_final_16bytes_aligned

    /* Calculate the next address aligned to 16 bytes */
    orr tmp1, cursor, #15
    add tmp1, tmp1, #1
    /* If it overflows, fallback to byte per byte zeroing */
    cbz tmp1, .Lzeromem_dczva_final_1byte_aligned
    /* If the next aligned address is after the stop address, fall back */
    cmp tmp1, stop_address
    b.hs .Lzeromem_dczva_final_1byte_aligned

    /* Fallback entry loop: zero byte per byte */
1:
    strb wzr, [cursor], #1
    cmp cursor, tmp1
    b.ne 1b

    b .Lzeromem_dczva_final_16bytes_aligned

    .unreq    cursor
    /*
     * length is already unreq'ed to reuse the register for another
     * variable.
     */
    .unreq stop_address
    .unreq block_size
    .unreq block_mask
    .unreq tmp1
    .unreq tmp2
endfunc zeromem_dczva
