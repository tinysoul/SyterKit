/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __SUN20IW5_REG_NCAT_H__
#define __SUN20IW5_REG_NCAT_H__

#define SUNXI_BROM_BASE 0x00000000
#define SUNXI_SRAM_C_BASE 0x02000000
#define SUNXI_VE_BASE 0x41C0E000
#define SUNXI_GPIO_BASE 0x42000000
#define SUNXI_PWM_BASE 0x42000C00
#define SUNXI_CCU_APP_BASE 0x42001000
#define SUNXI_GPADC_BASE 0x42009000
#define SUNXI_THS_BASE 0x42009400
#define SUNXI_ADDA_BASE 0x42030000
#define SUNXI_I2S_BASE 0x42032000
#define SUNXI_TIMER_BASE 0x42050000
#define SUNXI_TRNG_BASE 0x42059000
#define SUNXI_UART0_BASE 0x42500000
#define SUNXI_UART1_BASE 0x42500400
#define SUNXI_UART2_BASE 0x42500800
#define SUNXI_UART3_BASE 0x42500C00
#define SUNXI_TWI0_BASE 0x42502000
#define SUNXI_TWI1_BASE 0x42502400
#define SUNXI_TWI2_BASE 0x42502800
#define SUNXI_SYSCTRL_BASE 0x43000000
#define SUNXI_DMAC1_BASE 0x43001000
#define SUNXI_DMAC0__SGDMA__BASE 0x43002000
#define SUNXI_SPINLOCK_BASE 0x43005000
#define SUNXI_SID_BASE 0x43006000
#define SUNXI_SID_SRAM_BASE (SUNXI_SID_BASE + 0x200)
#define SUNXI_HSTIMER_BASE 0x43008000
#define SUNXI_DCU_BASE 0x43010000
#define SUNXI_E907_CFG_BASE 0x43030000
#define SUNXI_E907_WDG_BASE 0x43031000
#define SUNXI_E907_TIMESTAMP_BASE 0x43032000
#define SUNXI_E907_MSGBOX_BASE 0x43033000
#define SUNXI_WLAN_CTRL_BASE 0x43043000
#define SUNXI_CE_BASE 0x43044000
#define SUNXI_PWR_REQ_BASE 0x43045000
#define SUNXI_MSI_MEMC_BASE 0x43102000
#define SUNXI_A27L2_CFG_BASE 0x49100000
#define SUNXI_A27L2_WDG_BASE 0x49101000
#define SUNXI_A27L2_MSGBOX_BASE 0x49102000
#define SUNXI_SMHC0_BASE 0x44020000
#define SUNXI_SMHC1_BASE 0x44021000
#define SUNXI_SPI0_BASE 0x44025000
#define SUNXI_SPI1_BASE 0x44026000
#define SUNXI_SPI2_BASE 0x44027000
#define SUNXI_USB0_BASE 0x44100000
#define SUNXI_GMAC_BASE 0x44500000
#define SUNXI_SPI_FLASH_BASE 0x44F00000
#define SUNXI_DE_BASE 0x45000000
#define SUNXI_G2D_BASE 0x45410000
#define SUNXI_DISPLAY_TOP_BASE 0x45460000
#define SUNXI_TCON_LCD0_BASE 0x45461000
#define SUNXI_CSI_BASE 0x45800000
#define SUNXI_ISP_BASE 0x45900000
#define SUNXI_PRCM_BASE 0x4A000000
#define SUNXI_RTC_TIMER_BASE 0x4A000400
#define SUNXI_PMU_RTC_BASE 0x4A000800
#define SUNXI_SYSRTC_BASE 0x4A000C00
#define SUNXI_RTC_WDG_BASE 0x4A001000
#define SUNXI_CCU_AON_BASE 0x4A010000
#define SUNXI_PMU_AON_BASE 0x4A011000
#define SUNXI_RCCAL_BASE 0x4A011400
#define SUNXI_WIFI_SRAM_BASE 0x68000000
#define SUNXI_WIFI_PERI_BASE 0x79C00000
#define SUNXI_SPI_FLASH_XIP_BASE 0x10000000
#define SUNXI_DRAM_SPACE_BASE 0x80000000
#define SUNXI_RISCV_CLINT_BASE 0x30000000
#define SUNXI_RISCV_CLIC_BASE 0x30800000
#define SUNXI_RESERVE_BASE 0x30805000
#define SUNXI_PLIC_BASE 0x48000000
#define SUNXI_PLMT_BASE 0x48400000
#define SUNXI_PLIC_SW_BASE 0x48800000
#define SUNXI_PLDM_BASE 0x48C00000
#define SUNXI_L2C_BASE 0x49000000

#define SUNXI_RTC_DATA_BASE (SUNXI_PRCM_BASE + 0x200)
#define SUNXI_RTC_BOOT_FLAG_ADDR (SUNXI_PRCM_BASE + 0x1c0)
#define SUNXI_WDOG_BASE (SUNXI_E907_WDG_BASE)
#define SUNXI_PIO_BASE (SUNXI_GPIO_BASE)
#define SUNXI_RPIO_BASE (0x42000540)
#define SUNXI_RTWI_BASE (SUNXI_TWI0_BASE)
#define SUNXI_SPIF_BASE (SUNXI_SPI_FLASH_BASE)
#define SUNXI_DMA_BASE (SUNXI_DMAC0__SGDMA__BASE)
#define SUNXI_RTC_BASE (SUNXI_PMU_RTC_BASE)

/* check power off*/
#define VCC33_DET_CTRL_REG (0x64)
#define VCCIO_THRESHOLD_MASK (0x7)
#define VCCIO_THRESHOLD_VOLTAGE_2_7 (0 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_2_6 (1 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_2_8 (2 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_2_9 (3 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_3_0 (4 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_3_1 (5 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_3_2 (6 << 8)
#define VCCIO_THRESHOLD_VOLTAGE_3_3 (7 << 8)

#define POR_RESET_CTRL_REG (0X24)
#define VCC33_DET_RSTN_ENABLE (1 << 4)

#endif// __SUN20IW5_REG_NCAT_H__