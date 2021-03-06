/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : flexibleIO1.c
**     Project     : flexio_qc01
**     Processor   : MK82FN256VLL15
**     Component   : fsl_flexio
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0 MK82FN256xxx15
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-04-19, 20:42, # CodeGen: 15
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file flexibleIO1.c
** @version 01.00
*/         
/*!
**  @addtogroup flexibleIO1_module flexibleIO1 module documentation
**  @{
*/         

/* flexibleIO1. */

#include "Events.h"
#include "flexibleIO1.h"

const flexio_uart_userconfig_t flexibleIO1_uartConfig0 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 0U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 0U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 0U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig1 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 1U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 1U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 1U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig2 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 2U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 2U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 2U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig3 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 3U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 3U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 3U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig4 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 4U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 4U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 4U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig5 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 5U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 5U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 5U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig6 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart8BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 6U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 6U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 6U,
};

const flexio_uart_userconfig_t flexibleIO1_uartConfig7 = {
  .baudRate = 115200U,
  .bitCounter = kFlexIOUart5BitsPerChar,
  .uartMode = flexioUART_RxOnly,
  .txConfig.pinIdx = 0U,
  .rxConfig.pinIdx = 7U,
  .txConfig.shifterIdx = 0U,
  .rxConfig.shifterIdx = 7U,
  .txConfig.timerIdx = 0U,
  .rxConfig.timerIdx = 7U,
};

const flexio_user_config_t flexibleIO1_initConfig0 = {
  .useInt = false,
  .onDozeEnable = false,
  .onDebugEnable = false,
  .fastAccessEnable = false,
};



/* END flexibleIO1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
