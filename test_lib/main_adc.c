#include<adc.h>
#include<LHP_stm32f103.h>

unsigned long adc_value;

float  nhiet_do[10], ky_vong = 0;
unsigned char k = 0;

void main() {
  
  RCC.APB2_ENR.REG = 0xFFFFFFFF;
  GPIO_Mode(&GPIOB, BIT0, input_analog);
  
  while(1){
  
    ADC_Start(&ADC1, 8);
    adc_value = ADC_Read(&ADC1);
    nhiet_do[k] =  (adc_value*3.3/4095/0.01);
    k++;
    if(k == 10){
      ky_vong = 0;
      for(int i = 0; i < 10; i++){
        ky_vong += nhiet_do[i];
      }
      ky_vong = ky_vong / 10;
      k = 0;
    }
    for(int i = 0; i < 100000; i++);
    ADC_Stop(&ADC1);
  }
}