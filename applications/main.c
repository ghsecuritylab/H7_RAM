/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-05     whj4674672   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "app_ram.h"
/* defined the LED0 pin: PB1 */
#define LED0_PIN    GET_PIN(B, 10)
    uint8_t test_buff[100]= {0};
int main(void)
{   
    int count = 1;
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    
    char *test_ptr;
    test_buff[10] = 1; 
    while (count++)
    {
        //test_ptr = axi_sram_malloc(100);
        test_ptr = rt_malloc(100);
        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_thread_mdelay(500);
        //axi_sram_free(test_ptr);
        rt_free(test_ptr);
    }
    return RT_EOK;
}
