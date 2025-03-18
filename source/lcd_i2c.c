#include<lcd_i2c.h>
#include<LHP_stm32f103.h>

void LCD_Init(){
  delay(15);
  
  I2C_Write(0x27, 0, 0x08);
  delay(1000);
  
  I2C_Write(0x27, 0, 0x38);
  I2C_Write(0x27, 0, 0x3C);
  I2C_Write(0x27, 0, 0x38);
  delay(5);
  
  I2C_Write(0x27, 0, 0x38);
  I2C_Write(0x27, 0, 0x3C);
  I2C_Write(0x27, 0, 0x38);
  delay(1);
  
  I2C_Write(0x27, 0, 0x38);
  I2C_Write(0x27, 0, 0x3C);
  I2C_Write(0x27, 0, 0x38);
  delay(1);
  
  I2C_Write(0x27, 0, 0x28);
  I2C_Write(0x27, 0, 0x2C);
  I2C_Write(0x27, 0, 0x28);
  delay(1);
  
  I2C_Write(0x27, 0, 0x28);
  I2C_Write(0x27, 0, 0x2C);
  I2C_Write(0x27, 0, 0x28);
  delay(1);
  I2C_Write(0x27, 0, 0x88);
  I2C_Write(0x27, 0, 0x8C);
  I2C_Write(0x27, 0, 0x88);
  delay(1);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0xC8);
  I2C_Write(0x27, 0, 0xCC);
  I2C_Write(0x27, 0, 0xC8);
  delay(1);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0x18);
  I2C_Write(0x27, 0, 0x1C);
  I2C_Write(0x27, 0, 0x18);
  delay(2);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0x6B);
  I2C_Write(0x27, 0, 0x6C);
  I2C_Write(0x27, 0, 0x68);
  delay(1);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0x28);
  I2C_Write(0x27, 0, 0x2C);
  I2C_Write(0x27, 0, 0x28);
  delay(1);
}

void LCD_Write(unsigned char Data){
  I2C_Write(0x27, 0, (Data & 0xF0) | 0x09); // transmit 4 high bits
  I2C_Write(0x27, 0, (Data & 0xF0) | 0x0D);
  I2C_Write(0x27, 0, (Data & 0xF0) | 0x09);
  
  I2C_Write(0x27, 0, (Data << 4) | 0x09) ; // transmit 4 low bits;
  I2C_Write(0x27, 0, (Data << 4) | 0x0D) ;
  I2C_Write(0x27, 0, (Data << 4) | 0x09) ;
};

void LCD_Writes(const unsigned char* Data, unsigned char Size){
  
  for(unsigned char i = 0; i < Size; i++){
    LCD_Write(Data[i]); 
  }
}

void LCD_Write_Command(unsigned char Command){
  I2C_Write(0x27, 0, (Command & 0xF0) | 0x08); // transmit 4 high bits
  I2C_Write(0x27, 0, (Command & 0xF0) | 0x0C);
  I2C_Write(0x27, 0, (Command & 0xF0) | 0x08);
  
  I2C_Write(0x27, 0, (Command << 4) | 0x08) ; // transmit 4 low bits;
  I2C_Write(0x27, 0, (Command << 4) | 0x0C) ;
  I2C_Write(0x27, 0, (Command << 4) | 0x08) ;
}

void LCD_Index(unsigned char Hang, unsigned char Cot){
  unsigned char DDRAM_Adress = 0x80;
  unsigned char Index = 0;
  if (Hang == 1){
    Index = DDRAM_Adress | (0x00 | (Cot - 1));
  }
  if (Hang == 2){
    Index = DDRAM_Adress | (0x40 | (Cot - 1));
  }
  LCD_Write_Command(Index);
}

void LCD_Clear(){
  LCD_Write_Command(0x01);
}