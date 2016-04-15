/**
  ******************************************************************************
  * @file    stm32f10x_it.c 
  * @author  MMY Application Team
  * @version V0.8.2
  * @date    03/21/2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
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
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "menu.h"
#include "usb_istr.h"
#include "usb_int.h"

/** @addtogroup User_Appli
  * @{
  * @brief      <b>This folder contains the application files</b> 
  */
	
/** @addtogroup Stm32f10x_it
 * 	@{
 *  @brief      This file wrap function to IRQ handler (MCU specific)
 */

 /**
 *	@brief  this uDataReady variable is set when the RF transceiver sends an interruption on the IRQout pad
 */
volatile bool uDataReady 							= false;
volatile bool RF_DataExpected 					= false;
volatile bool RF_DataReady 						= false;
volatile bool screenRotated 						= false;
volatile bool disableRotate						= false;

volatile bool DisableExitButtonAction  = false;
volatile bool exitOnRotate = false;

volatile uint32_t nb_ms_elapsed = 0;

extern __IO uint32_t 					SELStatus;
extern bool 									KEYPress;
extern uint8_t 								KEYPressed;
extern bool 									lockKEYUpDown;
extern bool 									refreshMenu;
extern bool										reversed;



/** @addtogroup Stm32f10x_it_Private_Functions
 * 	@{
 *  @brief	No Private Function
 */

/**
  * @}
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/** @addtogroup Stm32f10x_it_Public_Functions
 * 	@{
 */

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	nb_ms_elapsed++;
}



/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/******************************************************************************/

/** @addtogroup Peripherals Interrupt Handlers
 *  @{
 */

/**
  * @brief  This function handles External lines 5 to 9 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5) != RESET)
  { 
    /* Clear the EXTI Line 5 (left)*/
    EXTI_ClearITPendingBit(EXTI_Line5);
		
		KEYPress = true;
		KEYPressed = LEFT;
  }
	
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
  {
		/* Update SelStatus global variable */
    SELStatus = 1;
    /* Clear the EXTI Line 6 */  
    EXTI_ClearITPendingBit(EXTI_Line6);
		
		KEYPress = true;
		KEYPressed = SEL;
  }
	
	if(EXTI_GetITStatus(EXTI_Line7) != RESET)
  {
		if (!lockKEYUpDown)
		{
			if (screenRotated)
				UpFunc();
			else
				DownFunc();  
		}
    /* Clear the EXTI Line 7 */
    EXTI_ClearITPendingBit(EXTI_Line7);
		
		KEYPress = true;
		if (screenRotated)
			KEYPressed = UP;
		else
			KEYPressed = DOWN;
		
  }
	
	if(EXTI_GetITStatus(EXTI_Line8) != RESET)
  { 
    /* Clear the EXTI Line 8 (right) */
    EXTI_ClearITPendingBit(EXTI_Line8);
		
		KEYPress = true;
		KEYPressed = RIGHT;
  }
	
  if(EXTI_GetITStatus(EXTI_Line9) != RESET)
  {
		if (!lockKEYUpDown)
		{
			if (screenRotated)
				DownFunc(); 
			else
				UpFunc();
		}
    /* Clear the EXTI Line 9 */  
    EXTI_ClearITPendingBit(EXTI_Line9);
		
		KEYPress = true;
		if (screenRotated)
			KEYPressed = DOWN;
		else
			KEYPressed = UP;
  }
	
	if( !DisableExitButtonAction)
		ConfigManager_Stop();
 
}

/**
  * @brief  This function handles External line 4 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI4_IRQHandler(void)
{
	if (!disableRotate)
	{
		screenRotated= !screenRotated;
		LCD_Rotate();
		refreshMenu = true;
	}
	KEYPressed=ROTATE;
	EXTI_ClearITPendingBit(EXTI_Line4);
	
	if( !DisableExitButtonAction)
		ConfigManager_Stop();
	
	if( exitOnRotate)
		ConfigManager_Stop();
}
 
/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
 *	@brief  This function handles the RF transceiver interupts
 *	@brief  RFTRANS_IRQ_HANDLER							EXTI3_IRQHandlers
 */

void RFTRANS_95HF_IRQ_HANDLER ( void )
{
	if(EXTI_GetITStatus(EXTI_RFTRANS_95HF_LINE) != RESET)
	{
		/* Clear IT flag */
		EXTI_ClearITPendingBit(EXTI_RFTRANS_95HF_LINE);
		/* Disable EXTI Line9 IRQ */
		EXTI->IMR &= ~EXTI_RFTRANS_95HF_LINE;
		
		if(RF_DataExpected)
			RF_DataReady = true;
		
		/* Answer to command ready*/
		uDataReady = true;		
	}
	
}

/**
 * @brief  This function handles the timer interrupt.
 * @param  None
 * @retval None
 */
void TIMER_DELAY_IRQ_HANDLER(void)
{
	/* Clear TIMER update interrupt flag */
	TIM_ClearITPendingBit(TIMER_DELAY, TIM_IT_Update);
	decrement_delay();
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
