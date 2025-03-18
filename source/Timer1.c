#include<timer1.h>
#include<LHP_stm32f103.h>
void Timer1_Init(Timer1_Typedef* Timer1, unsigned char Time){
  RCC.APB2_ENR.BIT.TM1EN = 1;
  Timer1->ARR = Time * 8000;
  Timer1->DIER.REG = BIT0;
  Timer1->CR2.REG = 0;
  
  Timer1->CR1.REG = BIT7 | BIT2 | BIT0;
  *((unsigned long*) 0xE000E100) = BIT25; 
}