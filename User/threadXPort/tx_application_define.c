//
// Created by ythan on 2021/4/30.
//


#include "stdbool.h"

#include "main.h"
#include "tx_api.h"

#include "floatCompute.h"


TX_BYTE_POOL bytePool0;


unsigned long my_thread_counter = 0;
TX_THREAD mainThread;

void mainThread_entry(uint32_t arg)
{
    /* Start other threads */


    /* Enter into a forever loop. */
    while (1)
    {
        /* Increment thread counter. */
        my_thread_counter++;

        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        /* Sleep for 500 tick, 500ms */
        tx_thread_sleep(500);
    }
}


void tx_application_define(void* first_unused_memory)
{
    void* pointer;
    uint32_t stackSize;

    tx_byte_pool_create(&bytePool0,
                        (char*)"BytePool0",
                        first_unused_memory,
                        (1024 * 16));

    /* Create mainThread */
    stackSize = 256;
    tx_byte_allocate(&bytePool0, &pointer, stackSize, TX_NO_WAIT);
    tx_thread_create(&mainThread,
                     (char*)"My Thread",
                     mainThread_entry,
                     0x1000,
                     pointer,
                     stackSize,
                     4,
                     4,
                     TX_16_ULONG,
                     TX_AUTO_START);

    /* Create floatComputeCompete threads */
    stackSize = 256;
    tx_byte_allocate(&bytePool0, &pointer, stackSize, TX_NO_WAIT);
    tx_thread_create(&diag_thread_floatComputeCompete1,
                     (char*)"float compute compete 1",
                     diag_floatComputeThread1,
                     0x1001,
                     pointer,
                     stackSize,
                     3,
                     2,
                     TX_NO_TIME_SLICE,
                     TX_AUTO_START);
    tx_byte_allocate(&bytePool0, &pointer, stackSize, TX_NO_WAIT);
    tx_thread_create(&diag_thread_floatComputeCompete2,
                     (char*)"float compute compete 2",
                     diag_floatComputeThread2,
                     0x1002,
                     pointer,
                     stackSize,
                     3,
                     2,
                     TX_NO_TIME_SLICE,
                     TX_AUTO_START);
}
