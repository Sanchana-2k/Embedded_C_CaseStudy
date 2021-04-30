/**
 * @file Activity4.h
 * @author S Sanchana
 * @brief Send Temperature Value via UART
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY4_H__
#define __ACTIVITY4_H__

#include <avr/io.h>
#include <util/delay.h>

// Macro Definitions

#define BAUD_RATE 103 /**< Set baud rate*/

/**
 * @brief Initialize UART to send Temperature Reading Output
 * 
 * @param ubrr_value Baud rate
 */
void USART_init(uint16_t);

/**
 * @brief Send data via UART
 * 
 * @param data Data to be sent
 */
void USARTWritechar(char data);

/**
 * @brief Display temperature value as output in serial montior
 * 
 * @param data Temperature sensor value (ADC Output)
 */
void USART_display(uint16_t data);

/**
 * @brief USART output when heater is OFF
 * 
 */
void USART_HeaterOFF(void);

#endif
