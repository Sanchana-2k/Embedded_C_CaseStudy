/**
 * @file Activity3.c
 * @author S Sanchana
 * @brief Modulate PWM output based on Temperature Sensor value
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY3_H__
#define __ACTIVITY3_H__

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initialize Timer for PWM operation
 * 
 */
void pwm_init(void);

/**
 * @brief Modulate PWM output duty cycle based on Temperature Sensor value
 * 
 * @param data Temperature Sensor value
 */
void PWM_output(uint16_t);

#endif