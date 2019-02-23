#include "types.h"
#include "string.h"
#include "debug.h"

extern void idtr_load(uint32_t addr);

void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();

void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();

void isr255();

typedef struct pt_regs_t {
	uint32_t ds;		// 用于保存用户的数据段描述符
	uint32_t edi; 		// 从 edi 到 eax 由 pusha 指令压入
	uint32_t esi; 
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
	uint32_t int_no; 	// 中断号
	uint32_t err_code;  	// 错误代码(有中断错误代码的中断会由CPU压入)
	uint32_t eip;		// 以下由处理器自动压入
	uint32_t cs; 		
	uint32_t eflags;
	uint32_t useresp;
	uint32_t ss;
} pt_regs;

typedef struct {
	uint16_t addr_low;
	uint16_t seg_select;
	uint8_t  reserve;
	uint8_t  type_config; 
	uint16_t addr_high;
} __attribute__((packed)) idt_desc ;

struct {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) idt_ptr_t;
idt_desc idt_table[256];

/*
 * learn linux 2.4.0
 */
#define _set_gate(gate_addr, type, dpl, addr)  \
do {  \
	int32_t __d0, __d1;  \
	__asm__ __volatile__( \
		"movw %%dx, %%ax \n\t"  \
		"movw %4,   %%dx \n\t"  \
		"movl %%eax, %0 \n\t"   \
		"movl %%edx, %1"   \
		:"=m" (*((long *)(gate_addr))), \
		 "=m" (*(1 + (long *)(gate_addr))), "=&a" (__d0), "=&d" (__d1) \
		:"i" ((short)(0x8000 + (type << 8) + (dpl << 13))) , \
		 "3" ((char *)(addr)), "2" (0x08 << 16));\
}while(0);

void set_intr_gate(uint32_t n, void *addr)
{
	_set_gate(idt_table + n, 14, 0, addr);
}

typedef void (* irq_handle)(pt_regs *regs);
irq_handle irq_handle_table[256];

void isr_handler(pt_regs *regs)
{
	if(irq_handle_table[regs->int_no]) {
		irq_handle_table[regs->int_no](regs);
	} else {
		printk_color(rc_black, rc_blue, "Unhandled interrupt: %d\n", regs->int_no);
	}
}

void idt_init()
{
	bzero((uint8_t *)irq_handle_table, sizeof(irq_handle_table));

	idt_ptr_t.limit = sizeof(idt_table) - 1;
	idt_ptr_t.base  = (uint32_t)idt_table;

	set_intr_gate(1,  (void *)isr0);
	set_intr_gate(2,  (void *)isr2);
	set_intr_gate(3,  (void *)isr3);
	set_intr_gate(4,  (void *)isr4);
	set_intr_gate(5,  (void *)isr5);
	set_intr_gate(6,  (void *)isr6);
	set_intr_gate(7,  (void *)isr7);
	set_intr_gate(8,  (void *)isr8);
	set_intr_gate(9,  (void *)isr9);
	set_intr_gate(10, (void *)isr10);
	set_intr_gate(11, (void *)isr11);
	set_intr_gate(12, (void *)isr12);
	set_intr_gate(13, (void *)isr13);
	set_intr_gate(14, (void *)isr14);
	set_intr_gate(15, (void *)isr15);
	set_intr_gate(16, (void *)isr16);
	set_intr_gate(17, (void *)isr17);
	set_intr_gate(18, (void *)isr18);
	set_intr_gate(19, (void *)isr19);
	set_intr_gate(20, (void *)isr20);
	set_intr_gate(21, (void *)isr21);
	set_intr_gate(22, (void *)isr22);
	set_intr_gate(23, (void *)isr23);
	set_intr_gate(24, (void *)isr24);
	set_intr_gate(25, (void *)isr25);
	set_intr_gate(26, (void *)isr26);
	set_intr_gate(27, (void *)isr27);
	set_intr_gate(28, (void *)isr28);
	set_intr_gate(29, (void *)isr29);
	set_intr_gate(30, (void *)isr30);
	set_intr_gate(31, (void *)isr31);

	set_intr_gate(255, (void *)isr255);

	idtr_load((uint32_t)&idt_ptr_t);
	/*
	 * TODO
	 */
}
