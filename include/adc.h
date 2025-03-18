
#ifndef ADC_H
#define ADC_H

typedef struct{
  
  union{
    unsigned char REG;
    struct{
      unsigned long AWD : 1;
      unsigned long EOC : 1;
      unsigned long JEOC : 1;
      unsigned long JSTRT : 1;
      unsigned long STRT : 1;
    } BIT;
  } SR;
  
  union{
    unsigned char REG;
    struct{
      unsigned long AWDCH : 5;
      unsigned long EOCIE : 1;
      unsigned long AWDIE : 1;
      unsigned long JEOCIE : 1;
      unsigned long SCAN : 1;
      unsigned long AWDSGL : 1;
      unsigned long JAUTO : 1;
      unsigned long DISCEN : 1;
      unsigned long JDISCEN : 1;
      unsigned long DISCNUM : 3;
      unsigned long DUALMOD : 4;
      unsigned long reverse : 2;
      unsigned long JAWDEN : 1;
      unsigned long AWDEN : 1;
    } BIT;
  } CR1;
  
  union{
    unsigned long REG;
    struct{
      unsigned long ADON : 1;
      unsigned long CONT : 1;
      unsigned long CAL : 1;
      unsigned long RSTCAL : 1;
      unsigned long REVERSE : 4;
      unsigned long DMA : 1;
      unsigned long REVERSE1 : 2;
      unsigned long ALIGN : 1;
      unsigned long JEXTSE : 3;
      unsigned long JEXTTRIG : 1;
      unsigned long REVERSE2 : 1;
      unsigned long EXTSEL : 3;
      unsigned long EXTTRIG : 1;
      unsigned long JSWSTART : 1;
      unsigned long SWSTART : 1;
      unsigned long TSVREFE : 1;
    } BIT;
  } CR2;
    
  unsigned long SMPR1;
  unsigned long SMPR2;
  unsigned long JOFR1;
  unsigned long JOFR2;
  unsigned long JOFR3;
  unsigned long JOFR4;
  unsigned long HTR;
  unsigned long LTR;
  
  union{
    unsigned long REG;
    struct{
      unsigned long SQ13 : 5;
      unsigned long SQ14 : 5;
      unsigned long SQ15 : 5;
      unsigned long SQ16 : 5;
      unsigned long L : 4;
    } BIT;
  } SQR1;
  
  
  union{
    unsigned long REG;
    struct{
      unsigned long SQ7 : 5;
      unsigned long SQ8 : 5;
      unsigned long SQ9 : 5;
      unsigned long SQ10 : 5;
      unsigned long SQ11 : 5;
      unsigned long SQ12 : 5;
    } BIT;
  }SQR2;
  
  union{
    unsigned long REG;
    struct{
      unsigned long SQ1 : 5;
      unsigned long SQ2 : 5;
      unsigned long SQ3 : 5;
      unsigned long SQ4 : 5;
      unsigned long SQ5 : 5;
      unsigned long SQ6 : 5;
    } BIT;
  }SQR3;
  
  union{
    unsigned long REG;
    struct{
      unsigned long JSQ1 : 5;
      unsigned long JSQ2 : 5;
      unsigned long JSQ3 : 5;
      unsigned long JSQ4 : 5;
      unsigned long JL : 2;
    } BIT;
  } JSQR;
  
  unsigned long JDR1;
  unsigned long JDR2;
  unsigned long JDR3;
  unsigned long JDR4;
  
  unsigned long DR;
  
} ADC_Typedef;

void ADC_Start(volatile ADC_Typedef* ADC, unsigned long Channel);
unsigned long ADC_Read(volatile ADC_Typedef* ADC);
void ADC_Stop(volatile ADC_Typedef* ADC);
#endif

__root __no_init  ADC_Typedef ADC1 @ 0x40012400;