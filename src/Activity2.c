/**
 * @file Activity2.c
 * @author S Sanchana
 * @brief Read the Temperature Sensor (Potentiometer) value via ADC
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include "Activity2.h"

/**
 * @brief Initialize ADC for aquiring Temperature Sensor (Potentiometer) value
 * 
 */
void ADC_init(void){
    ADMUX=(1<<REFS0); // For Aref=AVcc;

    ADCSRA=(1<<ADEN)|(7<<ADPS0); //Enable ADC and set 128 prescaler
}

/**
 * @brief Read the Temperature Sensor (Potentiometer) value via ADC
 * 
 * @param ch The to which the ADC is connected
 * @return uint16_t Temperature Sensor (Potentiometer) value
 */
uint16_t ReadADC(uint8_t ch){

    //Select ADC Channel ch must be 0-7

    ADMUX&=0xf8; //clearing MUX2,1,0 bits and considering the rest as such
    ch=ch&0b00000111;

    ADMUX|=ch;

    //Start Single conversion

    ADCSRA|=(1<<ADSC);

    //Wait for conversion to complete

    while(!(ADCSRA & (1<<ADIF)));

    //Clear ADIF by writing one to it

    ADCSRA|=(1<<ADIF);

    return(ADC);
}
