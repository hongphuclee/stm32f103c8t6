#include<LHP_stm32f103.h>

unsigned char truyen[10], nhan[10], size_truyen = 0, size_nhan = 0;

void UART1_IRQHandler(){
  unsigned data = UART1.DR;
  nhan[size_nhan] = data;
  size_nhan++;
  if(size_nhan == 10) size_nhan = 0;
}

void main(){
  
  UART1_Init();
  
  while(1){
    UART_Writes(&UART1, "ABCD", 4);
    for(int i = 0; i < 100000; i++);
  }
}