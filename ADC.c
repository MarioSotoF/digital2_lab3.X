#include "ADC.h"
#include <pic16f887.h>
#include <stdint.h>
/* 
 * Author: mario
 * 
 * 
 * 
 * 
 */
//Iniciar Condiciones para generar la Interrupcion
#define _XTAL_FREQ 8000000


void ADC(uint8_t encenderADC, uint8_t justificadoADC){
    
    
    if (encenderADC == 1){
        if (justificadoADC == 1){
            
//            ADCON0bits.ADON = 1;
            ADCON1bits.ADFM = 0;
//            ADCON1bits.VCFG0 = 0;
//            ADCON1bits.VCFG1 = 0;
            ANSELbits.ANS0 = 1;
            ANSELbits.ANS1 = 1;
            TRISAbits.TRISA0 = 1;
            TRISAbits.TRISA1 = 1;
            PIE1bits.ADIE = 1;
            PIR1bits.ADIF = 0;     
            INTCON = 0b11101000;//Duda
        }
    }
}

    
uint8_t TURNOS (uint8_t bandera, uint8_t pot1, uint8_t pot2, uint8_t turno){
    if (bandera == 1 && turno == 1){
        ADCON0 = 0b01000001;
        __delay_us(25);
        bandera=0;
        ADCON0bits.GO = 1;
    }
    else if (bandera == 1 && turno == 2){
        ADCON0 = 0b01000101;
        __delay_us(25);
        bandera=0;
        ADCON0bits.GO = 1;
    }
    return(0);
}