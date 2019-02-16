#include "console.h"
#include "debug.h"
#include "gdt.h"


int kern_entry()
{
	init_debug();
	gdt_init();

	console_clear();

	printk_color(rc_black, rc_green, "0216, Hello, OS kernel!\n");


	return 0;
}


