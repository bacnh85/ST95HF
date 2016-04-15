/**
  ******************************************************************************
  * @file    common.h 
  * @author  MMY Application Team
  * @version V0.8.2
  * @date    03/21/2013
  * @brief   This file provides all the headers of the common functions.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _COMMON_H
#define _COMMON_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"
#include "miscellaneous.h"
#include "stm32f30x_conf.h"

/* Exported types ------------------------------------------------------------*/
typedef  void (*pFunction)(void);


/* Exported constants --------------------------------------------------------*/


/* Constants used by Serial Command Line Mode */
#define CMD_STRING_SIZE       128

#define ApplicationAddress    0x8009000

#define STM32F10X_HD

#if defined (STM32F10X_MD) || defined (STM32F10X_MD_VL)
 #define PAGE_SIZE                         (0x400)    /* 1 Kbyte */
 #define FLASH_SIZE                        (0x20000)  /* 128 KBytes */
#elif defined STM32F10X_CL
 #define PAGE_SIZE                         (0x800)    /* 2 Kbytes */
 #define FLASH_SIZE                        (0x40000)  /* 256 KBytes */
#elif defined STM32F10X_HD || defined (STM32F10X_HD_VL)
 #define PAGE_SIZE                         (0x800)    /* 2 Kbytes */
 #define FLASH_SIZE                        (0x80000)  /* 512 KBytes */
#elif defined STM32F10X_XL
 #define PAGE_SIZE                         (0x800)    /* 2 Kbytes */
 #define FLASH_SIZE                        (0x100000) /* 1 MByte */
#else
 #error "Please select first the STM32 device to be used (in stm32f10x.h)"
#endif

/* Compute the FLASH upload image size */
#define FLASH_IMAGE_SIZE                   (uint32_t) (FLASH_SIZE - (ApplicationAddress - 0x08000000))

/* Enum for ST95 state */
typedef enum {UNDEFINED_MODE=0,PICC,PCD}DeviceMode_t;
typedef enum {UNDEFINED_TAG_TYPE=0,TT1,TT2,TT3,TT4A,TT4B,TT5}TagType_t;

/* TT1 */
#define NFCT1_MAX_TAGMEMORY																(120+2)

/* TT2 */
#define NFCT2_MAX_TAGMEMORY																512//2048 (must be a multiple of 8)
#define NFCT2_MAX_CC_SIZE																	4	
#define NFCT2_MAX_CONFIG																	12	
#define NFCT2_MAX_NDEFFILE																(NFCT2_MAX_TAGMEMORY-NFCT2_MAX_CC_SIZE-NFCT2_MAX_CONFIG)

/* TT3 */
#define NFCT3_ATTRIB_INFO_SIZE 														16
#define NFCT3_MAX_NDEFFILE																2048
#define NFCT3_MAX_TAGMEMORY 															(NFCT3_MAX_NDEFFILE+NFCT3_ATTRIB_INFO_SIZE)
#define NFCT3_NB_BLOC_MSB																	((NFCT3_MAX_TAGMEMORY/16)>>8)
#define NFCT3_NB_BLOC_LSB																	((NFCT3_MAX_TAGMEMORY/16)&0x00FF)

/* TT4 */
#define NFCT4_MAX_CCMEMORY																16
#define NFCT4A_MAX_NDEFMEMORY															8192
#define NFCT4B_MAX_NDEFMEMORY															8192
#define NFCT4_MAX_NDEFMEMORY															NFCT4A_MAX_NDEFMEMORY

/* TT5 */
#define NFCT5_MAX_TAGMEMORY																8192

#define NFC_DEVICE_MAX_NDEFMEMORY													NFCT4_MAX_NDEFMEMORY
/* Exported macro ------------------------------------------------------------*/
/* Common routines */
/* Exported functions ------------------------------------------------------- */

int32_t Transfert_FW (void);
uint32_t file_CRC(const char * fileName);
uint32_t Flash_CRC(uint32_t FwSize);
uint32_t FLASH_PagesMask(__IO uint32_t Size);
void Update(void);
uint8_t CheckFileCRC(void);
uint8_t CheckFlashCRC(void);
uint8_t RemoveFiles(void);
uint8_t CheckFiles(void);
uint16_t random(uint16_t min, uint16_t max);
#endif  /* _COMMON_H */

/*******************(C)COPYRIGHT 2010 STMicroelectronics *****END OF FILE******/
