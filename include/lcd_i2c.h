#ifndef LCD_I2C_H
#define LCD_I2C_H

#include<LHP_stm32f103.h>

void LCD_Init();
void LCD_Write(unsigned char Data);
void LCD_Writes(const unsigned char* Data, unsigned char Size);
void LCD_Write_Command(unsigned char Command);
void LCD_Index(unsigned char Hang, unsigned char Cot);
void LCD_Clear();

#endif 