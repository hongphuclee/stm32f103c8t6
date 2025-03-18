#include<LHP_stm32f103.h>

void main(){
  SysTick_Init(1);
  UART1_Init();
  
  
  while(1){
    UART_Writes(&UART1 ,"LEHONGPHUC", 10);
    delay(60);
  }
  
}