#ifndef _IDT_H_
#define _IDT_H_

typedef void (* irq_handle)(void *param, int vector);

void idt_init();
void isr_register(int irq_num, irq_handle isr_fun, void *param);
#endif
