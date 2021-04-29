/**
 * @file Activity1.h
 * @author S Sanchana
 * @brief 
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

void gpio_init(void);

uint8_t heater_status (void);

#endif