/**
 * @file Activity1.c
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

void gpio_init(void){
    DDRB |= (1<<PB0); //SET PB0=1 i.e., SET PB0 as Output Pin

    DDRD &= ~(1<<PD0); // CLEAR PD0=0 i.e., SET PD0 as Input Pin for Seat Occupancy
    PORTD |= (1<<PD0); // Set bit PD0 to 1

    DDRD &= ~(1<<PD3); // CLEAR PD3=0 i.e., SET PD3 as Input Pin for Heater Status
    PORTD |= (1<<PD3); // Set bit PD3 to 1
}

uint8_t heater_status (void){
    if (!(PIND&(1<<PD0))){
                if (!(PIND&(1<<PD3))){
                    PORTB |= (1<<PB0);
                    _delay_ms(100);
                    return 1;
                }
                else{
                    PORTB &= ~(1<<PB0);
                    _delay_ms(100);
                    return 0;
                }
        }
        else{
            PORTB &= ~(1<<PB0);
            _delay_ms(100);
            return 0;
        }
}