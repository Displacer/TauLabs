/**
 ******************************************************************************
 * @addtogroup TauLabsTargets Tau Labs Targets
 * @{
 * @addtogroup FlyingF3 FlyingF3 support files
 * @{
 *
 * @file       STM32F4xx_DiscoveryF4 
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2013
 * @brief      Board header file for DiscoveryF4
 * @see        The GNU Public License (GPL) Version 3
 * 
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


#ifndef STM32F4XX_DISCOVERYF4_H_
#define STM32F4XX_DISCOVERYF4_H_

#include <stdbool.h>

//------------------------
// Timers and Channels Used
//------------------------
/*
Timer | Channel 1 | Channel 2 | Channel 3 | Channel 4
------+-----------+-----------+-----------+----------
TIM1  |           |           |           |
TIM2  | --------------- PIOS_DELAY -----------------
TIM3  |           |           |           |
TIM4  |           |           |           |
TIM5  |           |           |           |
TIM6  |           |           |           |
TIM7  |           |           |           |
TIM8  |           |           |           |
------+-----------+-----------+-----------+----------
*/

//------------------------
// DMA Channels Used
//------------------------
/* Channel 1  -                                 */
/* Channel 2  - SPI1 RX                         */
/* Channel 3  - SPI1 TX                         */
/* Channel 4  - SPI2 RX                         */
/* Channel 5  - SPI2 TX                         */
/* Channel 6  -                                 */
/* Channel 7  -                                 */
/* Channel 8  -                                 */
/* Channel 9  -                                 */
/* Channel 10 -                                 */
/* Channel 11 -                                 */
/* Channel 12 -                                 */

//------------------------
// BOOTLOADER_SETTINGS
//------------------------
#define BOARD_READABLE	true
#define BOARD_WRITABLE	true
#define MAX_DEL_RETRYS	3


//------------------------
// PIOS_LED
//------------------------
#define PIOS_LED_GREEN		0
#define PIOS_LED_ORANGE		1
#define PIOS_LED_RED		2
#define PIOS_LED_BLUE		3

#define PIOS_LED_HEARTBEAT	PIOS_LED_BLUE
#define PIOS_LED_ALARM		PIOS_LED_RED
#define PIOS_LED_USB		PIOS_LED_GREEN

#define USB_LED_ON			PIOS_LED_On(PIOS_LED_USB)
#define USB_LED_OFF			PIOS_LED_Off(PIOS_LED_USB)
#define USB_LED_TOGGLE		PIOS_LED_Toggle(PIOS_LED_USB)


//------------------------
// PIOS_WDG
//------------------------
#define PIOS_WATCHDOG_TIMEOUT    250 /* (ms) */
#define PIOS_WDG_REGISTER        RTC_BKP_DR4

//------------------------
// PIOS_I2C
// See also pios_board.c
//------------------------
#define PIOS_I2C_MAX_DEVS			1
extern uint32_t pios_i2c_gyro_accel_adapter_id;
#define PIOS_I2C_MPU6050_ADAPTER		(pios_i2c_gyro_accel_adapter_id)

//-------------------------
// PIOS_COM
//
// See also pios_board.c
//-------------------------
extern uintptr_t pios_com_telem_rf_id;
#define PIOS_COM_TELEM_RF               (pios_com_telem_rf_id)

#if defined(PIOS_INCLUDE_DEBUG_CONSOLE)
extern uintptr_t pios_com_debug_id;
#define PIOS_COM_DEBUG                  (pios_com_debug_id)
#endif	/* PIOS_INCLUDE_DEBUG_CONSOLE */

extern uintptr_t pios_com_vcp_id;
#define PIOS_COM_VCP			(pios_com_vcp_id)

extern uintptr_t pios_com_telem_usb_id;
#define PIOS_COM_TELEM_USB              (pios_com_telem_usb_id)

//------------------------
// TELEMETRY
//------------------------
#define TELEM_QUEUE_SIZE         20
#define PIOS_TELEM_STACK_SIZE    624
		

#define PIOS_SYSCLK 168000000
//	Peripherals that belongs to APB1 are:
//	DAC			|PWR				|CAN1,2
//	I2C1,2,3	|UART4,5			|USART3,2
//	I2S3Ext		|SPI3/I2S3			|SPI2/I2S2
//	I2S2Ext		|IWDG				|WWDG
//	RTC/BKP reg	
// TIM2,3,4,5,6,7,12,13,14

// Calculated as SYSCLK / APBPresc * (APBPre == 1 ? 1 : 2)   
// Default APB1 Prescaler = 4 
#define PIOS_PERIPHERAL_APB1_CLOCK					(PIOS_SYSCLK / 2)

//	Peripherals belonging to APB2
//	SDIO			|EXTI				|SYSCFG			|SPI1
//	ADC1,2,3				
//	USART1,6
//	TIM1,8,9,10,11
//
// Default APB2 Prescaler = 2
//
#define PIOS_PERIPHERAL_APB2_CLOCK					PIOS_SYSCLK


//-------------------------
// Interrupt Priorities
//-------------------------
#define PIOS_IRQ_PRIO_LOW                       12              // lower than RTOS
#define PIOS_IRQ_PRIO_MID                       8               // higher than RTOS
#define PIOS_IRQ_PRIO_HIGH                      5               // for SPI, ADC, I2C etc...
#define PIOS_IRQ_PRIO_HIGHEST                   4               // for USART etc...


//------------------------
// PIOS_RCVR
// See also pios_board.c
//------------------------
#define PIOS_RCVR_MAX_CHANNELS       12
#define PIOS_GCSRCVR_TIMEOUT_MS     100

//--------------------------
// Timer controller settings
//--------------------------
#define PIOS_TIM_MAX_DEVS			6

//-------------------------
// ADC
//-------------------------
#define PIOS_ADC_SUB_DRIVER_MAX_INSTANCES       3

//-------------------------
// USB
//-------------------------
#define PIOS_USB_ENABLED                        1 /* Should remove all references to this */

#endif /* STM32F4XX_DISCOVERYF4_H_ */


/**
 * @}
 * @}
 */
