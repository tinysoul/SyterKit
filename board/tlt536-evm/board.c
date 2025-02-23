/* SPDX-License-Identifier: GPL-2.0+ */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <types.h>

#include <log.h>

#include <common.h>

#include <reg-ncat.h>
#include <sys-clk.h>

#include <mmu.h>

#include <mmc/sys-sdhci.h>

#include <sys-dram.h>
#include <sys-gpio.h>
#include <sys-i2c.h>
#include <sys-sdcard.h>
#include <sys-sid.h>
#include <sys-spi.h>
#include <sys-uart.h>

sunxi_serial_t uart_dbg = {
        .base = SUNXI_UART0_BASE,
        .id = 0,
        .baud_rate = UART_BAUDRATE_115200,
        .dlen = UART_DLEN_8,
        .stop = UART_STOP_BIT_0,
        .parity = UART_PARITY_NO,
        .gpio_pin = {
                .gpio_tx = {GPIO_PIN(GPIO_PORTB, 9), GPIO_PERIPH_MUX2},
                .gpio_rx = {GPIO_PIN(GPIO_PORTB, 10), GPIO_PERIPH_MUX2},
        },
        .uart_clk = {
                .gate_reg_base = SUNXI_CCU_BASE + UART0_BGR_REG,
                .gate_reg_offset = SERIAL_DEFAULT_CLK_GATE_OFFSET(0),
                .rst_reg_base = SUNXI_CCU_BASE + UART0_BGR_REG,
                .rst_reg_offset = SERIAL_DEFAULT_CLK_RST_OFFSET(0),
                .parent_clk = SERIAL_DEFAULT_PARENT_CLK,
        },
};

sunxi_i2c_t i2c_pmu = {
    .base = SUNXI_RTWI_BASE,
    .id = SUNXI_R_I2C0,
    .speed = SUNXI_I2C_SPEED_400K,
    .gpio = {
            .gpio_scl = {GPIO_PIN(GPIO_PORTL, 0), GPIO_PERIPH_MUX2},
            .gpio_sda = {GPIO_PIN(GPIO_PORTL, 1), GPIO_PERIPH_MUX2},
    },
    .i2c_clk = {
            .gate_reg_base = SUNXI_RTWI_BRG_REG,
            .gate_reg_offset = TWI_DEFAULT_CLK_GATE_OFFSET(0),
            .rst_reg_base = SUNXI_RTWI_BRG_REG,
            .rst_reg_offset = TWI_DEFAULT_CLK_RST_OFFSET(0),
            .parent_clk = 24000000,
    },
};

void neon_enable(void) {
    /* set NSACR, both Secure and Non-secure access are allowed to NEON */
    asm volatile("MRC p15, 0, r0, c1, c1, 2");
    asm volatile("ORR r0, r0, #(0x3<<10) @ enable fpu/neon");
    asm volatile("MCR p15, 0, r0, c1, c1, 2");
    /* Set the CPACR for access to CP10 and CP11*/
    asm volatile("LDR r0, =0xF00000");
    asm volatile("MCR p15, 0, r0, c1, c0, 2");
    /* Set the FPEXC EN bit to enable the FPU */
    asm volatile("MOV r3, #0x40000000");
    /*@VMSR FPEXC, r3*/
    asm volatile("MCR p10, 7, r3, c8, c0, 0");
}

void clean_syterkit_data(void) {
    /* Disable MMU, data cache, instruction cache, interrupts */
    arm32_mmu_disable();
    printk_info("disable mmu ok...\n");
    arm32_dcache_disable();
    printk_info("disable dcache ok...\n");
    arm32_icache_disable();
    printk_info("disable icache ok...\n");
    arm32_interrupt_disable();
    printk_info("free interrupt ok...\n");
}

#define GPIO_POW_MOD_SEL (SUNXI_GPIO_BASE + 0x40)
#define R_GPIO_POW_MOD_SEL (SUNXI_R_GPIO_BASE + 0x340)
#define GPIO_POW_MOD_SEL_MASK (0x033ffff3)
#define R_GPIO_POW_MOD_SEL_MASK (0xf)

void sunxi_gpio_power_mode_init(void) {
	uint32_t reg_val;
	reg_val = readl(GPIO_POW_MOD_SEL);
	reg_val &= ~GPIO_POW_MOD_SEL_MASK;
	reg_val |= 0x022AAAA2;
	writel(reg_val, GPIO_POW_MOD_SEL);

	reg_val = readl(R_GPIO_POW_MOD_SEL);
	reg_val &= ~R_GPIO_POW_MOD_SEL_MASK;
	reg_val |= 0xA;
	writel(reg_val, R_GPIO_POW_MOD_SEL);
}

void show_chip() {
    uint32_t chip_sid[4];
    chip_sid[0] = read32(SUNXI_SID_SRAM_BASE + 0x0);
    chip_sid[1] = read32(SUNXI_SID_SRAM_BASE + 0x4);
    chip_sid[2] = read32(SUNXI_SID_SRAM_BASE + 0x8);
    chip_sid[3] = read32(SUNXI_SID_SRAM_BASE + 0xc);

    printk_info("Chip SID = %08x%08x%08x%08x\n", chip_sid[0], chip_sid[1], chip_sid[2], chip_sid[3]);

    uint32_t chip_markid_sid = chip_sid[0] & 0xffff;

    switch (chip_markid_sid) {
        case 0x5f00:
            printk_info("Chip type = T536MX-CXX");
            break;
        default:
            printk_info("Chip type = UNKNOW");
            break;
    }

    setbits_le32(SUNXI_SYSCTRL_BASE + 0x24, BIT(15));
    uint32_t version = (read32(SUNXI_SYSCTRL_BASE + 0x24) & 0xFFFF0007) >> 16;
    printk(LOG_LEVEL_MUTE, " Chip Version = 0x%04x \n", version);
}