#ifndef __APP_RAM_H__
#define __APP_RAM_H__
#include <rtthread.h>
#include <stm32h7xx.h>
#include "string.h"

#define RT_AXI_SRAM_BEGIN 0x24000000
#define RT_AXI_SRAM_SIZE  0x80000 

void *axi_sram_malloc(unsigned long size);
void axi_sram_free(void *ptr);
void *axi_sram_calloc(unsigned int n,unsigned int size);

#endif
