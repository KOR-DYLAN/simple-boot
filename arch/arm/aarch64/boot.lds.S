#include <platform.h>

OUTPUT_FORMAT(PLAT_LINKER_FORMAT)
OUTPUT_ARCH(PLAT_LINKER_ARCH)
ENTRY(image_entrypoint)

MEMORY {
    RAM (rwx): ORIGIN = PLAT_IMAGE_BASE, LENGTH = PLAT_IMAGE_LIMIT - PLAT_IMAGE_BASE
}

SECTIONS
{
    . = PLAT_IMAGE_BASE;
    ASSERT(. == ALIGN(PAGE_SIZE), "PLAT_IMAGE_BASE address is not aligned on a page boundary.")

    __IMAGE_START__ = .;
    .text . : {
        __TEXT_START__ = .;
        *startup.o(.text*)
        *(SORT_BY_ALIGNMENT(SORT(.text*)))
        *(.vectors)
        . = ALIGN(PAGE_SIZE);
        __TEXT_END__ = .;
    } >RAM

    .rodata : {
        __RODATA_START__ = .;
        *(SORT_BY_ALIGNMENT(.rodata*))

        . = ALIGN(PAGE_SIZE);
         __RODATA_END__ = .;
    } >RAM


    /*
     * Define a linker symbol to mark start of the RW memory area for this image.
     */
    __RW_START__ = . ;
    /*
     * .data must be placed at a lower address than the stacks if the stack protector is enabled. 
     * Alternatively, the .data.stack_protector_canary section can be placed independently of the main .data section.
     */
    .data . : ALIGN(DATA_ALIGN) {
        __DATA_START__ = .;
        *(SORT_BY_ALIGNMENT(.data*))
        __DATA_END__ = .;
    } >RAM

    /*
     * .rela.dyn needs to come after .data for the read-elf utility to parse this section correctly.
     */
    .rela.dyn : ALIGN(STRUCT_ALIGN) {
        __RELA_START__ = .;
        *(.rela*)
        __RELA_END__ = .;
    } >RAM

    stacks (NOLOAD) : {
        __STACKS_START__ = .;
        . = . + PLAT_STACK_SIZE;
        __STACKS_END__ = .;
    } >RAM

    /*
     * The .bss section gets initialised to 0 at runtime.
     * Its base address has bigger alignment for better performance of the zero-initialization code.
     */
    .bss (NOLOAD) : ALIGN(BSS_ALIGN) { 
        __BSS_START__ = .;
        *(SORT_BY_ALIGNMENT(.bss*))
        *(COMMON)
        __BSS_END__ = .;
    } >RAM

    /*
     * Define a linker symbol to mark end of the RW memory area for this image.
     */
    __RW_END__ = .;
    __IMAGE_END__ = .;
    ASSERT(. <= PLAT_IMAGE_LIMIT, "IMAGE has exceeded its limit.")

    /DISCARD/ : {
        *(.dynsym .dynstr .hash .gnu.hash)
    }
}
