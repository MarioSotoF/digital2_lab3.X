//#include <xc.h>
//#define _XTAL_FREQ 4000000
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <pic16f887.h>
//#include "LCD.h"
//
//
//#define RS PORTEbits.RE0
//#define EN  PORTEbits.RE1
//#define TRISRS  TRISEbits.TRISE0
//#define TRISEN  TRISEbits.TRISE1
//#define PUERTOTRS  TRISB
//#define PUERTO PORTB
//
//void lcd_control(uint8_t dato){
//    RS = 0;
//    PUERTO = dato; 
//    EN = 1;
//    __delay_us(5);
//    EN = 0;
//    __delay_us(5);
//    __delay_ms(2);
//    
//}
//void lcd_init(){
////    TRISRS = 0; //RS como salida
////    TRISEN = 0; //configuro E como salida
////    PUERTOTRS = 0b00000000;//condiguro el nibble mas significativo como salida
////    RS = 0; //rs en 0
////    EN = 0; //E en 0
////    PUERTO = 0; //en 0
////    
////    __delay_ms(50);//tiempo de espera de puertos
////    lcd_control(0x02);// Cursor al inicio
////    lcd_control(0x38);//Configuracion a 8 bits, 2 lineas y fuente de 5*8(function set)
////    lcd_control(0x0C);//LCD encendido, Cursor apagado
////    lcd_control(0x06);//no rota el mensaje y se incrementa el contador de dirección
//    
//    
//    
//}
//
//
//
//void lcd_dato(uint8_t dato){
//    RS = 1;//estoy mandando datos
//    PUERTO = dato;
//    EN = 1;
//    __delay_us(5);
//    EN = 0;
//    __delay_us(5);
//    __delay_us(50);
//}
//
//void lcd_clear_display(){
//    lcd_control(0x01);
//    __delay_ms(2);
//}
//void lcd_cursor_home(){
//    lcd_control(0x02);
//    __delay_ms(2);
//}
//void lcd_print(char *dato){
//    while(*dato){
//        lcd_dato(*dato);
//        dato++;
//    }
//}/*
//void lcd_print_with_position(int x, int y, char *dato){
//    char posicion;
//    switch(y){
//        case 1: posicion = 0x80 + x;
//        break;
//        case 2: posicion = 0xC0 + x;
//        break;
//        default: posicion = 0x80 + x;
//        break;
//      
//    }
//    lcd_control(posicion);
//    lcd_print(dato);
//}*/
//void lcd_goto(char x, char y){
//    char posicion;
//    switch(y){
//        case 1:  posicion = 0x80 + x;
//        break;
//        case 2:  posicion = 0xC0 + x;
//        break;
//        default: posicion = 0x80 + x;
//        break;   
//    }
//    lcd_control(posicion);
//}
///*
//void lcd_put_caracter(char adress, char caracter[]){
//    int i;
//    lcd_control(0x40 + (adress * 8));
//    for(i = 0; i<8; i++){
//        lcd_dato(caracter[i]);
//    }
//}*/



#include<stdint.h>
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RS PORTEbits.RE0
#define EN PORTEbits.RE1


void Lcd_Port(char a) {
    PORTD = a; 
}

void Lcd_Cmd(char a) {
    RS = 0; 
    Lcd_Port(a);
    EN = 1; 
    __delay_ms(4);
    EN = 0; 

void Lcd_Clear(void) {
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b) {
    char temp;
    if (a == 1) {
        temp = 0x80 + b - 1; 
        Lcd_Cmd(temp);
    } else if (a == 2) {
        temp = 0xC0 + b - 1;
        Lcd_Cmd(temp);
    }
}

void Lcd_Init(void) {
    Lcd_Port(0x00);
    __delay_ms(20);
    Lcd_Cmd(0x3F); 
    __delay_ms(10);
    Lcd_Cmd(0x3F);
    __delay_us(200);
    Lcd_Cmd(0x3F);
    /////////////////////////////////////////////////////
    Lcd_Cmd(0x38);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x06);
}

void Lcd_Write_Char(char a) {
    RS = 1; 
    Lcd_Port(a); 
    EN = 1;
    __delay_us(40); 
    EN = 0;
    __delay_us(40);
}

void Lcd_Write_String(char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++) 
        Lcd_Write_Char(a[i]);
}
