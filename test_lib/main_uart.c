#include<LHP_stm32f103.h>

struct{
  unsigned char TX_Size;
  unsigned char RX_Size;
  unsigned char Timeout;
  unsigned char TXTrig;
  unsigned char Buffer[32];
} UART1_RX = {
  .TX_Size = 0,
  .RX_Size = 0,
  .Timeout =0,
  .TXTrig = 0,
},
UART2_RX = {
  .TX_Size = 0,
  .RX_Size = 0,
  .Timeout =0,
  .TXTrig = 0,
};


void HardFault_Handler(){
  return;
}

unsigned char MsTick = 0;

void TIM1_UP_IRQHandler(){
  MsTick = 1;
}


void UART1_IRQHandler(){
  unsigned char data = UART1.DR;
  if(UART1_RX.RX_Size < 32){
    UART1_RX.Buffer[UART1_RX.RX_Size] = data;
    UART1_RX.RX_Size++;
    UART1_RX.TX_Size = UART1_RX.RX_Size;
  }
  UART1.SR.BIT.RXNE = 0;
  UART1_RX.Timeout = 1;
}

void UART2_IRQHandler(){
  unsigned char data = UART2.DR;
  if(UART2_RX.RX_Size < 32){
    UART2_RX.Buffer[UART2_RX.RX_Size] = data;
    UART2_RX.RX_Size++;
    UART2_RX.TX_Size = UART2_RX.RX_Size;
  }
  UART2.SR.BIT.RXNE = 0;
  UART2_RX.Timeout = 1;
}

void main(){
  
  //USART1_TX = PA9, USART1_RX = PA10;
  //USART2_TX = PA2, USART2_RX = PA3;
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  GPIOA.ODR.REG = BIT3 | BIT10;
  GPIO_Mode(&GPIOA, BIT3 | BIT10, input_push_pull);
  GPIO_Mode(&GPIOA, BIT2 | BIT9, af_output_push_pull_10Mhz);
    
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  RCC.APB2_ENR.BIT.USART1EN = 1;
  RCC.APB1_ENR.BIT.UART2EN = 1;
  
  //BASE CLOCK = 8Mhz, baudrate = 9600 = 8Mhz/(16*MANTISSA = 52, FRACTION ~ 1); 
  UART1.BRR.REG = (52UL << 4) | 1;
  UART1.CR1.REG = BIT13 | BIT5 | BIT3 | BIT2;
  NVIC.NVIC_SER1.BIT.USART1 = 1;
  
  UART2.BRR.REG = (52UL << 4) | 1;
  UART2.CR1.REG = BIT13 | BIT5 | BIT3 | BIT2;
  NVIC.NVIC_SER1.BIT.USART2 = 1;
  
  Timer1_Init(&Timer1, 2);
  
  UART_Writes(&UART1, "ABCD", 4);
  while(1){
    
    if(MsTick){
      
      if(UART1_RX.Timeout && UART1_RX.Timeout < 10){
        UART1_RX.Timeout ++;
      }
      
      if(UART2_RX.Timeout && UART2_RX.Timeout < 10){
        UART2_RX.Timeout ++;
      }
      
      if(UART1_RX.TXTrig){
        UART1_RX.TXTrig --;
        if(UART1_RX.TXTrig == 0){
          for(unsigned char i = 0; i < UART1_RX.TX_Size; i ++){
            UART1_RX.Buffer[i]++;
          }
          UART_Writes(&UART1, UART1_RX.Buffer, UART1_RX.TX_Size);
        }
      }
      
      if(UART2_RX.TXTrig){
        UART2_RX.TXTrig --;
        if(UART2_RX.TXTrig == 0){
          for(unsigned char i = 0; i < UART2_RX.TX_Size; i ++){
            UART2_RX.Buffer[i]++;
          }
          UART_Writes(&UART2, UART2_RX.Buffer, UART2_RX.TX_Size);
        }
      }
      
      MsTick = 0;
    }
    
    if(UART1_RX.Timeout == 10){
      UART1_RX.TXTrig = 60;
      UART1_RX.Timeout = 0;
      UART1_RX.RX_Size = 0;
    }
    
    if(UART2_RX.Timeout == 10){
      UART2_RX.TXTrig = 60;
      UART2_RX.Timeout = 0;
      UART2_RX.RX_Size = 0;
    }
    
  }
}