#ifndef SYSTICK_H
#define SYSTICK_H
typedef struct{
  union{
    unsigned long REG;
    struct{
      unsigned long ENABLE            : 1;
      unsigned long TICKINT           : 1;
      unsigned long CLKSOURCE         : 1;
      unsigned long Reserved          : 13;
      unsigned long COUNTFLAG         : 1;
      unsigned long Reserved_1         : 15;
    } BIT;
  } STK_CTRL;
  
  union{
    unsigned long REG;
    struct{
      unsigned long RELOAD     : 23;
      unsigned long REserved_2 : 9;
    } BIT;
  } STK_LOAD;
    
  union{
    unsigned long REG;
    struct{
      unsigned long CURRENT    : 23;
      unsigned long Reserved_3 : 9; 
    } BIT;
  } STK_VAL;
  
  union{
    unsigned long REG;
    struct{
      unsigned long TENMS      : 23;
      unsigned long Reserved_4 : 9;
    } BIT;
  } STK_CALIB;
  
} STK_Typedef;

__root __no_init STK_Typedef STK @ 0xE000E010;

void SysTick(unsigned long sys_time);
void delay(unsigned long sys_time);
unsigned long get_time();


#endif