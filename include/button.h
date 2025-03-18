#ifndef _BUTTON_H
#define _BUTTON_H

#include<gpio.h>
typedef enum{
  Button_Status_None = 0,
  Button_Status_Fall = 1,
  Button_Status_Rise = 2,
} Button_Status;

typedef struct{
  unsigned char Accumulator;
  unsigned char Count;
  unsigned char Time;
  Button_Status Status;
  Button_Status LastStatus;
} Button_Typedef;

void Button_Begin();
void Button_Process();

unsigned char Button_Check(Button_Status Status, unsigned char Clear);
unsigned char Button_Press(unsigned char Time, unsigned char Clear);
#define Read_Button() (GPIOB.IDR.BIT.B_15)

#endif 