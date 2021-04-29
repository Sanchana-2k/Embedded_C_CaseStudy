/**
 * @file Activity1.h
 * @author S Sanchana
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__

#include <avr/io.h>
#include <util/delay.h>

// Macro Definitions

#define OCCUPANCY (!(PIND&(1<<PD0)))  /**< Check Seat Occupancy*/
#define HEATER_BUTTON (!(PIND&(1<<PD3)))  /**< Check if Heater Button if ON or OFF */


#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PB0)   /**< LED Pin number  */

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */


/**
 * @brief Initialize GPIO Pins for aquiring status
 * 
 */
void gpio_init(void);

/**
 * @brief Change State of the LED
 * 
 * @param state ON or OFF state
 */
void change_led_state(uint8_t);

/**
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater (Make LED glow)
 * 
 * @return uint8_t ON or OFF status of the heater
 */
uint8_t heater_status (void);

#endif