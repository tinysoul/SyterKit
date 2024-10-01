/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __SUN20IW1_REG_NCAT_H__
#define __SUN20IW1_REG_NCAT_H__

/*CPUX*/
#define SUNXI_CPUXCFG_BASE (0x08100000)

/*sys ctrl*/
#define SUNXI_TIMER_BASE (0x02050000)
#define SUNXI_CCM_BASE (0x02001000)
#define SUNXI_PIO_BASE (0x02000000)
#define SUNXI_SPC_BASE (0x02000800)
#define SUNXI_SYSCRL_BASE (0x03000000)
#define SUNXI_DMA_BASE (0x03002000)
#define SUNXI_SID_BASE (0x03006000)
#define SUNXI_SID_SRAM_BASE (0x03006200)

#define SUNXI_WDOG_BASE (0x020500A0)

#define SUNXI_CE_BASE (0x03040000)
#define SUNXI_SS_BASE SUNXI_CE_BASE

#define SUNXI_SMC_BASE (0x03007000)

/*storage*/
#define SUNXI_SMHC0_BASE (0x04020000)
#define SUNXI_SMHC1_BASE (0x04021000)
#define SUNXI_SMHC2_BASE (0x04022000)

/*noraml*/
#define SUNXI_UART0_BASE (0x02500000)
#define SUNXI_UART1_BASE (0x02500400)
#define SUNXI_UART2_BASE (0x02500800)
#define SUNXI_UART3_BASE (0x02500C00)

#define SUNXI_TWI0_BASE (0x02502000)
#define SUNXI_TWI1_BASE (0x02502400)

#define SUNXI_SPI0_BASE (0x04025000)
#define SUNXI_SPI1_BASE (0x04026000)
#define SUNXI_SPIF_BASE (0x04f00000)

/*physical key*/
#define SUNXI_GPADC_BASE (0x02009000)
#define SUNXI_LRADC_BASE (0x02009800)
#define SUNXI_KEYADC_BASE SUNXI_LRADC_BASE

/*cpus*/
#define SUNXI_RTC_BASE (0x07090000)
#define SUNXI_AUDIO_CODEC (0x02030000)
#define SUNXI_CPUS_CFG_BASE (0x07000400)
#define SUNXI_RCPUCFG_BASE (SUNXI_CPUS_CFG_BASE)
#define SUNXI_RPRCM_BASE (0x07010000)
#define SUNXI_RPWM_BASE (0x07020c00)
#define SUNXI_RPIO_BASE (0x07022000)
#define SUNXI_R_PIO_BASE SUNXI_RPIO_BASE
#define SUNXI_RTWI_BASE (0x07020800)
#define SUNXI_RRSB_BASE (0x07083000)
#define SUNXI_RSB_BASE SUNXI_RRSB_BASE
#define SUNXI_RTWI_BRG_REG (SUNXI_RPRCM_BASE + 0x019c)
#define SUNXI_RTWI0_RST_BIT (16)
#define SUNXI_RTWI0_GATING_BIT (0)
#define SUNXI_RST_BIT (16)
#define SUNXI_GATING_BIT (0)

#define SUNXI_RTC_DATA_BASE (SUNXI_RTC_BASE + 0x100)
#define AUDIO_CODEC_BIAS_REG (SUNXI_AUDIO_CODEC + 0x320)
#define AUDIO_POWER_REG (SUNXI_AUDIO_CODEC + 0x348)
#define SUNXI_VER_REG (SUNXI_SYSCRL_BASE + 0x24)

#define RES_CAL_CTRL_REG (SUNXI_RPRCM_BASE + 0X310)
#define ANA_PWR_RST_REG (SUNXI_RPRCM_BASE + 0X254)

#define VDD_ADDA_OFF_GATING (9)
#define CAL_ANA_EN (1)
#define CAL_EN (0)

#define RVBARADDR0_L (SUNXI_CPUXCFG_BASE + 0x40)
#define RVBARADDR0_H (SUNXI_CPUXCFG_BASE + 0x44)

#define SRAM_CONTRL_REG0 (SUNXI_SYSCRL_BASE + 0x0)
#define SRAM_CONTRL_REG1 (SUNXI_SYSCRL_BASE + 0x4)

/* rtc check power off */
#define FORCE_DETECTER_OUTPUT (1 << 7)
#define VCCIO_THRESHOLD_VOLTAGE_2_5 (0 << 4)
#define VCCIO_THRESHOLD_VOLTAGE_2_6 (1 << 4)
#define VCCIO_THRESHOLD_VOLTAGE_2_7 (2 << 4)
#define VCCIO_THRESHOLD_VOLTAGE_2_8 (3 << 4)
#define VCCIO_THRESHOLD_VOLTAGE_2_9 (4 << 4)
#define VCCIO_THRESHOLD_VOLTAGE_3_0 (5 << 4)
#define VCCIO_DET_BYPASS_EN (1 << 0)

#endif// __SUN20IW1_REG_NCAT_H__