#include <adc.h>
#include <LHP_stm32f103.h>

void ADC_Start(volatile ADC_Typedef* ADC, unsigned long Channel)
{
  ADC->CR2.REG = 0;
  ADC->SR.REG = 0;
  ADC->SQR3.REG = Channel;
  ADC->CR2.REG =  BIT0;
  ADC->CR2.REG = BIT22 | BIT0;
  ADC->SMPR2 = 7 << 24;
  ADC->CR2.BIT.EXTSEL = 0x7;
  ADC->CR2.BIT.EXTTRIG = 1;
  ADC->CR2.REG = ADC->CR2.REG;
}

void ADC_Stop(volatile ADC_Typedef* ADC){
  ADC->CR2.REG = 0x00000000;
  ADC->CR2.REG = ADC->CR2.REG;
}

unsigned long ADC_Read(volatile ADC_Typedef* ADC)
{
  unsigned long OutValue;
  OutValue = ADC->DR;
  return OutValue;
}