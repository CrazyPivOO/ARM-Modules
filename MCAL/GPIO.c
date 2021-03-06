/*
 * GPIO.c
 *
 *  Created on: October 4, 2018
 *      Author: PRRAG
 */

#include "tm4c123gh6pm.h"
#include "GPIO.h"

void GPIO_vSetConfig(u8 PORTName,u8 DEN,u8 DIR,u8 PCTL,u8 PUR){
    switch (PORTName){
        case 'A':
            SYSCTL_RCGCGPIO_R |= (1<<A);
            GPIO_PORTA_DEN_R = DEN;
            GPIO_PORTA_DIR_R = DIR;
            GPIO_PORTA_PCTL_R = PCTL;
            GPIO_PORTA_PUR_R = PUR;
            break;

        case 'B':
            SYSCTL_RCGCGPIO_R |= (1<<B);
            GPIO_PORTB_DEN_R = DEN;
            GPIO_PORTB_DIR_R = DIR;
            GPIO_PORTB_PCTL_R = PCTL;
            GPIO_PORTB_PUR_R = PUR;
            break;

        case 'C':
            SYSCTL_RCGCGPIO_R |= (1<<C);
            GPIO_PORTC_DEN_R = DEN;
            GPIO_PORTC_DIR_R = DIR;
            GPIO_PORTC_PCTL_R = PCTL;
            GPIO_PORTC_PUR_R = PUR;
            break;

        case 'D':
            SYSCTL_RCGCGPIO_R |= (1<<D);
            GPIO_PORTD_DEN_R = DEN;
            GPIO_PORTD_DIR_R = DIR;
            GPIO_PORTD_PCTL_R = PCTL;
            GPIO_PORTD_PUR_R = PUR;
            break;

        case 'E':
            SYSCTL_RCGCGPIO_R |= (1<<E);
            GPIO_PORTE_DEN_R = DEN;
            GPIO_PORTE_DIR_R = DIR;
            GPIO_PORTE_PCTL_R = PCTL;
            GPIO_PORTE_PUR_R = PUR;
            break;

        case 'F':
            SYSCTL_RCGCGPIO_R |= (1<<F);
            GPIO_PORTF_DEN_R = DEN;
            GPIO_PORTF_DIR_R = DIR;
            GPIO_PORTF_PCTL_R = PCTL;
            GPIO_PORTF_PUR_R = PUR;
            break;

        default:
            break;
    }
}
Status GPIO_sWritePORT(u8 PORTName,u8 val){
    if((SYSCTL_RCGCGPIO_R&(1<<(PORTName-'A'))) == 0){      //ASCII of char - ASCII of A = number of port
        return;
    }
    switch (PORTName){
        case 'A':
            GPIO_PORTA_DATA_R = (GPIO_PORTA_DIR_R & val);
            return Ok;

        case 'B':
            GPIO_PORTB_DATA_R = (GPIO_PORTB_DIR_R & val);
            return Ok;

        case 'C':
            GPIO_PORTC_DATA_R = (GPIO_PORTC_DIR_R & val);
            return Ok;

        case 'D':
            GPIO_PORTD_DATA_R = (GPIO_PORTD_DIR_R & val);
            return Ok;

        case 'E':
            GPIO_PORTE_DATA_R = (GPIO_PORTE_DIR_R & val);
            return Ok;

        case 'F':
            GPIO_PORTF_DATA_R = (GPIO_PORTF_DIR_R & val);
            return Ok;

        default:
            return Nok;
    }
}
Status GPIO_sReadPin(u8 PORTName,u8 PinNum,u8 *val){

    /*PORTName is a character that point to the PORT {'A','B','C','D','E','F'}
     * PinNum is from 0 to 7
     * pointer val point to the address of variable to return the reading of pin
     */

    if((SYSCTL_RCGCGPIO_R&(1<<(PORTName-'A'))) == 0){      //ASCII of char - ASCII of A = number of port
        return Nok;
    }
    switch (PORTName){
           case 'A':
               *val = (((~GPIO_PORTA_DIR_R)&(1<<PinNum))&GPIO_PORTA_DATA_R)>>PinNum;
               return Ok;

           case 'B':
               *val = (((~GPIO_PORTB_DIR_R)&(1<<PinNum))&GPIO_PORTB_DATA_R)>>PinNum;
               return Ok;

           case 'C':
               *val = (((~GPIO_PORTC_DIR_R)&(1<<PinNum))&GPIO_PORTC_DATA_R)>>PinNum;
               return Ok;

           case 'D':
               *val = (((~GPIO_PORTD_DIR_R)&(1<<PinNum))&GPIO_PORTD_DATA_R)>>PinNum;
               return Ok;

           case 'E':
               *val = (((~GPIO_PORTE_DIR_R)&(1<<PinNum))&GPIO_PORTE_DATA_R)>>PinNum;
               return Ok;

           case 'F':
               *val = (((~GPIO_PORTF_DIR_R)&(1<<PinNum))&GPIO_PORTF_DATA_R)>>PinNum;
               return Ok;

           default:
               return Nok;
       }
}
Status GPIO_sWritePin(u8 PORTName,u8 PinNum,u8 val){
    /*PORTName is a character that point to the PORT {'A','B','C','D','E','F'}
     * PinNum is from 0 to 7
     *\val is logic 1 or logic 0
     */

    if((SYSCTL_RCGCGPIO_R&(1<<(PORTName-'A'))) == 0){      //ASCII of char - ASCII of A = number of port
        return Nok;
    }
    switch (PORTName){
           case 'A':
               if(val){
                   GPIO_PORTA_DATA_R |= (1<<PinNum);
               }
               else{
                   GPIO_PORTA_DATA_R &= ~(1<<PinNum);
               }
               return Ok;

           case 'B':
               if(val){
                  GPIO_PORTB_DATA_R |= (1<<PinNum);
               }
               else{
                  GPIO_PORTB_DATA_R &= ~(1<<PinNum);
               }
               return Ok;

           case 'C':
               if(val){
                  GPIO_PORTC_DATA_R |= (1<<PinNum);
               }
               else{
                  GPIO_PORTC_DATA_R &= ~(1<<PinNum);
               }
               return Ok;

           case 'D':
               if(val){
                  GPIO_PORTD_DATA_R |= (1<<PinNum);
               }
               else{
                  GPIO_PORTD_DATA_R &= ~(1<<PinNum);
               }
               return Ok;

           case 'E':
               if(val){
                  GPIO_PORTE_DATA_R |= (1<<PinNum);
               }
               else{
                  GPIO_PORTE_DATA_R &= ~(1<<PinNum);
               }
               return Ok;

           case 'F':
               if(val){
                  GPIO_PORTF_DATA_R |= (1<<PinNum);
               }
               else{
                  GPIO_PORTF_DATA_R &= ~(1<<PinNum);
               }
               return Ok;

           default:
               return Nok;
   }

}
