#include <rtthread.h>
#include <rtdevice.h>
#include "rtconfig.h"
#include "app_ram.h"

struct rt_memheap axi_sram_heap;
void *axi_sram_malloc(unsigned long size)
{
    return rt_memheap_alloc(&axi_sram_heap,size);
}

void axi_sram_free(void *ptr)
{
    rt_memheap_free(ptr);
}

void *axi_sram_calloc(unsigned int n,unsigned int size)
{
    void* ptr = NULL;
    
    ptr = axi_sram_malloc(n * size);
    if(ptr)
    {
        memset(ptr, 0, n*size);
    }
    
    return ptr;
}

