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

#include "configuration.h"

#include <avr/io.h>
#include <util/delay.h>

#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"

/**
 * @brief Runs the Application
 * 
 * @return int Returns 0 on successful completion
 */
int main(void){

    // GPIO Initialization
    gpio_init();
    // ADC Initialization
    ADC_init();
    // PWM Initialization
    pwm_init();
    //USART Initialization
    USART_init(BAUD_RATE);

    while (1){
        // Variable to store status of the Heater
        uint8_t status=0;

        status = heater_status(); // Get status of the Heater

        if (status==1){
            uint16_t sensor_val = 0; // Variable to store sensor value
            sensor_val = ReadADC(ADC_CHANNEL); // Read sensor value
            _delay_ms(200);
            PWM_output(sensor_val); // Show output as PWM
            USART_display(sensor_val); // Send temp value via USART to serial monitor
        }
        else{
            PWM_heaterOFF(); // Switch off (make PWM output as zero) if heater is off or driver not seated
            USART_HeaterOFF(); // Show Heater OFF output when heater is off or driver not seated
        }
    }

    return 0;
}