/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-02     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define LED_PIN GET_PIN(I, 8)
void lcd_fill_color(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint8_t color);
extern uint32_t cnt1;
int main(void)
{
	rt_uint8_t color = 0x00;
	rt_uint32_t count = 1;
	rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
	uint16_t x = 500, y = 200;
//	memset(LCD_BUFFER, 0xff, sizeof(LCD_BUFFER));
	lcd_fill_color(x, x + 50, y, y + 50, 0xd0);
    while(count++)
    {
		rt_kprintf("cnt1=%d\r\n", cnt1);
		rt_thread_mdelay(1000);
    }
    return RT_EOK;
}
void lcd_fill_color(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint8_t color)
{
	for(;y1 < y2; ++y1)
	{
		uint16_t x = x1;
		for(;x < x2; ++x);
//			LCD_BUFFER1[y1][x] = color;
	}
}
#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);

