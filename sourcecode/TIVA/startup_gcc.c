extern int main(void);
void rst_handler(void);
void nmi_handler(void);
void empty_def_handler(void);
void hardfault_handler(void);
extern void UARTIntHandler(void);

extern unsigned long _stack_top;
extern unsigned long _start_text;
extern unsigned long _end_text;
extern unsigned long _start_data;
extern unsigned long _end_data;
extern unsigned long _start_bss;
extern unsigned long _end_bss;
__attribute__ ((section(".nvic_table")))
void (*myvectors[])(void) = {
		(void (*)) &_stack_top,
		rst_handler,
		nmi_handler,
		hardfault_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		UARTIntHandler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		0,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		empty_def_handler,
		0,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		0,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		empty_def_handler,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0 
};
void rst_handler(void) {
	unsigned long *src;
	unsigned long *dest;
	src = &_end_text;
	dest = &_start_data;
	while (dest < &_end_data) {
		*dest++ = *src++;
	}
	dest = &_start_bss;
	while (dest < &_end_bss) {
		*dest++ = 0;
	}
	main();
}
void nmi_handler(void) {

	while (1) {
	}
}
void hardfault_handler(void) {
	while (1) {
	}
}
void empty_def_handler(void) {

	while (1) {
	}
}
