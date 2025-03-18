#include<LHP_stm32f03.h>

void UART_Write(UART_Typedef* UART, unsigned char Data){
  UART->DR = Data;
  while(!UART->SR.BIT.TC);
  UART->SR.BIT.TC = 0;
  for(int i = 0; i < 10000; i++);
}

void UART_Writes(UART_Typedef* UART, const unsigned char* Data, unsigned char Size){
  for(unsigned char i = 0; i < Size; i++){
    UART_Write(UART, Data[i]);
  }
}

unsigned char MsTick = 0;
void SysTick_Handler(){
  MsTick = 2;
}

struct UART_Rx{
  unsigned char Buffer[32];
  unsigned char Rx_Size;
  unsigned char Tx_Size;
  unsigned char Timeout;
  unsigned char Tx_Trigger;
} UART1_Rx = {
  .Rx_Size = 0,
  .Tx_Size = 0,
  .Timeout = 0,
  .Tx_Trigger = 60
},
UART2_Rx = {
  .Rx_Size = 0,
  .Tx_Size = 0,
  .Timeout = 0,
  .Tx_Trigger = 60
};

void UART1_IRQHandler(){
  unsigned data = UART1.DR;
  if(UART1_Rx.Rx_Size < 32){
    UART1_Rx.Buffer[UART1_Rx.Rx_Size] = data;
    UART1_Rx.Rx_Size ++;
    UART1_Rx.Tx_Size = UART1_Rx.Rx_Size;
    UART1_Rx.Timeout = 1;
  }
}

void UART2_IRQHandler(){
  unsigned data = UART2.DR;
  if(UART2_Rx.Rx_Size < 32){
    UART2_Rx.Buffer[UART2_Rx.Rx_Size] = data;
    UART2_Rx.Rx_Size ++;
    UART2_Rx.Tx_Size = UART2_Rx.Rx_Size;
    UART2_Rx.Timeout = 1;
  }
}


void main(){
  
  RCC.APB2_ENR.BIT.USART1EN = 1;
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  RCC.APB1_ENR.BIT.UART2EN = 1;
  
  //TX1=PA9, RX1=PA10, TX2=PA2,  RX2=PA3;
  
  GPIOA.ODR.REG = BIT3 | BIT10;
  GPIO_Mode(&GPIOA, BIT3 | BIT10, input_push_pull);
  GPIO_Mode(&GPIOA, BIT2 | BIT9, af_output_push_pull_10Mhz);
  
  systick_delay(2);
  
  UART1.BRR.REG = 52 << 4 | 1;
  UART1.CR1.REG = BIT13 | BIT5 | BIT3 | BIT2;
  
  UART2.BRR.REG = 52 << 4 | 1;
  UART2.CR1.REG = BIT13 | BIT5 | BIT3 | BIT2;
  
  NVIC.NVIC_SER1.BIT.USART1 = 1;
  NVIC.NVIC_SER1.BIT.USART2 = 1;
  
  UART_Writes(&UART1, "ABCD", 4);
  
  while(1) {
    
    if(MsTick){
      if(UART1_Rx.Timeout &&  UART1_Rx.Timeout < 10){
        UART1_Rx.Timeout++;
      }
      
      if(UART2_Rx.Timeout &&  UART2_Rx.Timeout < 10){
        UART2_Rx.Timeout++;
      }
      
      if(UART1_Rx.Tx_Trigger){
        UART1_Rx.Tx_Trigger--;
        if(!UART1_Rx.Tx_Trigger){
          for(unsigned char i = 0; i < UART1_Rx.Tx_Size; i++){
            UART1_Rx.Buffer[i]++;
          }
          UART_Writes(&UART1, UART1_Rx.Buffer, UART1_Rx.Tx_Size);
        }
      }
      
      if(UART2_Rx.Tx_Trigger){
        UART2_Rx.Tx_Trigger--;
        if(!UART2_Rx.Tx_Trigger){
          for(unsigned char i = 0; i < UART2_Rx.Tx_Size; i++){
            UART2_Rx.Buffer[i]++;
          }
          UART_Writes(&UART2, UART2_Rx.Buffer, UART2_Rx.Tx_Size);
        }
      }
      
      MsTick = 0;
    }
    
    if(UART1_Rx.Timeout == 10){
      UART1_Rx.Tx_Trigger = 60;
      UART1_Rx.Rx_Size = 0;
      UART1_Rx.Timeout = 0;
    }
    
    if(UART2_Rx.Timeout == 10){
      UART2_Rx.Tx_Trigger = 60;
      UART2_Rx.Rx_Size = 0;
      UART2_Rx.Timeout = 0;
    }
  }
}




