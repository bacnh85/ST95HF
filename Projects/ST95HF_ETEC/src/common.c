/**
  ******************************************************************************
  * @file    common.c 
  * @author  MMY Application Team
  * @version V0.8.2
  * @date    03/21/2013
  * @brief   This file provides all the common functions.
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

/* Includes ------------------------------------------------------------------*/
#include "common.h"

/** @addtogroup User_Appli
  * @{
 *  @brief      <b>This folder contains the application files</b> 
  */

/** @addtogroup Common
 * 	@{
 * @brief      This file contain function link to STM32 memory management  
 */


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
pFunction Jump_To_Application;
uint32_t JumpAddress;
uint32_t BlockNbr = 0, UserMemoryMask = 0;
uint32_t FwSize=0;
__IO uint32_t FlashProtection = 0;

extern uint32_t FlashDestination;
extern uint32_t 			CRCFile;


/* Private function prototypes -----------------------------------------------*/
static void FLASH_DisableWriteProtectionPages(void);

/** @addtogroup common_Private_Functions
 * 	@{
  */

/**
  * @brief  Disable the write protection of desired pages
  * @param  None
  * @retval None
  */
static void FLASH_DisableWriteProtectionPages(void)
{
#if 0
  uint32_t useroptionbyte = 0, WRPR = 0;
  uint16_t var1 = OB_IWDG_SW, var2 = OB_STOP_NoRST, var3 = OB_STDBY_NoRST;
  FLASH_Status status = FLASH_BUSY;

  WRPR = FLASH_GetWriteProtectionOptionByte();

  /* Test if user memory is write protected */
  if ((WRPR & UserMemoryMask) != UserMemoryMask)
  {
    useroptionbyte = FLASH_GetUserOptionByte();

    UserMemoryMask |= WRPR;

    status = FLASH_EraseOptionBytes();

    if (UserMemoryMask != 0xFFFFFFFF)
    {
      status = FLASH_EnableWriteProtection((uint32_t)~UserMemoryMask);
    }

    /* Test if user Option Bytes are programmed */
    if ((useroptionbyte & 0x07) != 0x07)
    { 
      /* Restore user Option Bytes */
      if ((useroptionbyte & 0x01) == 0x0)
      {
        var1 = OB_IWDG_HW;
      }
      if ((useroptionbyte & 0x02) == 0x0)
      {
        var2 = OB_STOP_RST;
      }
      if ((useroptionbyte & 0x04) == 0x0)
      {
        var3 = OB_STDBY_RST;
      }

      FLASH_UserOptionByteConfig(var1, var2, var3);
    }

    if (status == FLASH_COMPLETE)
    {
      /* SerialPutString("Write Protection disabled...\r\n"); */

      /* SerialPutString("...and a System Reset will be generated to re-load the new option bytes\r\n"); */

      /* Generate System Reset to load the new option byte values */
      NVIC_SystemReset();
    }
    else
    {
      /* SerialPutString("Error: Flash write unprotection failed...\r\n"); */
    }
  }
  else
  {
    /* SerialPutString("Flash memory not write protected\r\n"); */
  }
#endif
}

/**
  * @}
  */


/** @addtogroup common_Public_Functions
 * 	@{
 */

/**
  * @brief  Calculate the number of pages
  * @param  Size : The image size
  * @retval The number of pages
  */
uint32_t FLASH_PagesMask(__IO uint32_t Size)
{
#if 0
  uint32_t pagenumber = 0x0;
  uint32_t size = Size;

  if ((size % PAGE_SIZE) != 0)
  {
    pagenumber = (size / PAGE_SIZE) + 1;
  }
  else
  {
    pagenumber = size / PAGE_SIZE;
  }
  return pagenumber;
#endif
	
	return 0;
}

/**
  * @brief  Prepare the flash memory for update and launch it
  * @param  None
  * @retval None
  */
void Update(void)
{
#if 0
  /* Get the number of block (4 or 2 pages) from where the user program will be loaded */
  BlockNbr = (FlashDestination - 0x08000000) >> 12;

  /* Compute the mask to test if the Flash memory, where the user program will be */
  /* loaded, is write protected */
#if defined (STM32F10X_MD) || defined (STM32F10X_MD_VL)
  UserMemoryMask = ((uint32_t)~((1 << BlockNbr) - 1));
#else
  if (BlockNbr < 62)
  {
    UserMemoryMask = ((uint32_t)~((1 << BlockNbr) - 1));
  }
  else
  {
    UserMemoryMask = ((uint32_t)0x80000000);
  }
#endif /* (STM32F10X_MD) || (STM32F10X_MD_VL) */


  /* Test if any page of Flash memory where program user will be loaded is write protected */
  if ((FLASH_GetWriteProtectionOptionByte() & UserMemoryMask) != UserMemoryMask)
  {
    FlashProtection = 1;
  }
  else
  {
    FlashProtection = 0;
  }
   
  if(FlashProtection != 0)
  {
		/* Disable the write protection ------------------------- */
		FLASH_DisableWriteProtectionPages();
  }
         
  FwSize=Transfert_FW();
#endif
}

/**
  * @brief  Check that new firmeware was well programmed in flash
  * @param  None
  * @retval Flash programming succes or not
  */
uint8_t CheckFlashCRC(void){
#if 0
	uint32_t crcCalc=0,crcFile=0;
	
	crcCalc=Flash_CRC(FwSize/4);

	crcFile=CRCFile;
	
	if((crcFile !=0) &&  (crcCalc !=0) && (crcFile==crcCalc)){
			return 0;
	}
	
	return 1;
#endif
	
	return 0;
}

uint16_t random(uint16_t min, uint16_t max)
{
	return (((SysTick->VAL)%(max - min + 1)) + min);
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

/*******************(C)COPYRIGHT 2010 STMicroelectronics *****END OF FILE******/
