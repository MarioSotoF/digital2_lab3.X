// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)



// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
/*
 * File:   main.c
 * Author: mario
 *
 * Created on 8 de febrero de 2021, 09:37 AM
 */




//#define RS RD2
//#define EN RD3
//#define C0 RC0
//#define C1 RC1
//#define C2 RC2
//#define C3 RC3
//#define C4 RC4
//#define C5 RC5
//#define C6 RC6
//#define C7 RC7

void main(void) {
    unsigned int a;
    setup();
    //TRISC = 0x00;
    //TRISD = 0x00;
    Lcd_Init();
    while (1) {

        Lcd_Clear();
        //        if (PORTCbits.RC7 == 0) {
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String("Hola Mundo");
        //        }
        //        if (PORTCbits.RC7 == 0) {
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_String("Adios Mundo");
        __delay_ms(2000);
        Lcd_Clear();
        //        }
        //        if (PORTCbits.RC7 == 0) {
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String("Developed By");
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_String("electroSome");
        __delay_ms(2000);
        Lcd_Clear();
        //        }


        //        Lcd_Set_Cursor(1, 1);
        //        Lcd_Write_String("www.electroSome.com");

        for (a = 0; a < 15; a++) {
            __delay_ms(300);
            Lcd_Shift_Left();
        }

        for (a = 0; a < 15; a++) {
            __delay_ms(300);
            Lcd_Shift_Right();
        }

        Lcd_Clear();
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_Char('M');
        Lcd_Write_Char('S');
        __delay_ms(2000);
    }
}
void setup(void){
    
    
    
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0;
    PORTA = 0;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    PORTC = 0;
    PORTD = 0;
    PORTA = 0;
}
