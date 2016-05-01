/* ###################################################################
**     Filename    : main.c
**     Project     : flexio_qc01
**     Processor   : MK82FN256VLL15
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-04-16, 12:34, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "fsl_flexio_uart_driver.h"
FTM_Type *ftmBase;// = g_ftmBase[instance];
TPM_Type *tpmBase;// = g_tpmBase[instance];
uint8_t sec_tick_byte;
uint8_t servo_tick_byte;
static uint32_t s_flexioInstance;
flexio_uart_state_t uartState1,uartState2,uartState3,uartState4,uartState5,uartState6,uartState7,uartState8;
flexio_uart_status_t uart_status;
#define DATA_LENGTH         130
#define ROTOR_COUNT         8
uint8_t rxBuff1[DATA_LENGTH] = {0};
uint8_t rxBuff2[DATA_LENGTH] = {0};
uint8_t rxBuff3[DATA_LENGTH] = {0};
uint8_t rxBuff4[DATA_LENGTH] = {0};
uint8_t rxBuff5[DATA_LENGTH] = {0};
uint8_t rxBuff6[DATA_LENGTH] = {0};
uint8_t rxBuff7[DATA_LENGTH] = {0};
uint8_t rxBuff8[DATA_LENGTH] = {0};
uint32_t total_time_seconds;
uint32_t timestamp1[DATA_LENGTH] = {0};
uint32_t timestamp2[DATA_LENGTH] = {0};
uint32_t timestamp3[DATA_LENGTH] = {0};
uint32_t timestamp4[DATA_LENGTH] = {0};
uint32_t timestamp5[DATA_LENGTH] = {0};
uint32_t timestamp6[DATA_LENGTH] = {0};
uint32_t timestamp7[DATA_LENGTH] = {0};
uint32_t timestamp8[DATA_LENGTH] = {0};
uint32_t delta_timestamp1[DATA_LENGTH] = {0};
uint32_t delta_timestamp2[DATA_LENGTH] = {0};
uint32_t delta_timestamp3[DATA_LENGTH] = {0};
uint32_t delta_timestamp4[DATA_LENGTH] = {0};
uint32_t delta_timestamp5[DATA_LENGTH] = {0};
uint32_t delta_timestamp6[DATA_LENGTH] = {0};
uint32_t delta_timestamp7[DATA_LENGTH] = {0};
uint32_t delta_timestamp8[DATA_LENGTH] = {0};

uint16_t time_array_index1 = 0;
uint16_t time_array_index2 = 0;
uint16_t time_array_index3 = 0;
uint16_t time_array_index4 = 0;
uint16_t time_array_index5 = 0;
uint16_t time_array_index6 = 0;
uint16_t time_array_index7 = 0;
uint16_t time_array_index8 = 0;

bool rotor_fail[ROTOR_COUNT] = {false};

uint32_t pwm_duty_cycle[ROTOR_COUNT];
uint32_t inst_rpm[ROTOR_COUNT];         //instantaneous rotor RPM
uint32_t target_rpm[ROTOR_COUNT];       //expected rotor target RPM
uint32_t pwm_duty_cycle[ROTOR_COUNT];
/*
 * Stuff that is done if there is no user specified uart RX callback function
 *
            ++uartState->rxBuff;
            --uartState->rxSize;
            // Check and see if this was the last byte received
            if (uartState->rxSize == 0)
            {
                FLEXIO_UART_DRV_CompleteReceiveData(uartState);
            }

 */
