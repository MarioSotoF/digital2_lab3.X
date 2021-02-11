#include "adc.h"
#include <pic16f887.h>

/* 
 * Author: mario
 * 
 * 
 * 
 * 
 */
//Iniciar Condiciones para generar la Interrupcion
#define _XTAL_FREQ 8000000

//1 representa justificado a la derecha
void ADC(uint8_t encenderADC, uint8_t justificadoADC){
    
    
    if (encenderADC == 1){
        if (justificadoADC == 1){
            
            ADCON0bits.ADON = 1;
            ADCON0bits.GO_DONE = 0;
            ADCON0bits.CHS = 0b0010;
            ADCON1bits.ADFM = 1;
            ADCON1bits.VCFG0 = 0;
            ADCON1bits.VCFG1 = 0;
            ANSELbits.ANS2 = 1;
            TRISAbits.TRISA2 = 1;
            
            
            
        
        }
        
        else if(justificadoADC == 0){
            ADCON0bits.ADON = 1;
            ADCON0bits.GO_DONE = 0;
            ADCON0bits.CHS = 0b0010;
            ADCON1bits.ADFM = 0;
            ADCON1bits.VCFG0 = 0;
            ADCON1bits.VCFG1 = 0;
            ANSELbits.ANS2 = 1;
            TRISAbits.TRISA2 = 1;
            
        
        
        }
    
    }
    
    else if (encenderADC == 0){
        ADCON0 = 0;
    
    
    
   }


}

    
