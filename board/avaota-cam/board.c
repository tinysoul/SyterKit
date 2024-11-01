#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <types.h>

#include <log.h>

#include <common.h>

#include <reg-ncat.h>
#include <sys-clk.h>

#include <mmu.h>

#include <sys-gpio.h>
#include <sys-sdcard.h>
#include <sys-dram.h>
#include <sys-spi.h>
#include <sys-uart.h>

sunxi_serial_t uart_dbg = {
        .base = SUNXI_UART0_BASE,
        .id = 0,
        .gpio_tx = {GPIO_PIN(GPIO_PORTL, 4), GPIO_PERIPH_MUX3},
        .gpio_rx = {GPIO_PIN(GPIO_PORTL, 5), GPIO_PERIPH_MUX3},
};

dram_para_t dram_para = {
	.dram_clk            = 528,
	.dram_type           = 2,
	.dram_zq             = 0x7b7bf9,
	.dram_odt_en         = 0x00,
	.dram_para1          = 0x000000d2,
	.dram_para2          = 0x00400000,
	.dram_mr0            = 0x00000E73,
	.dram_mr1            = 0x02,
	.dram_mr2            = 0x0,
	.dram_mr3            = 0x0,
	.dram_tpr0           = 0x00471992,
	.dram_tpr1           = 0x0131A10C,
	.dram_tpr2           = 0x00057041,
	.dram_tpr3           = 0xB4787896,
	.dram_tpr4           = 0x0,
	.dram_tpr5           = 0x48484848,
	.dram_tpr6           = 0x48,
	.dram_tpr7           = 0x1621121e,
	.dram_tpr8           = 0x0,
	.dram_tpr9           = 0x0,
	.dram_tpr10          = 0x00000000,
	.dram_tpr11          = 0x00000000,
	.dram_tpr12          = 0x00000000,
	.dram_tpr13          = 0x34000100,
};

void show_chip() {
    uint32_t chip_sid[4];
    chip_sid[0] = read32(SUNXI_SID_SRAM_BASE + 0x0);
    chip_sid[1] = read32(SUNXI_SID_SRAM_BASE + 0x4);
    chip_sid[2] = read32(SUNXI_SID_SRAM_BASE + 0x8);
    chip_sid[3] = read32(SUNXI_SID_SRAM_BASE + 0xc);

    printk_info("Model: AvaotaSBC Avaota CAM board.\n");
    printk_info("Core: XuanTie E907 RISC-V Core.\n");
    printk_info("Chip SID = %08x%08x%08x%08x\n", chip_sid[0], chip_sid[1], chip_sid[2], chip_sid[3]);
}