@mainpage Seat Heating Status System 
By: S Sanchana - 256153

The System checks if the seat is occupied and if the the heater is switched ON
    
    If both the conditions satisfy:
         
         1. The system checks for the temperature sensor value using ADC
         
         2. Shows the output temperature value buy PWM
         
         3. Shows the temperature reading in Serial Monitor using USART

    Else:

        1. The PWM output is made zero

        2. Serial monitor shows "Heater OFF"


@subpage SeatHeatingSystem.c