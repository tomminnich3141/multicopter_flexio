/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
extern uint8_t sec_tick_byte;
extern uint8_t servo_tick_byte;
extern uint32_t total_time_seconds;
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
void PIT0CH0_IRQHandler(void)
{
  /* Clear interrupt flag.*/
  PIT_HAL_ClearIntFlag(g_pitBase[pitTimer1_IDX], pitTimer1_CHANNEL);
  /* Write your code here ... */
  total_time_seconds++;
  sec_tick_byte = true;
}
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
void FLEXIO0_IRQHandler(void)
{
  FLEXIO_DRV_IRQHandler(flexibleIO1_IDX);
  /* Write your code here ... */
}
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
void FTM0_IRQHandler(void)
{
  FTM_DRV_IRQHandler(flexTimer1_IDX);
  /* Write your code here ... */
}
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
void TPM1_IRQHandler(void)
{
  TPM_DRV_IRQHandler(tpmTmr1_IDX);
  /* Write your code here ... */
}
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
void PIT0CH1_IRQHandler(void)
{
  /* Clear interrupt flag.*/
  PIT_HAL_ClearIntFlag(g_pitBase[servo_loop_timer_IDX], servo_loop_timer_CHANNEL);
  /* Write your code here ... */
  servo_tick_byte = true;
}
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
