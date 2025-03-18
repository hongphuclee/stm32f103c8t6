#include<LHP_stm32f103.h>

unsigned char bang_ma[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
unsigned char Byte_Error[2] = {0, 0};


typedef union{
  unsigned char REG;
  struct{
    unsigned char B0 : 1;
    unsigned char B1 : 1;
    unsigned char B2 : 1;
    unsigned char B3 : 1;
    unsigned char B4 : 1;
    unsigned char B5 : 1;
    unsigned char B6 : 1;
    unsigned char B7 : 1;
  } BIT;
} Data_Typedef;
Data_Typedef Data, Data_Correct;
Data_Typedef Data_Error, DeCode_Error;

typedef union{
  unsigned short REG;
  struct{
    unsigned short B0  : 1;
    unsigned short B1  : 1;
    unsigned short B2  : 1;
    unsigned short B3  : 1;
    unsigned short B4  : 1;
    unsigned short B5  : 1;
    unsigned short B6  : 1;
    unsigned short B7  : 1;
    unsigned short B8  : 1;
    unsigned short B9  : 1;
    unsigned short B10 : 1;
    unsigned short B11 : 1;
  } BIT;
} Data_Encoded_Typedef;
Data_Encoded_Typedef Data_Encoded, Data_Rec;
Data_Encoded_Typedef Data_Encoded_Error;

Data_Encoded_Typedef Encode_Hamming(Data_Typedef Data){
  Data_Encoded_Typedef Data_Encoded;
  Data_Encoded.REG = 0;
  
  Data_Encoded.BIT.B2  = Data.BIT.B0;
  Data_Encoded.BIT.B4  = Data.BIT.B1;
  Data_Encoded.BIT.B5  = Data.BIT.B2;
  Data_Encoded.BIT.B6  = Data.BIT.B3;
  Data_Encoded.BIT.B8  = Data.BIT.B4;
  Data_Encoded.BIT.B9  = Data.BIT.B5;
  Data_Encoded.BIT.B10 = Data.BIT.B6;
  Data_Encoded.BIT.B11 = Data.BIT.B7;
  
  Data_Encoded.BIT.B0 = (Data.BIT.B0^Data.BIT.B1^Data.BIT.B3^Data.BIT.B4^Data.BIT.B6);
  Data_Encoded.BIT.B1 = (Data.BIT.B0^Data.BIT.B2^Data.BIT.B3^Data.BIT.B5^Data.BIT.B6);
  Data_Encoded.BIT.B3 = (Data.BIT.B1^Data.BIT.B2^Data.BIT.B3^Data.BIT.B7);
  Data_Encoded.BIT.B7 = (Data.BIT.B4^Data.BIT.B5^Data.BIT.B6^Data.BIT.B7);
  
  return Data_Encoded;
  
}; 

Data_Typedef Decode(Data_Encoded_Typedef Data_Encoded){
  Data_Typedef Data;
  //d1
  Data.BIT.B0 = Data_Encoded.BIT.B2;
  
  //d2
  Data.BIT.B1 = Data_Encoded.BIT.B4;
  
  //d3
  Data.BIT.B2 = Data_Encoded.BIT.B5;
  
  //d4
  Data.BIT.B3 = Data_Encoded.BIT.B6;
  
  //d5
  Data.BIT.B4 = Data_Encoded.BIT.B8;
  
  //d6
  Data.BIT.B5 = Data_Encoded.BIT.B9;
  
  //d7
  Data.BIT.B6 = Data_Encoded.BIT.B10;
  
  //d8
  Data.BIT.B7 = Data_Encoded.BIT.B11;
  return Data;
}

Data_Typedef Fix_Error(Data_Typedef Data_Error,
                       Data_Encoded_Typedef Data_Encoded ){
  Data_Typedef Data_Correct , Index_Eror ;
  
  // m1 + d1 + d2  + d4 + d8 + d10
  Index_Eror.BIT.B0 = (Data_Encoded.BIT.B0^Data_Encoded.BIT.B2
                      ^Data_Encoded.BIT.B4^Data_Encoded.BIT.B6
                      ^Data_Encoded.BIT.B8^Data_Encoded.BIT.B10);
  
  //m2 + d1 + d3 + d4 + d6 + d7
  Index_Eror.BIT.B1 = (Data_Encoded.BIT.B1^Data_Encoded.BIT.B2
                      ^Data_Encoded.BIT.B5^Data_Encoded.BIT.B6
                      ^Data_Encoded.BIT.B9^Data_Encoded.BIT.B10);
  
  //m3 + d2 + d3 + d4 + d8
  Index_Eror.BIT.B2 = (Data_Encoded.BIT.B3^Data_Encoded.BIT.B4
                      ^Data_Encoded.BIT.B5^Data_Encoded.BIT.B6
                      ^Data_Encoded.BIT.B11);
  
  //m4 + d5 + d6 + d7 + d8
  Index_Eror.BIT.B3 = (Data_Encoded.BIT.B7^Data_Encoded.BIT.B8
                      ^Data_Encoded.BIT.B9^Data_Encoded.BIT.B10
                      ^Data_Encoded.BIT.B11);

  
  
  
  unsigned Index = Index_Eror.REG;
  switch(Index) {
    case 3:  
      Data.BIT.B0 = !Data.BIT.B0; break;
    case 5: 
      Data.BIT.B1 = !Data.BIT.B1; break;
    case 6:  
      Data.BIT.B2 = !Data.BIT.B2; break;
    case 7:  
      Data.BIT.B3 = !Data.BIT.B3; break;
    case 9:  
      Data.BIT.B4 = !Data.BIT.B4; break;
    case 10: 
      Data.BIT.B5 = !Data.BIT.B5; break;
    case 11: 
      Data.BIT.B6 = !Data.BIT.B6; break;
    case 12: 
      Data.BIT.B7 = !Data.BIT.B7; break;
}
  Data_Correct = Data;
  return Data_Correct;
}


unsigned char a;
void UART1_IRQHandler(){
  a = UART1.DR;
}

unsigned char Buffer;
unsigned char Status = 0, Last_Stauts = 0;

unsigned char MsTick = 0;
void TIM1_UP_IRQHandler(){
  MsTick = 1;
  Timer1.SR.REG = 0;
}

struct{
  unsigned char colum;
  unsigned char row;
  unsigned char row_check;
} Vi_tri = {
  .colum = 0,
  .row = 0,
  .row_check = 0,
};

struct{
  unsigned char ma_truyen;
  unsigned char ma_bit;
} ma_phim = {
  .ma_truyen = 123,
  .ma_bit = 123,
};

void main(){
  UART1_Init();
  SysTick_Init(1);
  Timer1_Init(&Timer1, 8);
  
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  GPIO_Mode(&GPIOA ,BIT0 | BIT1 | BIT2 | BIT3, output_push_pull_10Mhz); // HANG(R)
  GPIO_Mode(&GPIOA ,BIT4 | BIT5 | BIT6 | BIT7, input_push_pull); // COT
  GPIOA.ODR.REG = BIT0 | BIT1| BIT2| BIT3|  BIT4 | BIT5 | BIT6 | BIT7; // INPUT PULL UP
  
  RCC.APB2_ENR.BIT.IOPBEN = 1;
  GPIO_Mode(&GPIOB, BIT8 | BIT9, output_push_pull_10Mhz);
  SDA(1);
  SCL(1);
  
  
  LCD_Init();
  LCD_Writes("Empty Data", 10);
  
  while(1){
    
    //Quet phim
    if(MsTick){
      if(Vi_tri.row_check == 0){
        GPIOA.ODR.BIT.B_0 = 0;
        GPIOA.ODR.BIT.B_1 = 1;
        GPIOA.ODR.BIT.B_2 = 1;
        GPIOA.ODR.BIT.B_3 = 1;
      }  
      if(Vi_tri.row_check == 1){
        GPIOA.ODR.BIT.B_0 = 1;
        GPIOA.ODR.BIT.B_1 = 0;
        GPIOA.ODR.BIT.B_2 = 1;
        GPIOA.ODR.BIT.B_3 = 1;
      }    
      if(Vi_tri.row_check == 2){
        GPIOA.ODR.BIT.B_0 = 1;
        GPIOA.ODR.BIT.B_1 = 1;
        GPIOA.ODR.BIT.B_2 = 0;
        GPIOA.ODR.BIT.B_3 = 1;
      }  
      if(Vi_tri.row_check == 3){
        GPIOA.ODR.BIT.B_0 = 1;
        GPIOA.ODR.BIT.B_1 = 1;
        GPIOA.ODR.BIT.B_2 = 1;
        GPIOA.ODR.BIT.B_3 = 0;
      }
      Vi_tri.row_check++;
      if(Vi_tri.row_check == 4) Vi_tri.row_check = 0;      
      MsTick = 0;
    }
    
   
    if(GPIOA.IDR.BIT.B_4 == 0){
      Vi_tri.colum = 0;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Status++;
      while(GPIOA.IDR.BIT.B_4 == 0);
    }
    if(GPIOA.IDR.BIT.B_5 == 0){
      Vi_tri.colum = 1;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Status++;
      while(GPIOA.IDR.BIT.B_5 == 0);
    }
    if(GPIOA.IDR.BIT.B_6 == 0){
      Vi_tri.colum = 2;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Status++;
      while(GPIOA.IDR.BIT.B_6 == 0);
    }
    if(GPIOA.IDR.BIT.B_7 == 0){
      Vi_tri.colum = 3;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Status++;
      while(GPIOA.IDR.BIT.B_7 == 0);
    }
   
    
    if(Status == 1 && Last_Stauts != Status){
      ma_phim.ma_truyen = bang_ma[Vi_tri.row][Vi_tri.colum];
      LCD_Clear();
      LCD_Writes("Du lieu: ", 9);
      LCD_Index(1, 11);
      LCD_Write(ma_phim.ma_truyen);
      
      LCD_Index(2, 1);
      LCD_Writes("Nhap vi tri sai:", 16);
      Last_Stauts = Status;
    }
    
    // Xu ly du lieu tu ban phim
    if(Status == 2){
      ma_phim.ma_bit = bang_ma[Vi_tri.row][Vi_tri.colum];
      Buffer = ma_phim.ma_truyen;
      Data.REG = Buffer;
      
      //tao loi khi truyen data
      Data_Error.REG = Data.REG;
      Data_Encoded = Encode_Hamming(Data);
      
      switch(ma_phim.ma_bit){
        case '1':
          Data_Error.BIT.B0 = !Data_Error.BIT.B0; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B2 = !Data_Encoded_Error.BIT.B2;
          break;
        case '2':
          Data_Error.BIT.B1 = !Data_Error.BIT.B1; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B4 = !Data_Encoded_Error.BIT.B4;
          break;
        case '3':
          Data_Error.BIT.B2 = !Data_Error.BIT.B2; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B5 = !Data_Encoded_Error.BIT.B5;
          break;
        case '4':
          Data_Error.BIT.B3 = !Data_Error.BIT.B3; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B6 = !Data_Encoded_Error.BIT.B6;
          break;
        case '5':
          Data_Error.BIT.B4 = !Data_Error.BIT.B4; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B8 = !Data_Encoded_Error.BIT.B8;
          break;
        case '6':
          Data_Error.BIT.B5 = !Data_Error.BIT.B5; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B9 = !Data_Encoded_Error.BIT.B9;
          break;
        case '7':
          Data_Error.BIT.B6 = !Data_Error.BIT.B6; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B10 = !Data_Encoded_Error.BIT.B10;
          break;
        case '8':
          Data_Error.BIT.B7 = !Data_Error.BIT.B7; 
          Data_Encoded_Error  = Data_Encoded;
          Data_Encoded_Error.BIT.B11 = !Data_Encoded_Error.BIT.B11;
          break;
          
      }
      //hien thi
      LCD_Clear();
      LCD_Writes("So dung: ", 9);
      LCD_Index(1, 12);
      LCD_Write(Buffer);
      LCD_Index(2, 1);
      LCD_Writes("So truyen: ", 10);
      LCD_Index(2, 12);
      LCD_Write(Data_Error.REG);
      
      //chia data loi thanh 2 byte de truyen di
      Byte_Error[0] = (unsigned char) Data_Encoded_Error .REG; //gui bit thap truoc roi den bit cao
      Byte_Error[1] = (unsigned char) (Data_Encoded_Error .REG >> 8);
      UART_Writes(&UART1 ,Byte_Error, 2);
      
      Status = 0;
      Last_Stauts = Status;
    }
 
  }
  
}