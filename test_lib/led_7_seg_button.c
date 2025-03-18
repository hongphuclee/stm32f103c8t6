#include<gpio.h>
#include<rcc.h>

int ma_led[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int dem = 0;

void main(){
  
  RCC.APB2ENR.BIT.IOPAEN = 1;
  RCC.APB2ENR.BIT.IOPBEN = 1;
  RCC.APB2ENR.BIT.IOPCEN = 1;
  for(unsigned int i = 0; i < 15; i ++){
    GPIO_Mode(&GPIOA, 1UL << i, output_push_pull_10Mhz);
  }
  GPIO_Mode(&GPIOC, 1UL << 13, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 12, input_push_pull);
  GPIO_Mode(&GPIOB, 1UL << 13, input_push_pull);
  GPIOC.ODR.BIT.B_13 = 0;
  GPIOB.ODR.BIT.B_12 = 1;
  GPIOB.ODR.BIT.B_13 = 1;
  
  while(1){
    GPIOA.ODR.REG = ma_led[dem];
    if(GPIOB.IDR.BIT.B_12 == 0){
      for(int i = 0; i < 50000; i++){};
      if(GPIOB.IDR.BIT.B_12 == 0) dem --;
      if(dem == 10) dem = 0;
      if(dem == -1) dem = 9;
      GPIOA.ODR.REG = ma_led[dem];
      while(GPIOB.IDR.BIT.B_12 == 0){}
    }
   if(GPIOB.IDR.BIT.B_13 == 0){
      for(int i = 0; i < 50000; i++){};
      if(GPIOB.IDR.BIT.B_13 == 0) dem ++;
      if(dem == 10) dem = 0;
      if(dem == -1) dem = 9;
      GPIOA.ODR.REG = ma_led[dem];
      while(GPIOB.IDR.BIT.B_13 == 0){}
    }
   
  }
}