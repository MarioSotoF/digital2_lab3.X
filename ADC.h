/* 
 * File: Oscilador.h  
 * Author: mario
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_h
#define	ADC_h

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
void ADC(uint8_t encenderADC, uint8_t justificadoADC);
uint8_t TURNOS (uint8_t bandera, uint8_t pot1, uint8_t pot2, uint8_t turno);

#endif	/* OSCILADOR_H */

