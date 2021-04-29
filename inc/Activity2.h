/**
 * @file Activity2.h
 * @author S Sanchana
 * @brief Read the Temperature Sensor (Potentiometer) value via ADC
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initialize ADC for aquiring Temperature Sensor (Potentiometer) value
 * 
 */
void ADC_init(void);

/**
 * @brief Read the Temperature Sensor (Potentiometer) value via ADC
 * 
 * @param ch Channel to which the ADC is connected
 * @return uint16_t Temperature Sensor (Potentiometer) value
 */
uint16_t ReadADC(uint8_t);

#endif