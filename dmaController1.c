/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : dmaController1.c
**     Project     : flexio_qc01
**     Processor   : MK82FN256VLL15
**     Component   : fsl_edma
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0 MK82FN256xxx15
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-04-16, 13:57, # CodeGen: 6
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
** @file dmaController1.c
** @version 01.00
*/         
/*!
**  @addtogroup dmaController1_module dmaController1 module documentation
**  @{
*/         

/* dmaController1. */

#include "dmaController1.h"

edma_state_t dmaController1_State;
  
const edma_user_config_t dmaController1_InitConfig0 = {
  .chnArbitration = kEDMAChnArbitrationFixedPriority,
  .groupArbitration = kEDMAGroupArbitrationFixedPriority,
  .groupPriority = kEDMAGroup0PriorityLowGroup1PriorityHigh,
  .notHaltOnError = false,
};


/*! @brief Dma channel 0 ISR */
void DMA0_DMA16_IRQHandler(void){
   EDMA_DRV_IRQHandler(0U);
}
/*! @brief Dma channel 1 ISR */
void DMA1_DMA17_IRQHandler(void){
   EDMA_DRV_IRQHandler(1U);
}
/*! @brief Dma channel 2 ISR */
void DMA2_DMA18_IRQHandler(void){
   EDMA_DRV_IRQHandler(2U);
}
/*! @brief Dma channel 3 ISR */
void DMA3_DMA19_IRQHandler(void){
   EDMA_DRV_IRQHandler(3U);
}
/*! @brief Dma channel 4 ISR */
void DMA4_DMA20_IRQHandler(void){
   EDMA_DRV_IRQHandler(4U);
}
/*! @brief Dma channel 5 ISR */
void DMA5_DMA21_IRQHandler(void){
   EDMA_DRV_IRQHandler(5U);
}
/*! @brief Dma channel 6 ISR */
void DMA6_DMA22_IRQHandler(void){
   EDMA_DRV_IRQHandler(6U);
}
/*! @brief Dma channel 7 ISR */
void DMA7_DMA23_IRQHandler(void){
   EDMA_DRV_IRQHandler(7U);
}
/*! @brief Dma channel 8 ISR */
void DMA8_DMA24_IRQHandler(void){
   EDMA_DRV_IRQHandler(8U);
}
/*! @brief Dma channel 9 ISR */
void DMA9_DMA25_IRQHandler(void){
   EDMA_DRV_IRQHandler(9U);
}
/*! @brief Dma channel 10 ISR */
void DMA10_DMA26_IRQHandler(void){
   EDMA_DRV_IRQHandler(10U);
}
/*! @brief Dma channel 11 ISR */
void DMA11_DMA27_IRQHandler(void){
   EDMA_DRV_IRQHandler(11U);
}
/*! @brief Dma channel 12 ISR */
void DMA12_DMA28_IRQHandler(void){
   EDMA_DRV_IRQHandler(12U);
}
/*! @brief Dma channel 13 ISR */
void DMA13_DMA29_IRQHandler(void){
   EDMA_DRV_IRQHandler(13U);
}
/*! @brief Dma channel 14 ISR */
void DMA14_DMA30_IRQHandler(void){
   EDMA_DRV_IRQHandler(14U);
}
/*! @brief Dma channel 15 ISR */
void DMA15_DMA31_IRQHandler(void){
   EDMA_DRV_IRQHandler(15U);
}
  
/* END dmaController1. */

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
