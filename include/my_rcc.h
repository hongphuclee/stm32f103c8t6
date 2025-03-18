#ifndef MY_RCC_H
#define MY_RCC_H
typedef struct{
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long HSION : 1;
      unsigned long HSIRDY : 1;
      unsigned long Reserved1 : 1;
      unsigned long HSITRIM : 5;
      unsigned long HSICAL : 8;
      unsigned long HSEON : 1;
      unsigned long HSERDI : 1;
      unsigned long HSEBIP : 1;
      unsigned long CSSON : 1;
      unsigned long RESERVED2 : 4;
      unsigned long PLLON : 1;
      unsigned long PLLRDY : 1;
      unsigned long PLL2ON : 1;
      unsigned long PLL2RDY : 1;
      unsigned long PLL3ON : 1;
      unsigned long PLL3RDY : 1;
      unsigned long RESERVED3 : 2;
    } BIT;
  } CR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long SW : 2;
      unsigned long SWS : 2;
      unsigned long HPRE : 4;
      unsigned long PPRE : 3;
      unsigned long PPER2 : 3;
      unsigned long ADCPRE : 2;
      unsigned long PLLSRC : 1;
      unsigned long PLLXTPRE : 1;
      unsigned long PLLMUL : 4;
      unsigned long OTGFSPRE : 1;
      unsigned long RESERVED : 1;
      unsigned long MCO : 4;
      unsigned long RESERVED2 : 4;
    } BIT;
  } CFGR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long LSIRDYF : 1;
      unsigned long LSERDYF : 1;
      unsigned long HSIRDYF : 1;
      unsigned long HSERDYF : 1;
      unsigned long PLLRDYF : 1;
      unsigned long PLL2RDYF : 1;
      unsigned long PLL3RDYF : 1;
      unsigned long CSSF : 1;
      unsigned long LSIRDYIE : 1;
      unsigned long LSERDYIE : 1;
      unsigned long HSIRDYIE : 1;
      unsigned long HSERDYIE : 1;
      unsigned long PLLRDYIE : 1;
      unsigned long PLL2RDYIE : 1;
      unsigned long PLL3RDYIE : 1;
      unsigned long RESERVED : 1;
      unsigned long LSYRDYC : 1;
      unsigned long LSERDYC : 1;
      unsigned long HSIRDYC : 1;
      unsigned long HSERDYC : 1;
      unsigned long PLLRDYC : 1;
      unsigned long PLL2RDYC : 1;
      unsigned long PLL3RDYC : 1;
      unsigned long CSSC : 1;
      unsigned long RESERVED4 : 8;
    } BIT;
  } CIR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long AFIORST : 1;
      unsigned long RESERVED1 : 1;
      unsigned long IOPARST : 1;
      unsigned long IOPBRST : 1;
      unsigned long IOPCRST : 1;
      unsigned long IOPDRST : 1;
      unsigned long IOPERST : 1;
      unsigned long RESERVED2 : 2;
      unsigned long ADC1RST : 1;
      unsigned long ADC2RST : 1;
      unsigned long TMR1RST : 1;
      unsigned long SPI1RST : 1;
      unsigned long RESERVED3 : 1;
      unsigned long USRT1REST : 1;
      unsigned long RESERVED4 : 17;
    } BIT;
  } APB2_RSTR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long TM2RST : 1;
      unsigned long TM3RST : 1;
      unsigned long TM4RST : 1;
      unsigned long TM5RST : 1;
      unsigned long TM6RST : 1;
      unsigned long TM7RST : 1;
      unsigned long RESERVED1 : 5;
      unsigned long WWDGRST : 1;
      unsigned long RESERVED2 : 2;
      unsigned long SPI2RST : 1;
      unsigned long SPI3RST : 1;
      unsigned long RESERVED3 : 1;
      unsigned long UART2RST : 1;
      unsigned long UART3RST : 1;
      unsigned long UART4RST : 1;
      unsigned long UART5RST : 1;
      unsigned long I2C1RST : 1;
      unsigned long I2C2RST : 1;
      unsigned long RESERVED4 : 2;
      unsigned long CAN1RST : 1;
      unsigned long CAN2RST : 1;
      unsigned long BKPRST : 1;
      unsigned long PWRRST : 1;
      unsigned long DACRST : 1;
      unsigned long REVERSED5 : 2;
    } BIT;
  } APB1_RSTR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long DMA1AEN : 1;
      unsigned long DMA2AEN : 1;
      unsigned long SRAMEN : 1;
      unsigned long RESERVED1 : 1;
      unsigned long FLIEFEN : 1;
      unsigned long RESERVED2 : 1;
      unsigned long CRCEN : 1;
      unsigned long RESERVED3 : 5;
      unsigned long OTGFSEN : 1;
      unsigned long RESERVED4 : 1;
      unsigned long ETHMACEN : 1;
      unsigned long ETHMACTXEN : 1;
      unsigned long ETHMACRXEN : 1;
      unsigned long RESERVED5 : 15;
    } BIT;
  } AHB_ENR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long AFIONEN : 1;
      unsigned long RESERVED1 : 1;
      unsigned long IOPAEN : 1 ;
      unsigned long IOPBEN : 1 ;
      unsigned long IOPCEN : 1 ;
      unsigned long IOPDEN : 1 ;
      unsigned long IOPEEN : 1 ;
      unsigned long RESERVED2 : 2;
      unsigned long ADC1EN : 1;
      unsigned long ADC2EN : 1;
      unsigned long TM1EN : 1;
      unsigned long SPI1EN : 1;
      unsigned long RESERVED3 : 1;
      unsigned long USART1EN : 1;
      unsigned long RESERVED4 : 17;
    } BIT;
  } APB2_ENR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long TIM2EN : 1;
      unsigned long TIM3EN : 1;
      unsigned long TIM4EN : 1;
      unsigned long TIM5EN : 1;
      unsigned long TIM6EN : 1;
      unsigned long TIM7EN : 1;
      unsigned long Reserved1 : 5;
      unsigned long WWDGEN : 1;
      unsigned long Reserved6 : 2;
      unsigned long SPI2EN : 1;
      unsigned long SPI3EN : 1;
      unsigned long Reserved2: 1;
      unsigned long UART2EN : 1;
      unsigned long UART3EN : 1;
      unsigned long UART4EN : 1;
      unsigned long UART5EN : 1;
      unsigned long I2C1EN : 1;
      unsigned long I2C2EN : 1;
      unsigned long Reserved : 2;
      unsigned long CAN1EN : 1;
      unsigned long CAN2EN : 1;
      unsigned long BKPEN : 1;
      unsigned long PWREN : 1;
      unsigned long DACEN : 1;
    } BIT;
  } APB1_ENR;

  union
  {
    unsigned long REG;
    struct
    {
      unsigned long LSEON : 1;
      unsigned long LSERDY : 1;
      unsigned long LSEBYP : 1;
      unsigned long Reserved1 : 5;
      unsigned long RTC_SEL : 2;
      unsigned long Reserved2 : 5;
      unsigned long RTCEN : 1;
      unsigned long BDRST : 1;
      unsigned long Reserved : 15;
    } BIT;
  } BDCR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long LSION : 1;
      unsigned long LSIRDY : 1;
      unsigned long Reserved1 : 22;
      unsigned long RMVF : 1;
      unsigned long Reserved2 : 1;
      unsigned long PINRSTF : 1;
      unsigned long PORRSTF : 1;
      unsigned long SFTRSTF : 1;
      unsigned long IWDGRSTF : 1;
      unsigned long WWDGRSTF : 1;
      unsigned long LPWRSTF : 1 ;
    } BIT;
  } CSR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long RESERVED1 : 12;
      unsigned long OTGFSRST : 1;
      unsigned long RESERVED2: 1;
      unsigned long ETHMACRST : 1;
      unsigned long RESERVED3: 17;
    } BIT;
  } AHB_STR;
  
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long PERDIV1 : 4;
      unsigned long PREDIV2 : 4;
      unsigned long PLL2MUL : 4;
      unsigned long PLL3MUL : 4;
      unsigned long PREDIV1SRC : 1;
      unsigned long I2S2SRC : 1;
      unsigned long I2S3SRC : 1;
      unsigned long RESERVED : 13;
    } BIT;
  } CFGR2;
  
}MY_RCC_Typedef;

__root __no_init MY_RCC_Typedef RCC @ 0x40021000;

#endif