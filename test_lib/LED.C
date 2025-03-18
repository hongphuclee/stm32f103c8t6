#include<gpio.h>
#include<rcc.h>

void main()
{
  RCC.APB2ENR.BIT.IOPBEN = 1;
  RCC.APB2ENR.BIT.IOPCEN = 1;
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 12, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 13, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 14, output_push_pull_10Mhz);
  GPIOC.ODR.BIT.B_13 = 0;
  GPIOB.ODR.BIT.B_12 = 1;
  while(1)
  {
//    GPIOB.ODR.BIT.B_12 = 1;
//    GPIOB.ODR.BIT.B_13 = 0;
//    GPIOB.ODR.BIT.B_14 = 0;
//    for(unsigned long i = 0; i < 3333333; i++){};
//    
//    GPIOB.ODR.BIT.B_12 = 0;
//    GPIOB.ODR.BIT.B_13 = 1;
//    GPIOB.ODR.BIT.B_14 = 0;
//    for(unsigned long i = 0; i < 3333333; i++){};
//    
//    GPIOB.ODR.BIT.B_12 = 0;
//    GPIOB.ODR.BIT.B_13 = 0;
//    GPIOB.ODR.BIT.B_14 = 1;
//    for(unsigned long i = 0; i < 3333333; i++){};
  }
}