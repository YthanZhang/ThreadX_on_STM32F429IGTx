//
// Created by ythan on 2021/5/1.
//


#include "floatCompute.hpp"

#include <cstdint>

#include "tx_api.h"


namespace diag
{


TX_THREAD thread_floatComputeCompete1;
TX_THREAD thread_floatComputeCompete2;

volatile uint32_t floatComputeCompete1_repetitionCounter;
volatile uint32_t floatComputeCompete2_repetitionCounter;


void floatComputeThread1(uint32_t arg)
{
    volatile float result = 1000;

    while (true)
    {
        result *= 0.9f;
        ++floatComputeCompete1_repetitionCounter;
        tx_thread_sleep(1);
    }
}

void floatComputeThread2(uint32_t arg)
{
    volatile float result = 1000;

    while (true)
    {
        result *= 0.9f;
        ++floatComputeCompete2_repetitionCounter;
        tx_thread_sleep(1);
    }
}


}    // namespace diag
