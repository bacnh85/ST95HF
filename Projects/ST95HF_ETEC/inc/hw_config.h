/**
  ******************************************************************************
  * @file    hw_config.h
  * @author  MMY Application Team
  * @version V1.0.0
  * @date    december-2012
  * @brief   Hardware Configuration & Setup
  ******************************************************************************
  * @copyright
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  */ 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_it.h" 
#include "miscellaneous.h"

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
#define BULK_MAX_PACKET_SIZE  0x00000040

/* Regarding board antenna (and matching) appropriate value may be modified to optimized RF performances */
/*
 Analogue configuration register
 ARConfigB	bits 7:4	MOD_INDEX	Modulation index to modulator
								 3:0	RX_AMP_GAIN	Defines receiver amplifier gain

 For type A you can also adjust the Timer Window
*/

/******************  PCD  ******************/
/* ISO14443A */
#define PCD_TYPEA_ARConfigA	0x01
#define PCD_TYPEA_ARConfigB	0xDF

#define PCD_TYPEA_TIMERW    0x5A

/* ISO14443B */
#define PCD_TYPEB_ARConfigA	0x01
#define PCD_TYPEB_ARConfigB	0x51

/* Felica */
#define PCD_TYPEF_ARConfigA	0x01
#define PCD_TYPEF_ARConfigB	0x51

/* ISO15693 */
#define PCD_TYPEV_ARConfigA	0x01
#define PCD_TYPEV_ARConfigB	0xD1

/******************  PICC  ******************/
/* ISO14443A */
#define PICC_TYPEA_ACConfigA 0x27  /* backscaterring */


/* Exported constants --------------------------------------------------------*/

/** 
 * @brief  Communication Interface pin B1; Fake as there is no Interface pin
 */
#define INTERFACE_PIN             						GPIO_Pin_1                  
#define INTERFACE_GPIO_PORT       						GPIOB                   
#define INTERFACE_GPIO_CLK        						RCC_APB2Periph_GPIOB


/* -------------------------------------------------------------------------- 
* Delay TIMER configuration (ms)
* -------------------------------------------------------------------------- */ 
#define TIMER_DELAY												TIM2
#define TIMER_DELAY_PERIOD										71
#define TIMER_DELAY_PRESCALER									1000
#define TIMER_DELAY_CLOCK										RCC_APB1Periph_TIM2
																						
/* -------------------------------------------------------------------------- 
* Delay TIMER configuration (µs)
* --------------------------------------------------------------------------- */ 
#define TIMER_US_DELAY											TIM2
#define TIMER_US_DELAY_PERIOD									35
#define TIMER_US_DELAY_PRESCALER								1
#define TIMER_US_DELAY_CLOCK									RCC_APB1Periph_TIM2

/** 
 * @brief  NVIC definitions 
 */
#define NVIC_PRIORITY_GROUP										NVIC_PriorityGroup_2

#define USB_HP_PREEMPTION_PRIORITY								2
#define USB_HP_SUB_PRIORITY												1
#define USB_HP_IRQ_CHANNEL												USB_HP_CAN1_TX_IRQn

#define USB_LP_PREEMPTION_PRIORITY								2
#define USB_LP_SUB_PRIORITY												2
#define USB_LP_IRQ_CHANNEL												USB_LP_CAN1_RX0_IRQn

#define TIMER_DELAY_PREEMPTION_PRIORITY				1
#define TIMER_DELAY_SUB_PRIORITY							3
#define TIMER_DELAY_IRQ_CHANNEL								TIM2_IRQn

#define TIMER_DELAY_PREEMPTION_HIGHPRIORITY		0
#define TIMER_DELAY_SUB_HIGHPRIORITY					0


/** 
 * @brief  IRQ functions names 
 */
#define USB_HP_IRQ_HANDLER										USB_HP_CAN1_TX_IRQHandler
#define USB_LP_IRQ_HANDLER										USB_LP_CAN1_RX0_IRQHandler
#define TIMER_STANDALONE_IRQ_HANDLER 							TIM4_IRQHandler
#define TIMER_DELAY_IRQ_HANDLER									TIM2_IRQHandler


/* Exported functions ------------------------------------------------------- */
void Set_System										( void );
void Interrupts_Config						( void );
void Set_USBClock									( void );
void Enter_LowPowerMode						( void );
void Leave_LowPowerMode						( void );
void USB_Cable_Config 						(FunctionalState NewState);
void USB_Disconnect_Config				( void );
#ifdef USE_MSD_DRIVE
void Get_SerialNum								( void );
void MAL_Config										( void );
void USB_RebootMSD								( void );
#endif

void Timer_Config									( void );
void Timer_RCC_Config							( void );
void Timer_Structure_Config				( void );
void delay_ms											( uint16_t delay );
void delay_us											( uint16_t delay );
void delayHighPriority_ms					( uint16_t delay );
void decrement_delay							( void );



#endif  /*__HW_CONFIG_H*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
