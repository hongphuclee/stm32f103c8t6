#include<LHP_stm32f103.h>

void main()
{
    RCC.APB2_ENR.BIT.IOPCEN = 1;
//  GPIOC.CRH.BIT.Mode_13 = 3;
//  GPIOC.CRH.BIT.CNF_13 = 0;
  
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  
  //GPIOC.ODR.BIT.B_13 = 0;
  
  while(1)
  {
    GPIOC.ODR.BIT.B_13 = !GPIOC.ODR.BIT.B_13;
    for(unsigned long i = 0; i < 2086464; i++){};
  }
}