void tach1_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp1;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp1;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp1[time_array_index1] = temp_time;
		delta_timestamp1[time_array_index1] = temp_delta;
		previous_timestamp1 = timestamp1[time_array_index1];
		time_array_index1++;
		if(time_array_index1 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index1 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach2_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp2;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp2;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp2[time_array_index2] = temp_time;
		delta_timestamp2[time_array_index2] = temp_delta;
		previous_timestamp2 = timestamp2[time_array_index2];
		time_array_index2++;
		if(time_array_index2 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index2 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach3_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp3;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp3;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp3[time_array_index3] = temp_time;
		delta_timestamp3[time_array_index3] = temp_delta;
		previous_timestamp3 = timestamp3[time_array_index3];
		time_array_index3++;
		if(time_array_index3 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index3 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach4_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp4;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp4;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp4[time_array_index4] = temp_time;
		delta_timestamp4[time_array_index4] = temp_delta;
		previous_timestamp4 = timestamp4[time_array_index4];
		time_array_index4++;
		if(time_array_index4 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index4 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach5_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp5;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp5;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp5[time_array_index5] = temp_time;
		delta_timestamp5[time_array_index5] = temp_delta;
		previous_timestamp5 = timestamp5[time_array_index5];
		time_array_index5++;
		if(time_array_index5 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index5 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach6_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp6;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp6;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp6[time_array_index6] = temp_time;
		delta_timestamp6[time_array_index6] = temp_delta;
		previous_timestamp6 = timestamp6[time_array_index6];
		time_array_index6++;
		if(time_array_index6 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index6 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach7_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp7;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp7;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp7[time_array_index7] = temp_time;
		delta_timestamp7[time_array_index7] = temp_delta;
		previous_timestamp7 = timestamp7[time_array_index7];
		time_array_index7++;
		if(time_array_index7 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index7 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}
void tach8_rx_callback(flexio_uart_state_t *uartState ){
	static uint32_t previous_timestamp8;
	uint32_t temp_delta;
	uint32_t temp_time;
	// Collect timestamp and calculate the difference in time for the delta_timestamp

	temp_time = (total_time_seconds*100000)+((59999999-PIT_HAL_ReadTimerCount(g_pitBase[pitTimer1_IDX],pitTimer1_CHANNEL) )/600); // in 10uS resolution
	temp_delta = temp_time - previous_timestamp8;
	if(temp_delta > 100){ // filter out events that are glitch like - not physically possible propeller events
		timestamp8[time_array_index8] = temp_time;
		delta_timestamp8[time_array_index8] = temp_delta;
		previous_timestamp8 = timestamp8[time_array_index8];
		time_array_index8++;
		if(time_array_index8 >= DATA_LENGTH ){ // stay inside array bounds
			time_array_index8 = 0;
		}
	}
	// Resume the normal rx_callback procedure
     ++uartState->rxBuff;
	 --uartState->rxSize;
	 // Check and see if this was the last byte received
	 if (uartState->rxSize == 0)
	 {
//            FLEXIO_UART_DRV_CompleteReceiveData(uartState);

//These lines below are what happens in FLEXIO_UART_DRV_CompleteReceiveData()
// there was no way of referencing the function ( an internal non-public interface )
// so the body of the function is duplicated here.

		 FLEXIO_UART_Rx_HAL_SetRxBufferFullIntCmd(&(uartState->rxDev), false);

		 /* Signal the synchronous completion object. */
		 if (uartState->isRxBlocking)
		 {
			 OSA_SemaPost(&uartState->rxIrqSync);
		 }

		 /* Update the information of the module driver state */
		 uartState->isRxBusy = false;
	 }

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
//FTM Example Code
#define BOARD_FTM_INSTANCE 3
#define BOARD_FTM_CHANNEL  4

  // Software trigger to update registers.
  FTM_HAL_SetSoftwareTriggerCmd(g_ftmBase[flexTimer1_IDX], true);

  s_flexioInstance = 0;
  /* Fill in FlexIO config data */
  flexio_user_config_t userConfig =
  {
      .useInt = true,
      .onDozeEnable = false,
      .onDebugEnable = true,
      .fastAccessEnable = false
  };
  FLEXIO_DRV_Init(s_flexioInstance,&userConfig);
  FLEXIO_DRV_Start(s_flexioInstance);
  /* Fill in FlexIO UART config data */
  flexio_uart_userconfig_t uartConfig;
  uartConfig.bitCounter = kFlexIOUart8BitsPerChar;
  uartConfig.baudRate = 115200;
  uartConfig.uartMode = flexioUART_RxOnly;
  //uartConfig.txConfig.pinIdx = 5;
  //uartConfig.txConfig.shifterIdx = 0;
  //uartConfig.txConfig.timerIdx = 0;
  uartConfig.rxConfig.pinIdx = 0;
  uartConfig.rxConfig.shifterIdx = 0;
  uartConfig.rxConfig.timerIdx = 0;

  /* init the FlexIO simulated UART module with base address and config structure*/
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState1, &uartConfig);
  uartConfig.rxConfig.pinIdx = 1;
  uartConfig.rxConfig.shifterIdx = 1;
  uartConfig.rxConfig.timerIdx = 1;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState2, &uartConfig);
  uartConfig.rxConfig.pinIdx = 2;
  uartConfig.rxConfig.shifterIdx = 2;
  uartConfig.rxConfig.timerIdx = 2;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState3, &uartConfig);
  uartConfig.rxConfig.pinIdx = 3;
  uartConfig.rxConfig.shifterIdx = 3;
  uartConfig.rxConfig.timerIdx = 3;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState4, &uartConfig);
  uartConfig.rxConfig.pinIdx = 4;
  uartConfig.rxConfig.shifterIdx = 4;
  uartConfig.rxConfig.timerIdx = 4;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState5, &uartConfig);
  uartConfig.rxConfig.pinIdx = 5;
  uartConfig.rxConfig.shifterIdx = 5;
  uartConfig.rxConfig.timerIdx = 5;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState6, &uartConfig);
  uartConfig.rxConfig.pinIdx = 6;
  uartConfig.rxConfig.shifterIdx = 6;
  uartConfig.rxConfig.timerIdx = 6;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState7, &uartConfig);
  uartConfig.rxConfig.pinIdx = 7;
  uartConfig.rxConfig.shifterIdx = 7;
  uartConfig.rxConfig.timerIdx = 7;
  FLEXIO_UART_DRV_Init(s_flexioInstance, &uartState8, &uartConfig);

  FLEXIO_UART_DRV_InstallRxCallback(&uartState1,(flexio_uart_rx_callback_t) tach1_rx_callback,rxBuff1,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState2,(flexio_uart_rx_callback_t) tach2_rx_callback,rxBuff2,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState3,(flexio_uart_rx_callback_t) tach3_rx_callback,rxBuff3,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState4,(flexio_uart_rx_callback_t) tach4_rx_callback,rxBuff4,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState5,(flexio_uart_rx_callback_t) tach5_rx_callback,rxBuff5,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState6,(flexio_uart_rx_callback_t) tach6_rx_callback,rxBuff6,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState7,(flexio_uart_rx_callback_t) tach7_rx_callback,rxBuff7,NULL,true);
  FLEXIO_UART_DRV_InstallRxCallback(&uartState8,(flexio_uart_rx_callback_t) tach8_rx_callback,rxBuff8,NULL,true);

  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState1);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState2);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState3);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState4);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState5);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState6);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState7);
  uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState8);

  uint8_t dbg_loop,i; //loop counters
  uint8_t fail_count[ROTOR_COUNT];
  uint32_t calc_rpm;  // calculated rpm based on timestamp

  target_rpm[0]=5400;
  target_rpm[1]=5400;
  target_rpm[2]=5400;
  target_rpm[3]=5400;
  target_rpm[4]=5400;
  target_rpm[5]=5400;
  target_rpm[6]=5400;
  target_rpm[7]=5400;

  for(i=0;i<ROTOR_COUNT;i++) pwm_duty_cycle[i]=0;

  for(;;){ // The do forever main loop
	 if(servo_tick_byte){
	    servo_tick_byte = false;
	    // the servo loop goes here

	    // input part of servo loop
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState1);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState2);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState3);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState4);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState5);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState6);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState7);
	    uart_status = FLEXIO_UART_DRV_AbortReceivingData(&uartState8);

	    // collect the rotor tachometer data
	    // at 20 loops per second  one blade edge per loop is 600 RPM
	    // calculate rpm based on delta time on last data collected

	    if(time_array_index1!=0){
	    	calc_rpm = (100000*30)/( delta_timestamp1[time_array_index1-1] );
//	    	debug_printf("%d   %d   %d\r\n",calc_rpm,time_array_index1,delta_timestamp1[time_array_index1-1]);
	    	if(calc_rpm >30000){
	    		i=time_array_index1;
	    		do{
	    		    i--;
	    		    calc_rpm = (100000*30)/( delta_timestamp1[i] );
	    		    debug_printf("%d   %d   %d\r\n",calc_rpm,i,delta_timestamp1[i]);
	    		    if(calc_rpm < 30000) inst_rpm[0] = calc_rpm;
	    	    }while( i>0 );
	    		if(calc_rpm>30000) inst_rpm[0]=time_array_index1*600;
	    	}else{
	    		inst_rpm[0] = calc_rpm;
	    	}
	    }
	    inst_rpm[1] = time_array_index2*600;
	    inst_rpm[2] = time_array_index3*600;
	    inst_rpm[3] = time_array_index4*600;
	    inst_rpm[4] = time_array_index5*600;
	    inst_rpm[5] = time_array_index6*600;
	    inst_rpm[6] = time_array_index7*600;
	    inst_rpm[7] = time_array_index8*600;

	    time_array_index1 = 0;
	    time_array_index2 = 0;
	    time_array_index3 = 0;
	    time_array_index4 = 0;
	    time_array_index5 = 0;
	    time_array_index6 = 0;
	    time_array_index7 = 0;
	    time_array_index8 = 0;

	    // restart the receive process

		FLEXIO_UART_DRV_ReceiveData(&uartState1, rxBuff1, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState2, rxBuff2, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState3, rxBuff3, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState4, rxBuff4, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState5, rxBuff5, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState6, rxBuff6, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState7, rxBuff7, DATA_LENGTH);
		FLEXIO_UART_DRV_ReceiveData(&uartState8, rxBuff8, DATA_LENGTH);


		//   process the rotor tachometer data
        for(i=0;i<ROTOR_COUNT;i++){
			if(inst_rpm[i] < target_rpm[i]) {
				if(pwm_duty_cycle[i]<2300) pwm_duty_cycle[i]++;
			}else{
				if(pwm_duty_cycle[i]>0)pwm_duty_cycle[i]--;
			}
			// check for rotor failures
			if(inst_rpm[i]< (target_rpm[i]/2)){
				fail_count[i]++;
				if(fail_count[i]>10) rotor_fail[i] = true;
				// take needed action on rotor failure(s)
				//if(pwm_duty_cycle[i]>0)pwm_duty_cycle[i]--;
			}else{
				rotor_fail[i] = false;
				fail_count[i] = 0;
			}
        }


		// output part of servo loop
        ftmBase = g_ftmBase[flexTimer1_IDX];
        FTM_HAL_SetChnCountVal(ftmBase, 0, pwm_duty_cycle[0]);
        FTM_HAL_SetChnCountVal(ftmBase, 1, pwm_duty_cycle[1]);
        FTM_HAL_SetChnCountVal(ftmBase, 2, pwm_duty_cycle[2]);
        FTM_HAL_SetChnCountVal(ftmBase, 3, pwm_duty_cycle[3]);
        FTM_HAL_SetChnCountVal(ftmBase, 4, pwm_duty_cycle[4]);
        FTM_HAL_SetChnCountVal(ftmBase, 5, pwm_duty_cycle[5]);

		//*****************************************************************************
		// fill in for flex timer channel 6 that could not have a PWM output configured
		// use a tpm channel to provide the pwm channel
		tpmBase = g_tpmBase[tpmTmr1_IDX];
		TPM_HAL_SetChnCountVal(tpmBase, 0,pwm_duty_cycle[6] );

		//*****************************************************************************

	    FTM_HAL_SetChnCountVal(ftmBase, 7, pwm_duty_cycle[7]);

		//software trigger the PWM output changes
		FTM_HAL_SetSoftwareTriggerCmd(g_ftmBase[flexTimer1_IDX], true);

	 }

	 if(sec_tick_byte){
		 sec_tick_byte = false;
	     GPIO_DRV_TogglePinOutput(LEDRGB_GREEN);
	     for(dbg_loop=0;dbg_loop<ROTOR_COUNT;dbg_loop++){
	    	 debug_printf("Rotor #%d rpm =  %d   PWM CMD = %d \r\n",dbg_loop+1,inst_rpm[dbg_loop],pwm_duty_cycle[dbg_loop]);
	     }
	     if(rotor_fail[0]) debug_printf("Rotor #1 FAILURE!!!\r\n");
	 }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
