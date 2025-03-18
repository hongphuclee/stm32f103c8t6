#include<my_rcc.h>
#include<my_dma.h>
#include<bit.h>

unsigned char data1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
unsigned char data2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void main(){
  
  RCC.AHB_ENR.BIT.DMA1AEN = 1;
  DMA1.channel_1.CMAR1 = (unsigned long) &data2;
  DMA1.channel_1.CPAR1 = (unsigned long) &data1;
  DMA1.channel_1.CNDTR1 = 10;
  DMA1.channel_1.CCR1.REG = BIT14 | BIT7 | BIT6 | BIT0;
  
  while(1){
    
  }
}