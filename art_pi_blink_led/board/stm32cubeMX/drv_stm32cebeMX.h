#ifndef __DRV_STM32CEBEMX__
#define __DRV_STM32CEBEMX__
#include <rtthread.h>
#include <board.h>
#include <drv_common.h>
#include <rtdevice.h>
#define PIXELS_W	1024
#define PIXELS_H	600
#define LTDC_BUFF_ADDR 0XC0000000
#define GFXMMU_VIRTUAL_BUFFERS_BASE  (0x25000000UL)
#endif