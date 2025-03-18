#include<gpio.h>
#include<rcc.h>

int ma_led[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned short int dem = 0;

void main(){
  RCC.APB2ENR.BIT.IOPAEN = 1;
  RCC.APB2ENR.BIT.IOPBEN = 1;
  RCC.APB2ENR.BIT.IOPCEN = 1;
  for(unsigned int i = 0; i < 15; i ++){
    GPIO_Mode(&GPIOA, 1UL << i, output_push_pull_10Mhz);
  }
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  GPIOC.ODR.BIT.B_13 = 0;
  while(1){
   GPIOA.ODR.REG = ma_led[dem++];
   for(unsigned long int i = 0; i < 2000000; i++){
   };
   if(dem == 10) dem = 0;
  }
}