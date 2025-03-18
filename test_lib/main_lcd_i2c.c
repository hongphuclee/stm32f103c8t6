#include<LHP_stm32f103.h>



void main(){
  
  SysTick_Init(1);

  RCC.APB2_ENR.BIT.IOPBEN = 1;
  GPIO_Mode(&GPIOB, BIT8 | BIT9, output_push_pull_10Mhz);
  SDA(1);
  SCL(1);
  
  LCD_Init();
  
  
  delay(1);
  
    
  while(1){
    LCD_Writes("Le Hong Phuc", sizeof("Le Hong Phuc") - 1);
    delay(1000);
    LCD_Clear();
    LCD_Writes("hihi", sizeof("hihi") - 1);  
    delay(1000);
    LCD_Clear();
  }
}