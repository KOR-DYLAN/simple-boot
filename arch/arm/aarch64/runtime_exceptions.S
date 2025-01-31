#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>

    .global runtime_exceptions

    .global sync_exception_sp_el0
    .global irq_sp_el0
    .global fiq_sp_el0
    .global serror_sp_el0

    .global sync_exception_sp_elx
    .global irq_sp_elx
    .global fiq_sp_elx
    .global serror_sp_elx

    .global sync_exception_aarch64
    .global irq_aarch64
    .global fiq_aarch64
    .global serror_aarch64

    .global sync_exception_aarch32
    .global irq_aarch32
    .global fiq_aarch32
    .global serror_aarch32

vector_base runtime_exceptions

/*******************************************************************
 * Current EL with SP_EL0 : 0x0 - 0x200
 *******************************************************************/
/* offset: VBAR_EL3 + 0x0000 */
vector_entry sync_exception_sp_el0
    b .
end_vector_entry sync_exception_sp_el0

/* offset: VBAR_EL3 + 0x0080 */
vector_entry irq_sp_el0
    b .
end_vector_entry irq_sp_el0

/* offset: VBAR_EL3 + 0x0100 */
vector_entry fiq_sp_el0
    b .
end_vector_entry fiq_sp_el0

/* offset: VBAR_EL3 + 0x0180 */
vector_entry serror_sp_el0
    b .
end_vector_entry serror_sp_el0

/*******************************************************************
 * Current EL with SP_ELx: 0x200 - 0x400
 *******************************************************************/
/* offset: VBAR_EL3 + 0x0200 */
vector_entry sync_exception_sp_elx
    b .
end_vector_entry sync_exception_sp_elx

/* offset: VBAR_EL3 + 0x0280 */
vector_entry irq_sp_elx
    b .
end_vector_entry irq_sp_elx

/* offset: VBAR_EL3 + 0x0300 */
vector_entry fiq_sp_elx
    b .
end_vector_entry fiq_sp_elx

/* offset: VBAR_EL3 + 0x0380 */
vector_entry serror_sp_elx
    b .
end_vector_entry serror_sp_elx

/*******************************************************************
 * Lower EL using AArch64 : 0x400 - 0x600
 *******************************************************************/
/* offset: VBAR_EL3 + 0x0400 */
vector_entry sync_exception_aarch64
    b .
end_vector_entry sync_exception_aarch64

/* offset: VBAR_EL3 + 0x0480 */
vector_entry irq_aarch64
    b .
end_vector_entry irq_aarch64

/* offset: VBAR_EL3 + 0x0500 */
vector_entry fiq_aarch64
    b .
end_vector_entry fiq_aarch64

/* offset: VBAR_EL3 + 0x0580 */
vector_entry serror_aarch64
    b .
end_vector_entry serror_aarch64

/*******************************************************************
 * Lower EL using AArch32 : 0x600 - 0x800
 *******************************************************************/
/* offset: VBAR_EL3 + 0x0600 */
vector_entry sync_exception_aarch32
    b .
end_vector_entry sync_exception_aarch32

/* offset: VBAR_EL3 + 0x0680 */
vector_entry irq_aarch32
    b .
end_vector_entry irq_aarch32

/* offset: VBAR_EL3 + 0x0700 */
vector_entry fiq_aarch32
    b .
end_vector_entry fiq_aarch32

/* offset: VBAR_EL3 + 0x0780 */
vector_entry serror_aarch32
    b .
end_vector_entry serror_aarch32
