#include<uart.h>
#include<LHP_stm32f103.h>
void UART1_Init(){
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  RCC.APB2_ENR.BIT.USART1EN = 1;
  
  //USART1_TX = PA9, USART1_RX = PA10;
  GPIOA.ODR.REG = BIT10;
  GPIO_Mode(&GPIOA, BIT10, input_push_pull);
  GPIO_Mode(&GPIOA, BIT9, af_output_push_pull_10Mhz);
  
  //BASE CLOCK = 8Mhz, baudrate = 9600 = 8Mhz/(16*MANTISSA = 52, FRACTION ~ 1); 
  UART1.BRR.REG = (52UL << 4) | 1;
  UART1.CR1.REG = BIT13 | BIT5 | BIT3 | BIT2;
  NVIC.NVIC_SER1.BIT.USART1 = 1;
}

void UART_Write(UART_Typedef* UART, unsigned char Data){
  UART->DR = Data;
  while (!UART->SR.BIT.TC);
  UART->SR.BIT.TC = 0;
  for(int i = 0; i < 10000; i++);
}

void UART_Writes(UART_Typedef* UART, const unsigned char* Data, unsigned Size){
  for(unsigned char i = 0; i < Size; i++){
    UART_Write(UART, Data[i]);
  }
}