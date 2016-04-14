/**
  @page mdkarm MDK-ARM Project Template for STM32F30xx devices
  
  @verbatim
  ******************* (C) COPYRIGHT 2015 STMicroelectronics ********************
  * @file    readme.txt
  * @author  MCD Application Team
  * @version V1.2.2
  * @date    14-August-2015
  * @brief   This sub-directory contains all the user-modifiable files 
  *          needed to create a new project linked with the STM32F30x  
  *          Standard Peripheral Library and working with RealView Microcontroller
  *          Development Kit(MDK-ARM) software toolchain
  ******************************************************************************
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
  @endverbatim
 
 @par Directory contents
 
 - Project.uvprojx/.uvoptx: A pre-configured project file with the provided library structure
                          that produces an executable image with MDK-ARM.

Enabling "Options for Target — Output – Browser Information" is useful for quick 
source files navigation but may slow the compilation time.
 
 
 @par How to use it ?
 
 - Open the Project.uvproj project
 - In the build toolbar select the project config:
      - STM32F303xC: to configure the project for STM32F303xC devices.
                     You can use STMicroelectronics STM32303C-EVAL board to run this project.
                     
      - STM32F303xE: to configure the project for STM32F303xE devices.
                     You need to use custom HW board to run this project. 
                     
      - STM32F302x8: to configure the project for STM32F302x8 devices.
                     You can use STMicroelectronics Nucleo to run this project.
                     
      - STM32F334x8: to configure the project for STM32F334x8 devices.
                     You can use STMicroelectronics Discovery to run this project.
                     
 - Rebuild all files: Project->Rebuild all target files
 - Load project image: Debug->Start/Stop Debug Session
 - Run program: Debug->Run (F5) 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */