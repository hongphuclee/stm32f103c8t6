#include<LHP_stm32f103.h>

float  nhiet_do[10], ky_vong = 0;
unsigned char bang_ma[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

#define Address 0x06;

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
Data_Typedef Data;
Data_Typedef Data_Error;

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
Data_Encoded_Typedef Data_Encoded;
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

// Hàm chuyen  float sang ASCII
void floatToAscii(float number, unsigned char* ascii, unsigned char bufferSize) {
    if (bufferSize < 1) return;
    
    unsigned char i = 0;
    
    // Lay phan nguyên
    unsigned long intPart = (unsigned long)number;
    // Lay phan thap phân
    float fracPart = number - (float)intPart;

    // Xu lý phan nguyên
    if (intPart == 0) {
        if (i < bufferSize) {
            ascii[i++] = '0';
        }
    } else {
        char reverse[10];  // Buffer cho phan nguyên
        unsigned char revIdx = 0;
        unsigned long temp = intPart;

        // Chuyen so thành chuoi (nguoc)
        while (temp > 0 && revIdx < 10) {
            reverse[revIdx++] = (temp % 10) + '0';
            temp /= 10;
        }

        // Ðao nguoc chuoi
        while (revIdx > 0 && i < bufferSize) {
            ascii[i++] = reverse[--revIdx];
        }
    }

    // Thêm dau cham thap phân
    if (i < bufferSize) {
        ascii[i++] = '.';
    }

    // Xu lý phan thap phân (2 chu so)
    if (i < bufferSize - 1) {  // Ðam bao còn cho cho 2 chu so
        // Nhân 100 de lay 2 chu so thap phân
        unsigned long fracInt = (unsigned long)(fracPart * 100.0f + 0.5f);
        
        // Ðam bao không vuot quá 99
        if (fracInt > 99) fracInt = 99;
        
        ascii[i++] = (fracInt / 10) + '0';
        if (i < bufferSize) {
            ascii[i++] = (fracInt % 10) + '0';
        }
    }

    // Ket thúc chuoi
    if (i < bufferSize) {
        ascii[i] = '\0';
    } else {
        ascii[bufferSize - 1] = '\0';
    }
}


union{
  unsigned long a;
  float b;
} ky_vong_gui;


unsigned char k = 0, Size = 0, Buffer[6], Buffer_LCD[8], Buffer_Receive[2], Size_Receive = 0, Buffer_Receive_s[2];
unsigned long adc_value = 0;
unsigned char status = 0;

unsigned char MsTick = 0;
unsigned long Time_HT = 0;
void TIM1_UP_IRQHandler(){
  MsTick = 1;
  Timer1.SR.REG = 0;
  Time_HT++;
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
  unsigned char ma_current;
  unsigned char last_ma;
} ma_phim = {
  .ma_current = 123,
  .last_ma = 123,
};

unsigned char Buffer_Tran[8];
void RS485_Writes(unsigned char Address_Tran, unsigned char Address_Re,
                  unsigned char* Buffer, unsigned char Size_trans){ 
  Buffer_Tran[0] = Address_Tran;
  Buffer_Tran[1] = Address_Re;
  for(int i = 0 ; i < 6; i++){
    Buffer_Tran[i + 2] = Buffer[i];
  }
  UART_Writes(&UART1, Buffer_Tran, Size_trans);
}

void UART1_IRQHandler(){
  unsigned data = UART1.DR;
  Buffer_Receive[Size_Receive] = data;
  Buffer_Receive_s[Size_Receive] = data + 1;
  status = 1;
  
  Size_Receive ++;
  if(Size_Receive == 2) Size_Receive = 0;
}

void main(){
  
  SysTick_Init(1);
  UART1_Init();
  Timer1_Init(&Timer1, 8);
  
  RCC.APB2_ENR.REG = 0xFFFFFFFF;
  GPIO_Mode(&GPIOB, BIT0, input_analog);// chan doc cam bien
  GPIO_Mode(&GPIOB, BIT8 | BIT9, output_push_pull_50Mhz); //SCL, SDA
  
  GPIO_Mode(&GPIOA ,BIT0 | BIT1 | BIT2 | BIT3, output_push_pull_10Mhz); // HANG(R)
  GPIO_Mode(&GPIOA ,BIT4 | BIT5 | BIT6 | BIT7, input_push_pull); // COT
  GPIOA.ODR.REG = BIT0 | BIT1| BIT2| BIT3|  BIT4 | BIT5 | BIT6 | BIT7; // INPUT PULL UP
  
  SDA(1);
  SCL(1);
  
  LCD_Init();
  
  
  while(1){
    
    
    //quet phim - xu ly hang
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
    
   //xu ly cot
    if(GPIOA.IDR.BIT.B_4 == 0){
      Vi_tri.colum = 0;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Size++;
      while(GPIOA.IDR.BIT.B_4 == 0);
    }
    
    if(GPIOA.IDR.BIT.B_5 == 0){
      Vi_tri.colum = 1;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Size++;
      while(GPIOA.IDR.BIT.B_5 == 0);
    }
    
    if(GPIOA.IDR.BIT.B_6 == 0){
      Vi_tri.colum = 2;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Size++;
      while(GPIOA.IDR.BIT.B_6 == 0);
    }
    
    if(GPIOA.IDR.BIT.B_7 == 0){
      Vi_tri.colum = 3;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
      Size++;
      while(GPIOA.IDR.BIT.B_7 == 0);
    }
    ma_phim.ma_current = bang_ma[Vi_tri.row][Vi_tri.colum];
    
    // Xu ly du lieu tu ban phim
    if(Size){
      Buffer[0] = 0x01;
      Buffer[1] = ma_phim.ma_current;
      RS485_Writes(0x06, 0x10, Buffer, 8);
      
        
      Size = 0;
    }
    //doc cam bien
    ADC_Start(&ADC1, 8);
    adc_value = ADC_Read(&ADC1);
    nhiet_do[k] = (adc_value*3.3/4095/0.01);
    k++;
    if(k == 10){
      ky_vong = 0;
      for(int i = 0; i < 10; i++){
        ky_vong += nhiet_do[i];
      }
      ky_vong = ky_vong / 10;
      ky_vong_gui.b = ky_vong; // chuyen gia tri float thanh 4byte
      floatToAscii(ky_vong, Buffer_LCD, 20); // chuyen sang mang ma askii de hien thi lcd
      
      for(int i = 0; i < 4; i++){
        Buffer[i + 2] = (unsigned char) (ky_vong_gui.a >> (i * 8)); 
      }
      
      k = 0;
    }
    ADC_Stop(&ADC1);
    
    if(Time_HT > 400){
      if(status == 0){
        LCD_Clear();
        LCD_Writes("Nhiet do: ", 10);
        LCD_Index(1, 12);
        LCD_Writes(Buffer_LCD, 5);
      }
      if(status == 1){
        if(ma_phim.ma_current == '1'){
          LCD_Clear();
          LCD_Writes("Temp nhan: ", 11);
          LCD_Index(1, 13);
          LCD_Writes(Buffer_Receive_s, 2);
          LCD_Index(2, 1);
          LCD_Writes("Temp sua: ", 10);
          LCD_Index(2, 13);
          LCD_Writes(Buffer_Receive, 2);
          
        }
        
        if(ma_phim.ma_current == '2'){
          LCD_Clear();
          LCD_Writes("Do am nhan: ", 12);
          LCD_Index(1, 13);
          LCD_Writes(Buffer_Receive_s, 2);
          LCD_Index(2, 1);
          LCD_Writes("Do am sua: ", 11);
          LCD_Index(2, 13);
          LCD_Writes(Buffer_Receive, 2);
          
        }
        status = 2;
      }
      
      Time_HT = 0;
    }
    
    if(ma_phim.ma_current == 'C') status = 0;
  }
  
}
