/* 
 * File:   First_Application.c
 * Author: abdo
 *
 * Created on September 19, 2023, 4:53 PM
 */

#include "First_Application.h"

#define   _XTAL_FREQ      500000

Pin_Config_Type State_Led = {
    .Port = PORTA_INDEX,
    .Pin = GPIO_PIN7,
    .Direction = GPIO_DIRECTION_OUTPUT,
    .Logic = GPIO_LOW
}; 

Std_ReturnType Func_State = Func_OK;

int main() {
    /* counter Port_Index Start with 1 that PortB index is 1 @ref Port_Index_Type*/
    uint8 Port_Index = 1 , Pin_number = 0;
    
    Application_Initilization();
  
    while(1){
        
        /* iterate on ports */
        for(Port_Index = 1 ; Port_Index <  4  ; Port_Index++)
        {
            /* initialize lat registers before doing operation */
            *Lat_Registers[Port_Index] = 0x00;
            /* iterate on pins */
            for(Pin_number = 0 ; Pin_number < Max_Number_Of_Pins ;Pin_number++)
            {
                SET_BIT(*Lat_Registers[Port_Index] , Pin_number);
                __delay_ms(2000);
            }
        
        }
    
    }
    
    return (EXIT_SUCCESS);
}
void Application_Initilization(void)
{
    Func_State = GPIO_Port_Direction_Initilization(PORTB_INDEX , 0x00); 
    Func_State = GPIO_Port_Direction_Initilization(PORTC_INDEX , 0x00); 
    Func_State = GPIO_Port_Direction_Initilization(PORTD_INDEX , 0x00);
    
}