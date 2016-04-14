/**
  ******************************************************************************
  * @file    lib_nfctype5pcd.h 
  * @author  MMY Application Team
  * @version V4.0.0
  * @date    02/06/2014
  * @brief   Generates the NFC type5 commands
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
#ifndef _LIB_NFCTYPE5PCD_H
#define _LIB_NFCTYPE5PCD_H

#include "lib_PCD.h"
#include "lib_iso15693pcd.h"

/* Error codes */
#define PCDNFCT5_OK 											PCDNFC_OK
#define PCDNFCT5_ERROR 										PCDNFC_ERROR
#define PCDNFCT5_ERROR_MEMORY_TAG					PCDNFC_ERROR_MEMORY_TAG
#define PCDNFCT5_ERROR_MEMORY_INTERNAL		PCDNFC_ERROR_MEMORY_INTERNAL
#define PCDNFCT5_ERROR_LOCKED 						PCDNFC_ERROR_LOCKED
#define PCDNFCT5_ERROR_NOT_FORMATED				PCDNFC_ERROR_NOT_FORMATED

/* Functions */
uint8_t PCDNFCT5_ReadNDEF( void );
uint8_t PCDNFCT5_WriteNDEF( void );

#endif
