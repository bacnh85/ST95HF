/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.2.2
  * @date    14-August-2015
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "common.h"
#include "lib_Configmanager.h"

/* Private variables ---------------------------------------------------------*/

static __IO uint32_t TimingDelay = 0;

/* PCD/PICC global memory space */

/* TT1 (PCD only)*/
uint8_t TT1Tag[NFCT1_MAX_TAGMEMORY];

/* TT2 */
uint8_t TT2Tag[NFCT2_MAX_TAGMEMORY];

/* TT3 */
uint8_t TT3Tag[NFCT3_MAX_TAGMEMORY];
uint8_t *TT3AttribInfo = TT3Tag, *TT3NDEFfile = &TT3Tag[NFCT3_ATTRIB_INFO_SIZE];

/* TT4 */
uint8_t CardCCfile [NFCT4_MAX_CCMEMORY];
uint8_t CardNDEFfileT4A [NFCT4_MAX_NDEFMEMORY];
uint8_t CardNDEFfileT4B [NFCT4_MAX_NDEFMEMORY];

/* TT5 (PCD only)*/
uint8_t TT5Tag[NFCT5_MAX_TAGMEMORY];

__IO uint32_t SELStatus = 0;


/**
 * @function: Power up RFID module
 */

void RFID_PowerUp(void){
GPIO_InitTypeDef GPIO_InitStructure;

	// Enable RCC
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);

	// Init PD11 as output
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	// Power up
	GPIO_SetBits(GPIOD, GPIO_Pin_11);
}

/* Example to read tag */
void System_Init(void){

	/* Power up RFID board */
	//RFID_PowerUp();

	/* -- Configures Main system clocks & power */
	Set_System();

	/* Enable CRC periph used by application to compute CRC after download */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);

/*------------------- Resources Initialization -----------------------------*/

	/* configure the interuptions  */
	Interrupts_Config();

	/* configure the timers  */
	Timer_Config( );

	/* Configure systick in order to generate one tick every ms */
	/* also used to generate pseudo random numbers (SysTick->VAL) */
	SysTick_Config(SystemCoreClock / 1000);

	/* ST95HF HW Init */
	ConfigManager_HWInit();
}
  

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	/* Init RDIF */
	System_Init();

	/* Infinite loop */
	while (1)
	{
	}
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
