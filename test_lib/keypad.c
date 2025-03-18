#include<LHP_stm32f103.h>

unsigned char bang_ma[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

unsigned char buffer = 0;

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
  unsigned char ma_current;
  unsigned char last_ma;
} ma_phim = {
  .ma_current = 123,
  .last_ma = 123,
};

void main(){
  
  RCC.APB2_ENR.BIT.IOPAEN = 1;
  GPIO_Mode(&GPIOA ,BIT0 | BIT1 | BIT2 | BIT3, output_push_pull_10Mhz); // HANG(R)
  GPIO_Mode(&GPIOA ,BIT4 | BIT5 | BIT6 | BIT7, input_push_pull); // COT
  GPIOA.ODR.REG = BIT0 | BIT1| BIT2| BIT3|  BIT4 | BIT5 | BIT6 | BIT7; // INPUT PULL UP
  Timer1_Init(&Timer1, 8);
  
  while(1){
    
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
    }
    
    if(GPIOA.IDR.BIT.B_5 == 0){
      Vi_tri.colum = 1;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
    }
    
    if(GPIOA.IDR.BIT.B_6 == 0){
      Vi_tri.colum = 2;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
    }
    
    if(GPIOA.IDR.BIT.B_7 == 0){
      Vi_tri.colum = 3;
      Vi_tri.row = Vi_tri.row_check - 1;
      if(Vi_tri.row == 0xFF) Vi_tri.row = 3;
    }
    ma_phim.ma_current = bang_ma[Vi_tri.row][Vi_tri.colum];
    if(ma_phim.ma_current != ma_phim.last_ma) ma_phim.last_ma = ma_phim.ma_current;
    
      
  }
  
}