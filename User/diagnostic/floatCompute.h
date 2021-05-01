//
// Created by ythan on 2021/5/1.
//

#ifndef STM32F429CUBETHREADXTEST_FLOATCOMPUTE_H
#define STM32F429CUBETHREADXTEST_FLOATCOMPUTE_H


#include "stdint.h"


#include "tx_api.h"


extern TX_THREAD diag_thread_floatComputeCompete1;
extern TX_THREAD diag_thread_floatComputeCompete2;

extern volatile uint32_t diag_floatComputeCompete1_repetitionCounter;
extern volatile uint32_t diag_floatComputeCompete2_repetitionCounter;


void diag_floatComputeThread1(uint32_t arg);
void diag_floatComputeThread2(uint32_t arg);


#endif    // STM32F429CUBETHREADXTEST_FLOATCOMPUTE_H
