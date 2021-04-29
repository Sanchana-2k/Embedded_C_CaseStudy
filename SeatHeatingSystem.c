/**
 * @file SeatHeatingSystem.c
 * @author S Sanchana
 * @brief Notify the Seat Heating Status of the User
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

#include "Activity1.h"
#include "Activity2.h"

int main(void){

    // GPIO Initialization
    gpio_init();
    // ADC Initialization
    InitADC();

    while (1){
        uint8_t status=0;

        uint16_t sensor_val = 0;

        status = heater_status();

        if (status==1){
            sensor_val = ReadADC(0);
            _delay_ms(200);

        }
    }

    return 0;
}