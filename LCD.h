//#ifndef LCD
//#define LCD
//#include <xc.h>
//#define _XTAL_FREQ 4000000
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <pic16f887.h>
//
//#define RS PORTEbits.RE0
//#define EN  PORTEbits.RE1
//#define TRISRS  TRISEbits.TRISE0
//#define TRISEN  TRISEbits.TRISE1
//#define PUERTOTRS  TRISB
//#define PUERTO PORTB
//
//void lcd_init();
//void lcd_control(uint8_t dato);
//void lcd_dato(uint8_t dato);
//void lcd_clear_display();
//void lcd_cursor_home();
//void lcd_print(char *dato);
////void lcd_print_with_position(int, int, char*);
//void lcd_goto(char x, char y);
////void lcd_put_caracter(char, char[]);
//
//
//#endif

#ifndef LCD
#define	LCD

#include <xc.h> 
void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init(void);
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();
void Lcd_Clear(void);
#endif	/* XC_HEADER_TEMPLATE_H */
