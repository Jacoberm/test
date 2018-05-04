STARTUP(vectors.o)
ENTRY(reset_vector)
INPUT(extras.o)
GROUP(libtarget.a libgcc.a libsupc++.a)


MEMORY
{
    sram : ORIGIN = 0x20000000 - 0x00010000, LENGTH = 0x00020000 -4096
    flash : ORIGIN = 0x00000000, LENGTH = 0x00080000
    ramcod : ORIGIN = 0x08000000, LENGTH = 0x02000000
    ram : ORIGIN = 0x72000000, LENGTH = 0x04000000 -4096
    ramnc : ORIGIN = 0x86000000, LENGTH = 0x02000000
}

SECTIONS
{
    .debug_aranges 0 : { *(.debug_aranges) } .debug_pubnames 0 : { *(.debug_pubnames) } .debug_info 0 : { *(.debug_info) } .debug_abbrev 0 : { *(.debug_abbrev) } .debug_line 0 : { *(.debug_line) } .debug_frame 0 : { *(.debug_frame) } .debug_str 0 : { *(.debug_str) } .debug_loc 0 : { *(.debug_loc) } .debug_macinfo 0 : { *(.debug_macinfo) } .note.arm.ident 0 : { KEEP (*(.note.arm.ident)) } /DISCARD/ 0 : { *(.fini_array*) }
    .sram 0x20000000 - 0x00010000 + 0x400 + 0x100 : { __sram_data_start = ABSOLUTE (.); *(.sram*) . = ALIGN (4); } > sram __srom_data_start = LOADADDR (.sram); __sram_data_end = .; PROVIDE (__sram_data_end = .); PROVIDE (__srom_data_end = LOADADDR (.sram) + SIZEOF(.sram));
    .rom_vectors 0x08000000 : { __rom_vectors_vma = ABSOLUTE(.); . = .; KEEP (*(.vectors)) } > ramcod __rom_vectors_lma = LOADADDR(.rom_vectors);
    .rel.text : { *(.rel.text) *(.rel.text.*) *(.rel.gnu.linkonce.t*) } > ramcod .rela.text : { *(.rela.text) *(.rela.text.*) *(.rela.gnu.linkonce.t*) } > ramcod .rel.data : { *(.rel.data) *(.rel.data.*) *(.rel.gnu.linkonce.d*) } > ramcod .rela.data : { *(.rela.data) *(.rela.data.*) *(.rela.gnu.linkonce.d*) } > ramcod .rel.rodata : { *(.rel.rodata) *(.rel.rodata.*) *(.rel.gnu.linkonce.r*) } > ramcod .rela.rodata : { *(.rela.rodata) *(.rela.rodata.*) *(.rela.gnu.linkonce.r*) } > ramcod .rel.got : { *(.rel.got) } > ramcod .rela.got : { *(.rela.got) } > ramcod .rel.ctors : { *(.rel.ctors) } > ramcod .rela.ctors : { *(.rela.ctors) } > ramcod .rel.dtors : { *(.rel.dtors) } > ramcod .rela.dtors : { *(.rela.dtors) } > ramcod .rel.init : { *(.rel.init) } > ramcod .rela.init : { *(.rela.init) } > ramcod .rel.fini : { *(.rel.fini) } > ramcod .rela.fini : { *(.rela.fini) } > ramcod .rel.bss : { *(.rel.bss) } > ramcod .rela.bss : { *(.rela.bss) } > ramcod .rel.plt : { *(.rel.plt) } > ramcod .rela.plt : { *(.rela.plt) } > ramcod .rel.dyn : { *(.rel.dyn) } > ramcod
    .ARM.extab ALIGN (0x8) : { PROVIDE (__stext = ABSOLUTE(.));_stext = ABSOLUTE(.) ; . = .; *(.ARM.extab* .gnu.linkonce.armextab.*) } > ramcod . = ALIGN(8); __exidx_start = ABSOLUTE(.); .ARM.exidx ALIGN(8) : AT ((LOADADDR (.ARM.extab) + SIZEOF (.ARM.extab) + (8) - 1) & ~ ((8) - 1)) { *(.ARM.exidx* .gnu.linkonce.armexidx.*) . = .; } > ramcod __exidx_end = ABSOLUTE(.); .text ALIGN(8) : AT ((LOADADDR (.ARM.exidx) + SIZEOF (.ARM.exidx) + (8) - 1) & ~ ((8) - 1)) { *(.text*) *(.gnu.warning) *(.gnu.linkonce.t.*) *(.init) *(.glue_7) *(.glue_7t) __CTOR_LIST__ = ABSOLUTE (.); KEEP (*(SORT (.ctors*))) __CTOR_END__ = ABSOLUTE (.); __DTOR_LIST__ = ABSOLUTE (.); KEEP (*(SORT (.dtors*))) __DTOR_END__ = ABSOLUTE (.); } > ramcod _etext = .; PROVIDE (__etext = .);
    .fini ALIGN (0x8) : { . = .; *(.fini) } > ramcod
    .rodata 0x72000000 + 0x00020000 : { . = .; *(.rodata*) *(.gnu.linkonce.r.*) } > ram
    .rodata1 ALIGN (0x8) : { . = .; *(.rodata1) } > ram
    .fixup ALIGN (0x8) : { . = .; *(.fixup) } > ram
    .gcc_except_table ALIGN (0x8) : { . = .; KEEP(*(.gcc_except_table)) *(.gcc_except_table.*) } > ram
    .eh_frame ALIGN (0x8) : { . = .; __EH_FRAME_BEGIN__ = .; KEEP(*(.eh_frame)) __FRAME_END__ = .; . = . + 8; } > ram = 0
    .got ALIGN (0x8) : { . = .; *(.got.plt) *(.got) _GOT1_START_ = ABSOLUTE (.); *(.got1) _GOT1_END_ = ABSOLUTE (.); _GOT2_START_ = ABSOLUTE (.); *(.got2) _GOT2_END_ = ABSOLUTE (.); } > ramcod
    .data ALIGN (0x8) : { __ram_data_start = ABSOLUTE (.); *(.data*) *(.data1) *(.gnu.linkonce.d.*) . = ALIGN (4); KEEP(*( SORT (.ecos.table.*))) ; . = ALIGN (4); __init_array_start__ = ABSOLUTE (.); KEEP (*(SORT (.init_array.*))) KEEP (*(SORT (.init_array))) __init_array_end__ = ABSOLUTE (.); *(.dynamic) *(.sdata*) *(.gnu.linkonce.s.*) . = ALIGN (4); *(.2ram.*) } > ram __rom_data_start = LOADADDR (.data); __ram_data_end = .; PROVIDE (__ram_data_end = .); _edata = .; PROVIDE (edata = .); PROVIDE (__rom_data_end = LOADADDR (.data) + SIZEOF(.data));
    .bss ALIGN (0x8) : { __bss_start = ABSOLUTE (.); *(.scommon) *(.dynsbss) *(.sbss*) *(.gnu.linkonce.sb.*) *(.dynbss) *(.bss*) *(.gnu.linkonce.b.*) *(COMMON) __bss_end = ABSOLUTE (.); } > ram
    __heap1 = ALIGN (0x8);
    .noncache 0x86000000 (NOLOAD) : { __noncache_start = ABSOLUTE (.); *(.noncache*) __noncache_end = ABSOLUTE (.); } > ramnc
    . = ALIGN(4); _end = .; PROVIDE (end = .);
}

hal_vsr_table = (0x20000000 - 0x00010000);
hal_virtual_vector_table = hal_vsr_table + 128*4;
hal_startup_stack = 0x20000000 + 0x00010000;
