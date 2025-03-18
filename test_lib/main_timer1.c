#include<LHP_stm32f103.h>

unsigned char MsTick = 0;
void TIM1_UP_IRQHandler(){
  MsTick = 1;
  Timer1.SR.REG = 0;
}
unsigned time = 0;
void main(){ 
  
  RCC.APB2_ENR.BIT.IOPCEN = 1;
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  Timer1_Init(&Timer1, 5);
  while(1){
    if(MsTick){
      GPIOC.ODR.BIT.B_13 = !GPIOC.ODR.BIT.B_13;
      MsTick = 0;
    }
  }
}