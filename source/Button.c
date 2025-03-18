
#include<button.h>

__no_init Button_Typedef Button;

void Button_Begin()
{
  Button.Accumulator = 0;
  Button.Count = 5;
  Button.Status = (Button_Status)(Read_Button()+ 1);
  Button.LastStatus = Button_Status_None;
};

void Button_Process()
{
  if(Button.Count--)
  {
    Button.Accumulator += Read_Button() + 1;
      
  }
  else 
  {
    Button.Count = 5;
    Button.Accumulator /= 4;
    if((Button_Status)Button.Accumulator != Button.Status)
    {
      Button.Status =(Button_Status)Button.Accumulator;
      Button.LastStatus = Button.Status;
      if(Button.Status == Button_Status_Fall)
      {
        Button.Time = 0;
      }
    }
    if((Button_Status)Button.Accumulator == Button_Status_Fall && Button.Time < 255)
    {
      Button.Time++;
    }
  }
}

unsigned char Button_Check(Button_Status Status, unsigned char Clear)
{
  if(Button.LastStatus == Status){
    if(Clear){
      Button.LastStatus = Button_Status_None;
    }
    return 1;
  }
  return 0;
}

unsigned char Button_Press(unsigned char Time, unsigned char Clear)
{
  if(Button.LastStatus == Button_Status_Fall && Button.Time < Time)
  {
    if(Clear)
    {
     Button.LastStatus = Button_Status_None; 
    }
    return 1;
  }
  return 0;
}