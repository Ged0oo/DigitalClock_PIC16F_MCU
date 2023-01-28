/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 */

#include "application.h"

uint8 hour=20, min=45, sec=50;
uint8 counter;
segment_t seg =
{
    .segment_pins[0].port = PORTC_INDEX,
    .segment_pins[0].pin = GPIO_PIN0,
    .segment_pins[0].logic = GPIO_LOW,
    .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    
    .segment_pins[1].port = PORTC_INDEX,
    .segment_pins[1].pin = GPIO_PIN1,
    .segment_pins[1].logic = GPIO_LOW,
    .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    
    .segment_pins[2].port = PORTC_INDEX,
    .segment_pins[2].pin = GPIO_PIN2,
    .segment_pins[2].logic = GPIO_LOW,
    .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    
    .segment_pins[3].port = PORTC_INDEX,
    .segment_pins[3].pin = GPIO_PIN3,
    .segment_pins[3].logic = GPIO_LOW,
    .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT,
};

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    while(1)
    {
        for(counter=0 ; counter<34 ; counter++)
        {
            ret = gpio_port_write_logic(PORTD_INDEX, 1);
            ret = seven_segement_write_number(&seg, (uint8)(hour/10) );
            __delay_ms(5);

            ret = gpio_port_write_logic(PORTD_INDEX, 2);
            ret = seven_segement_write_number(&seg, (uint8)(hour%10 ) );
            __delay_ms(5);

            ret = gpio_port_write_logic(PORTD_INDEX, 4);
            ret = seven_segement_write_number(&seg, (uint8)(min/10) );
            __delay_ms(5);

            ret = gpio_port_write_logic(PORTD_INDEX, 8);
            ret = seven_segement_write_number(&seg, (uint8)(min%10) );
            __delay_ms(5);

            ret = gpio_port_write_logic(PORTD_INDEX, 16);
            ret = seven_segement_write_number(&seg, (uint8)(sec/10) );
            __delay_ms(5);

            ret = gpio_port_write_logic(PORTD_INDEX, 32);
            ret = seven_segement_write_number(&seg, (uint8)(sec%10) );
            __delay_ms(5);
        }
        
        sec++;
        
        if(sec==60)
        {
            min++;
            sec=0;
        }
        if(min==60)
        {
            hour++;
            min=0;
        }
        if(hour==24)
        {
            hour=0;
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = gpio_port_direction_intialize(PORTD_INDEX, 0xC0);
    ret = seven_segement_intialize(&seg);
    
}
