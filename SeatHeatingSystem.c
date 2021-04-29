/**
 * @file SeatHeatingSystem.c
 * @author S Sanchana
 * @brief 
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

#include "Activity1.h"

int main(void){

    gpio_init();

    while (1){
        uint8_t status=0;

        status = heater_status();
    }

    return 0;
}