void I2C_Start(){
  SDA(0);
  SCL(0);
}

  void I2C_Write_Byte(unsigned char Data){
    
    I2C_Write_Byte((Address << 1) | Command);
    I2C_Write_Byte(Data);
    
    SDA(Data & 0x80);
    SCL(1); SCL(0);
    
    SDA(Data & 0x40);
    SCL(1); SCL(0);
    
    SDA(Data & 0x20);
    SCL(1); SCL(0);
    
    SDA(Data & 0x10);
    SCL(1); SCL(0);
    
    SDA(Data & 0x08);
    SCL(1); SCL(0);
    
    SDA(Data & 0x04);
    SCL(1); SCL(0);
    
    SDA(Data & 0x02);
    SCL(1); SCL(0);
    
    SDA(Data & 0x01);
    SCL(1); SCL(0);
    
    SDA(1);
    SCL(1) ;SCL(0);
  }

void I2C_Stop(){
  SDA(0);
  SCL(1);
  SDA(1);
}

void LCD_Init(){
  delay(15);
  
  I2C_Write(0x27, 0, 0x08);
  delay(1000);
  
  I2C_Write(0x27, 0, 0x38);
  I2C_Write(0x27, 0, 0x3C);
  I2C_Write(0x27, 0, 0x38);
  delay(5);
  
  I2C_Write(0x27, 0, 0x38);
  I2C_Write(0x27, 0, 0x3C);
  I2C_Write(0x27, 0, 0x38);
  delay(1);
  
  I2C_Write(0x27, 0, 0x38);
  I2C_Write(0x27, 0, 0x3C);
  I2C_Write(0x27, 0, 0x38);
  delay(1);
  
  I2C_Write(0x27, 0, 0x28);
  I2C_Write(0x27, 0, 0x2C);
  I2C_Write(0x27, 0, 0x28);
  delay(1);
  
  I2C_Write(0x27, 0, 0x28);
  I2C_Write(0x27, 0, 0x2C);
  I2C_Write(0x27, 0, 0x28);
  delay(1);
  I2C_Write(0x27, 0, 0x88);
  I2C_Write(0x27, 0, 0x8C);
  I2C_Write(0x27, 0, 0x88);
  delay(1);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0xC8);
  I2C_Write(0x27, 0, 0xCC);
  I2C_Write(0x27, 0, 0xC8);
  delay(1);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0x18);
  I2C_Write(0x27, 0, 0x1C);
  I2C_Write(0x27, 0, 0x18);
  delay(2);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0x6B);
  I2C_Write(0x27, 0, 0x6C);
  I2C_Write(0x27, 0, 0x68);
  delay(1);
  
  I2C_Write(0x27, 0, 0x08);
  I2C_Write(0x27, 0, 0x0C);
  I2C_Write(0x27, 0, 0x08);
  delay(1);
  I2C_Write(0x27, 0, 0x28);
  I2C_Write(0x27, 0, 0x2C);
  I2C_Write(0x27, 0, 0x28);
  delay(1);
}


