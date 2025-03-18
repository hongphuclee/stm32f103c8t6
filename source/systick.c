#include<systick.h>
#include<bit.h>
#include<my_rcc.h>

//interrupt each 1ms
void SysTick_Init(unsigned long sys_time){
  STK.STK_LOAD.REG = sys_time * 8000;
  STK.STK_VAL.REG  = sys_time * 8000;
  STK.STK_CTRL.REG = BIT2 | BIT1 | BIT0;
}

unsigned long sys_current_time = 0;

void SysTick_Handler(){
  sys_current_time++;
}

unsigned long get_time(){
  return sys_current_time;
};

static unsigned long start_time;

void delay(unsigned long sys_time){
  start_time = get_time();
  while((get_time() - start_time) < sys_time);
}