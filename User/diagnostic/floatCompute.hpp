//
// Created by ythan on 2021/5/1.
//

#ifndef STM32F429CUBETHREADXTEST_FLOATCOMPUTE_HPP
#define STM32F429CUBETHREADXTEST_FLOATCOMPUTE_HPP


#include <cstdint>

#include "tx_api.h"


namespace diag
{


extern TX_THREAD thread_floatComputeCompete1;
extern TX_THREAD thread_floatComputeCompete2;

extern volatile uint32_t floatComputeCompete1_repetitionCounter;
extern volatile uint32_t floatComputeCompete2_repetitionCounter;


void floatComputeThread1(uint32_t arg);
void floatComputeThread2(uint32_t arg);


}

#endif    // STM32F429CUBETHREADXTEST_FLOATCOMPUTE_HPP