void LCD_Write(unsigned char Data){
  
  // transmit 4 high bits
  I2C_Write(0x27, 0, (Data & 0xF0) | 0x09); 
  I2C_Write(0x27, 0, (Data & 0xF0) | 0x0D);
  I2C_Write(0x27, 0, (Data & 0xF0) | 0x09);
  
  // transmit 4 low bits;
  I2C_Write(0x27, 0, (Data << 4) | 0x09) ; 
  I2C_Write(0x27, 0, (Data << 4) | 0x0D) ;
  I2C_Write(0x27, 0, (Data << 4) | 0x09) ;
};



void UART1_Init(){
  
  //Clock enable
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  RCC.APB2_ENR.BIT.USART1EN = 1;
  
  //USART1_TX = PA9, USART1_RX = PA10;
  GPIOA.ODR.REG = BIT10;
  GPIO_Mode(&GPIOA, BIT10, input_push_pull);
  GPIO_Mode(&GPIOA, BIT9, af_output_push_pull_10Mhz);
  
  //BASE CLOCK = 8Mhz
  //baudrate = 9600 = 8Mhz/(16*MANTISSA = 52, FRACTION ~ 1); 
  UART1.BRR.REG = (52UL << 4) | 1;
  
  //CONFIG CR1
  UART1.CR1.BIT.TE = 1;
  UART1.CR1.BIT.RE = 1;
  UART1.CR1.BIT.RXNEIE = 1;
  UART1.CR1.BIT.UE = 1;
  
  NVIC.NVIC_SER1.BIT.USART1 = 1;
}

void UART_Write(UART_Typedef* UART, unsigned char Data){
  UART->DR = Data;
  while (!UART->SR.BIT.TC);
  UART->SR.BIT.TC = 0;
  for(int i = 0; i < 10000; i++);
}




void RS485_Writes(unsigned char Address_Tran,
                  unsigned char Address_Re,
                  unsigned char* Data,
                  unsigned char Size_Data
                  unsigned char Command ){
                    
  unsigned char Buffer_Tran[Size_Data + 4];
  
  // dia chi
  Buffer_Tran[0] = Address_Re;
  Buffer_Tran[1] = Address_Tran;
  
  //lenh
  if(Command == 1){
    Buffer_Tran[2] = 0b11110000;  //doc
  }
  else{
    Buffer_Tran[2] = 0b00001111;  //ghi
  }
  
  //du lieu
  for(int i = 0 ; i < Size_Data; i++){
    Buffer_Tran[i + 3] = Data[i];
  }
  
  //byte dung
  Buffer_Tran[Size_Data + 3] = 0b11111111;
  
  for(int i = 0; i < sizeof(Buffer_Tran), i++){
    UART_Write(UART1, Buffer_Tran[i]);
  }
}

unsigned char i = 0, Buffer_Receive[256];
#define Address = 0x06

void UART1_IRQHandler(){  
  unsigned data = UART1.DR;
  Buffer_Receive[i] = data;
  
  if(Buffer_Receive[i] == 0b11111111){ 
    if(Buffer_Receive[0] == Address){
      if(Buffer_Receive[2] = 11110000){ //doc
        Data_Encoded_Typedef Data6[4];
        for(int j=0; j<4; j++){
          Data6[4] = Encode_Hamming(ky_vong>>(8*j));
        }
        for(int j=0; j<4; j++){
          UART_Write(&UART1, Data6[j])
        }                            
      }
      
      else if(Buffer_Receive[2] = 00001111){ //ghi
        Data_Typedef Data7[i-3];
        for(int j=0; j<i-3; j++){
          Data7[j-3] = Decode(Buffer_Receive[j+3]);
          Data7[j-3] = Fix_Error(Data7[j-3], Buffer_Receive[j+3])
        }
        for(unsigned char j=0; j<i-3; j++){
          LCD_Write(Data7[j]);
        }
      }   
     }
    }
  
    else return;
  }
  else{
    Size_Receive++;
  }  
}

