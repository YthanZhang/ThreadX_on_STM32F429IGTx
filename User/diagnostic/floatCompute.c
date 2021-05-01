//
// Created by ythan on 2021/5/1.
//


#include "floatCompute.h"

#include "stdint.h"
#include "stdbool.h"

#include "tx_api.h"


TX_THREAD diag_thread_floatComputeCompete1;
TX_THREAD diag_thread_floatComputeCompete2;

volatile uint32_t diag_floatComputeCompete1_repetitionCounter;
volatile uint32_t diag_floatComputeCompete2_repetitionCounter;


void diag_floatComputeThread1(uint32_t arg)
{
    volatile float result = 1000;

    while (true)
    {
        result *= 0.9f;
        ++diag_floatComputeCompete1_repetitionCounter;
        tx_thread_sleep(1);
    }
}

void diag_floatComputeThread2(uint32_t arg)
{
    volatile float result = 1000;

    while (true)
    {
        result *= 0.9f;
        ++diag_floatComputeCompete2_repetitionCounter;
        tx_thread_sleep(1);
    }
}
