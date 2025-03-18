#include<gpio.h>
#include<button.h>
__root unsigned char xx = 0 ;
void main()
{
  RCC.APB2ENR.BIT.IOPBEN = 1;
  GPIO_Mode(&GPIOB, 1UL << 13, output_push_pull_10Mhz);
  GPIO_Mode(&GPIOB, 1UL << 15, input_push_pull);
  GPIOB.ODR.BIT.B_15 = 1;
  Button_Begin();
  while(1)
  {
    Button_Process();
    for(unsigned long i = 0; i < 4579; i++);
    if(Button_Check(Button_Status_Fall, 0))
    { // de clear se xoa mat trang thai last_status dan den cac ham phia sau hoat dong khong chinh xac
      xx = 1;
    }
    if(Button_Check(Button_Status_Rise, 1))
    { // de clear se xoa mat trang thai last_status dan den cac ham phia sau hoat dong khong chinh xac
      xx = 2;
    }
    if(Button_Press(10, 0))
    {
      xx = 3;
    }
  } 

}