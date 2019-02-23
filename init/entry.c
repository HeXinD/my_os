#include "console.h"
#include "debug.h"
#include "gdt.h"
#include "idt.h"


int kern_entry()
{
	init_debug();
	gdt_init();
	idt_init();

	console_clear();

	printk_color(rc_black, rc_green, "0216, Hello, OS kernel!\n");

	asm volatile ("int $0x3");
	asm volatile ("int $0x4");


	return 0;
}


