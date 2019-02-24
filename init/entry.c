#include "console.h"
#include "debug.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"


int kern_entry()
{
	init_debug();
	gdt_init();
	idt_init();

	console_clear();

	printk_color(rc_black, rc_green, "0224, Hello, OS kernel!\n");

	init_timer(200);
	//asm volatile ("int $0x4");
	__asm__ __volatile__("sti");

	return 0;
}


