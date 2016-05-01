/* ###################################################################
**     Filename    : Events.h
**     Project     : flexio_qc01
**     Processor   : MK82FN256VLL15
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-04-16, 12:34, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "fsl_device_registers.h"
#include "pin_mux.h"
#include "osa1.h"
#include "clockMan1.h"
#include "pitTimer1.h"
#include "gpio1.h"
#include "DbgCs1.h"
#include "flexibleIO1.h"
#include "dmaController1.h"
#include "flexTimer1.h"
#include "tpmTmr1.h"
#include "servo_loop_timer.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifdef pitTimer1_IDX
/*
** ===================================================================
**     Interrupt handler : PIT0CH0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PIT0CH0_IRQHandler(void);
#else
  /* This IRQ handler is not used by pitTimer1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by pitTimer1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

#ifdef flexibleIO1_IDX
/*
** ===================================================================
**     Interrupt handler : FLEXIO0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FLEXIO0_IRQHandler(void);
#else
  /* This IRQ handler is not used by flexibleIO1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by flexibleIO1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif



#ifdef flexTimer1_IDX
/*
** ===================================================================
**     Interrupt handler : FTM0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FTM0_IRQHandler(void);
#else
  /* This IRQ handler is not used by flexTimer1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by flexTimer1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

#ifdef tpmTmr1_IDX
/*
** ===================================================================
**     Interrupt handler : TPM1_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM1_IRQHandler(void);
#else
  /* This IRQ handler is not used by tpmTmr1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

#ifdef servo_loop_timer_IDX
/*
** ===================================================================
**     Interrupt handler : PIT0CH1_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PIT0CH1_IRQHandler(void);
#else
  /* This IRQ handler is not used by servo_loop_timer component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by servo_loop_timer component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
