/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : flexio_qc01
**     Processor   : MK82FN256VLL15
**     Component   : MK82FN256LL15
**     Version     : Component 1.2.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0 MK82FN256xxx15
**     Datasheet   : K82P121M150SF5RM, Rev. 0, May 2015
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-04-16, 12:34, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**          Component name                                 : Cpu
**          CPU type                                       : MK82FN256VLL15
**          fsl_clock_manager                              : clockMan1
**          CPU                                            : CPU
**          MemModelDev                                    : MemModel_NoFlexMem
**          Allowed power modes                            : 
**            High speed run mode                          : Allowed
**            Very low power modes                         : Allowed
**            Low leakage stop mode                        : Allowed
**            Very low leakage stop mode                   : Allowed
**          Flash memory organization                      : 
**            Flash blocks                                 : 1
**              Flash block 0                              : PFlash
**                Address                                  : 0x0
**                Size                                     : 262144
**                Write unit size                          : 4
**                Erase unit size                          : 4096
**                Protection unit size                     : 8192
**          SDRAM chip select list                         : 1
**            Chip select 0                                : Disabled
**          External memory settings                       : 
**            CS0                                          : Disabled
**            CS1                                          : Disabled
**            CS2                                          : Disabled
**            CS3                                          : Disabled
**            CS4                                          : Disabled
**            CS5                                          : Disabled
**          QSPI serial flash memory settings              : 
**            QSPI0                                        : Disabled
**          Watchdog settings                              : 
**            Watchdog disable                             : yes
**          Pins/Signals                                   : 
**            Reset pin                                    : Enabled
**              Reset Pin                                  : RESET_b
**            Debug interface (JTAG)                       : 
**              JTAG Mode                                  : JTAG
**                TDI                                      : Enabled
**                  TDI Pin                                : ACCEL_SDA/JTAG_TDI/J2_18/J12_4
**                TDO                                      : Enabled
**                  TDO Pin                                : ACCEL_SCL/JTAG_TDO/J2_20/J12_3
**                TCK                                      : Enabled
**                  TCK Pin                                : SWD_CLK/JTAG_CLK
**                TMS                                      : Enabled
**                  TMS Pin                                : SWD_DIO/JTAG_TMS
**                nTRST                                    : Disabled
**     Contents    :
**         SystemInit            - void SystemInit(void);
**         SystemCoreClockUpdate - void SystemCoreClockUpdate(void);
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
** @file Cpu.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

#if !defined(__PE_LOW_LEVEL_INIT_H__)
#define __PE_LOW_LEVEL_INIT_H__

#include "Cpu.h"
#include "Events.h"

#endif /* __PE_LOW_LEVEL_INIT_H__ */