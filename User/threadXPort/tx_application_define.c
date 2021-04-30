//
// Created by ythan on 2021/4/30.
//


#include "tx_api.h"
#include "main.h"


unsigned long my_thread_counter = 0;
TX_THREAD my_thread;

void my_thread_entry(ULONG thread_input)
{
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
    /* Create my_thread! */
    _tx_thread_create(&my_thread,
                      "My Thread",
                      my_thread_entry,
                      0x1000,
                      first_unused_memory,
                      128,
                      4,
                      4,
                      TX_16_ULONG,
                      TX_AUTO_START);
}
