#include<gpio.h>
#include<rcc.h>
__root unsigned char xx ;
void main()
{

  RCC.APB2ENR.BIT.IOPBEN = 1;
  RCC.APB2ENR.BIT.IOPCEN = 1;
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 12, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 13, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 14, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 15, input_push_pull);
  GPIO_Mode(&GPIOC, 1UL << 15, input_push_pull);
  GPIOC.ODR.BIT.B_13 = 0;
  GPIOB.ODR.BIT.B_15 = 1;
  GPIOC.ODR.BIT.B_15 = 1;
  while(1)
  { 
    
    if(GPIOB.IDR.BIT.B_15 == 0){
      for(unsigned int i = 0; i < 6000; i++){};
      if(GPIOB.IDR.BIT.B_15 == 0){
        GPIOB.ODR.BIT.B_13 = 1;
      }
      xx = 1;
      while(GPIOB.IDR.BIT.B_15 == 0);
    }
    
  }
}