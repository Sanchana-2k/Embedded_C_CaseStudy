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

/**
 * @brief Initialize GPIO Pins for aquiring status
 * 
 */
void gpio_init(void);

/**
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater (Make LED glow)
 * 
 * @return uint8_t ON or OFF status of the heater
 */
uint8_t heater_status (void);

#endif