/**
 * @file Activity1.c
 * @author S Sanchana
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include "Activity1.h"

/**
 * @brief Initialize GPIO Pins for aquiring status
 * 
 */
void gpio_init(void){
    DDRB |= (1<<PB0); //SET PB0=1 i.e., SET PB0 as Output Pin

    DDRD &= ~(1<<PD0); // CLEAR PD0=0 i.e., SET PD0 as Input Pin for Seat Occupancy
    PORTD |= (1<<PD0); // Set bit PD0 to 1

    DDRD &= ~(1<<PD3); // CLEAR PD3=0 i.e., SET PD3 as Input Pin for Heater Status
    PORTD |= (1<<PD3); // Set bit PD3 to 1
}

/**
 * @brief Change State of the LED
 * 
 * @param state ON or OFF state
 */
void change_led_state(uint8_t state){
	LED_PORT = (state << LED_PIN);
}

/**
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater (Make LED glow)
 * 
 * @return uint8_t ON or OFF status of the heater
 */
uint8_t heater_status (void){
    if (OCCUPANCY){
        if (HEATER_BUTTON){
            change_led_state(LED_ON);
            _delay_ms(100);
            return 1;
        }
        else{
            change_led_state(LED_OFF);
            _delay_ms(100);
            return 0;
        }
    }
    else{
        change_led_state(LED_OFF);
        _delay_ms(100);
        return 0;
    }
}