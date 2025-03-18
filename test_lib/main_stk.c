#include<gpio.h>
#include<my_rcc.h>
#include<systick.h>
#include<bit.h>



void main(){
  
  RCC.APB2_ENR.BIT.IOPCEN = 1;
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  GPIOC.ODR.BIT.B_13 = 0;
  SysTick_Init(1);
  while(1){
    GPIOC.ODR.BIT.B_13 = !GPIOC.ODR.BIT.B_13;
    delay(200);
  }
}