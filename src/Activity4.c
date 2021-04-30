/**
 * @file Activity4.c
 * @author S Sanchana
 * @brief Send Temperature Value via UART
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include "configuration.h"
#include "Activity4.h"

/**
 * @brief Initialize UART to send Temperature Reading Output
 * 
 * @param ubrr_value Baud rate
 */
void USART_init(uint16_t ubrr_value){

    //Set Baud rate
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)&0x00ff;
    
    //Select number of bits to send (8 bits) - Consider Asynchronous mode
    UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
    //UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //Enable The receiver and transmitter
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

/**
 * @brief Send data via UART
 * 
 * @param data Data to be sent
 */
void USARTWritechar(char data){

    //Wait until the transmitter is ready
    while (!(UCSR0A & (1<<UDRE0))){
    //Do nothing
    }

    //Now write the data to USART buffer
    UDR0=data;
}

/**
 * @brief Display temperature value as output in serial montior
 * 
 * @param data Temperature sensor value (ADC Output)
 */
void USART_display(uint16_t data){
    int i = 0;
    if (data>=0 && data<=200){
        unsigned char reading[]="Temperature: 20 deg C";
        i = 0;
        while(reading[i] != 0) //Loop to Write every character of Reading
        {
            USARTWritechar(reading[i]);
            i++;                             // increment counter
        }
    }
    else if (data>=210 && data<=500){
        unsigned char reading[]="Temperature: 25 deg C";
        i = 0;
        while(reading[i] != 0) //Loop to Write every character of Reading
        {
            USARTWritechar(reading[i]);
            i++;                             // increment counter
        }
    }
    else if (data>=510 && data<=700){
        unsigned char reading[]="Temperature: 29 deg C";
        i = 0;
        while(reading[i] != 0) //Loop to Write every character of Reading
        {
            USARTWritechar(reading[i]);
            i++;                             // increment counter
        }
    }
    else if (data>=710 && data<=1024){
        unsigned char reading[]="Temperature: 33 deg C";
        i = 0;
        while(reading[i] != 0) //Loop to Write every character of Reading
        {
            USARTWritechar(reading[i]);
            i++;                             // increment counter
        }
    }
    else{
        unsigned char reading[]="Temperature: NA deg C";
        i = 0;
        while(reading[i] != 0) //Loop to Write every character of Reading
        {
            USARTWritechar(reading[i]);
            i++;                             // increment counter
        }
    }

    USARTWritechar('\n');
}

/**
 * @brief USART output when heater is OFF
 * 
 */
void USART_HeaterOFF(void){
    int i = 0;
    unsigned char heater_off[]="Heater OFF";
    i = 0;
    while(heater_off[i] != 0) //Loop to Write every character of Reading
    {
        USARTWritechar(heater_off[i]);
        i++;                             // increment counter
    }
    USARTWritechar('\n');
}