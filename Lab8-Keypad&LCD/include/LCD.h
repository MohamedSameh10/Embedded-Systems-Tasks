/*
 * Author : Abdullah Drwesh
 * Date   : 20/12/2021
 * Version: 1.0.0
 */
#ifndef LCD_H
#define LCD_H

/* LCD Modes */
#define LCD_8BIT_MODE 0
#define LCD_4BIT_MODE 1

/* User Input */
#define LCD_MODE LCD_8BIT_MODE

void LCD_Init(void);

void LCD_SendCommand(unsigned char Command);

void LCD_SendData(unsigned char Data);

void LCD_SetCursorAt(unsigned char x, unsigned char y);

void LCD_Print(const char * Str);


#endif /* LCD_H */
