/**
 * file gdt.c
 * @brief 
 * author He Xin, hexin900110@163.com
 * version 1.0
 * date 2019-02-16
 */
#include "gdt.h"
#include "types.h"

typedef struct {
	uint16_t  limit_low;		
	uint16_t  base_low;		
	uint8_t   base_middle;
	uint8_t   access;
	uint8_t   granularity;
	uint8_t   base_high;
}__attribute__((packed)) gdt_desc;

typedef struct {
	uint16_t limit;
	uint32_t base;
}__attribute__((packed)) gdt_ptr_t;

extern void gdtr_load(uint32_t gdtr);

#define GDT_LENGTH  5

gdt_desc   gdt_desc_attr[GDT_LENGTH];
gdt_ptr_t  gdt_ptr;

int32_t gdt_set_gate(gdt_desc *gdt_desc_ptr, uint32_t base, uint32_t limit,
		             uint8_t access, uint8_t granularity)
{
	gdt_desc_ptr->limit_low = limit & 0xFFFF;
	gdt_desc_ptr->base_low  = base  & 0xFFFF;
	gdt_desc_ptr->base_middle = (base >> 16) & 0xFF;
	gdt_desc_ptr->access = access;
	gdt_desc_ptr->granularity = (granularity & 0xF0) | ((limit >> 16) & 0x0F);
	gdt_desc_ptr->base_high = (base >> 24) & 0xFF;

	return 0;
}

/**
 * @brief gdt_init 
 */
void gdt_init()
{
	gdt_ptr.base  = (uint32_t)gdt_desc_attr;
	gdt_ptr.limit = sizeof(gdt_desc) * GDT_LENGTH - 1;

	/*
	 * linux 2.4.0
	 */
	gdt_set_gate(gdt_desc_attr, 0, 0, 0, 0);
	gdt_set_gate(gdt_desc_attr + 1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_gate(gdt_desc_attr + 2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_set_gate(gdt_desc_attr + 3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
	gdt_set_gate(gdt_desc_attr + 4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

	gdtr_load((uint32_t)&gdt_ptr);
}
