MEMORY
{
FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000
RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
STACK (rwx) : ORIGIN = 0x20007FFF , LENGTH = 0x00000000
}

SECTIONS
{
.mydata1 0x20000000 :
{
. = ALIGN(1);
*(.mydata1.*)
. = ALIGN(8);
}>RAM

.mydata2 0x20000070 :
{
. = ALIGN(1);
*(.mydata2.*)
. = ALIGN(8);
}>RAM

.mydata3 0x20000100 :
{
. = ALIGN(1);
*(.mydata3.*)
. = ALIGN(8);
}>RAM

.mydata4 0x20000170 :
{
. = ALIGN(1);
*(.mydata4.*)
. = ALIGN(8);
}>RAM

.text :
{
KEEP(*(.nvic_table))
KEEP(*(.isr_vector))
*(.text.*)
*(.rodata.*)
_end_text = .;
}>FLASH

.data :
{
_start_data = .;
*(.data.*)
*(vtable)
_end_data = .;
}>RAM AT >FLASH

.bss :
{
_start_bss = .;
*(.bss.*)
*(COMMON)
_end_bss = .; 
}>RAM

.stack :
{
_stack_top = .;
}>STACK
}
