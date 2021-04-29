//
// Created by ythan on 2021/4/29.
//

/**
 * This file contains initialization process for ThreadX RTOS.
 */


#include "stm32f4xx_hal.h"
#include "tx_api.h"


/* Define SysClock*/
static const uint32_t SYSTEM_CLOCK  = 168000000;    // f429 running @ 168MHz
static const uint32_t SYSTICK_CYCLE = (SYSTEM_CLOCK / 10000) -
                                          1; /* Systick running @ 10KHz, i.e.
                                                0.1ms per tick*/


extern void _tx_timer_interrupt();    // in "tx_timer_interrupt.S" file


void _tx_initialize_low_level()
{
    /* Disable interrupts during ThreadX initialization.  */
    __set_PRIMASK(1);

    /* Configure SysTick for 1000Hz clock, or 16384 cycles if no reference.  */
    SysTick_Config(SYSTICK_CYCLE);

    /* Configure handler priorities.  */
    HAL_NVIC_SetPriority(SVCall_IRQn, 15, 0); /*Note: SVC must be lowest
                                                 priority*/
    HAL_NVIC_EnableIRQ(SVCall_IRQn);

    HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);
    HAL_NVIC_EnableIRQ(PendSV_IRQn); /*Note: PnSV must be lowest priority*/

    HAL_NVIC_SetPriority(SysTick_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(SysTick_IRQn);
}


/* System Tick timer interrupt handler */
void SysTick_Handler()
{
    /*BL      _tx_timer_interrupt*/
    _tx_timer_interrupt();
}
