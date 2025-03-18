typedef struct{
  
  union{
    unsigned long REG;
    struct{
      unsigned long WWDG                : 1;
      unsigned long PVD                 : 1;
      unsigned long TAMPER              : 1;
      unsigned long RTC                 : 1;
      unsigned long FLASH               : 1;
      unsigned long RCC                 : 1;
      unsigned long EXTI0               : 1;
      unsigned long EXTI1               : 1;
      unsigned long EXTI2               : 1;
      unsigned long EXTI3               : 1;
      unsigned long EXTI4               : 1;
      unsigned long DMA1_Chanel1        : 1;
      unsigned long DMA1_Chanel2        : 1;
      unsigned long DMA1_Chanel3        : 1;
      unsigned long DMA1_Chanel4        : 1;
      unsigned long DMA1_Chanel5        : 1;
      unsigned long DMA1_Chanel6        : 1;
      unsigned long DMA1_Chanel7        : 1;
      unsigned long ADC1_2              : 1;
      unsigned long CAN1_TX             : 1;
      unsigned long CAN1_RX0            : 1;
      unsigned long CAN1_RX1            : 1;
      unsigned long CAN1_SCE            : 1;
      unsigned long EXTI9_5             : 1;
      unsigned long TIM1_BRK            : 1;
      unsigned long TIM1_UP             : 1;
      unsigned long TIM1_TRG_COM        : 1;
      unsigned long TIM1_CC             : 1;
      unsigned long TIM2                : 1;
      unsigned long TIM3                : 1;
      unsigned long TIM4                : 1;
      unsigned long I2C1_EV             : 1;
    } BIT;                              
  } NVIC_SER0;
  
  union{
    unsigned long REG;
    struct{
      unsigned long I2C1_ER             : 1;
      unsigned long I2C2EV              : 1;
      unsigned long I2C2ER              : 1;
      unsigned long SPI1                : 1;
      unsigned long SPI2                : 1;
      unsigned long USART1              : 1;
      unsigned long USART2              : 1;
      unsigned long USART3              : 1;
      unsigned long EXTI15_10           : 1;
      unsigned long RTCAlarm            : 1;
      unsigned long OTG_FS_WKUP         : 1;
      unsigned long RESERVED            : 1;
      unsigned long RESERVED1           : 1;
      unsigned long RESERVED2           : 1;
      unsigned long RESERVED3           : 1;
      unsigned long RESERVED4           : 1;
      unsigned long RESERVED5           : 1;
      unsigned long RESERVED6           : 1;
      unsigned long TIM5                : 1;
      unsigned long SPI3                : 1;
      unsigned long USART4              : 1;
      unsigned long USART5              : 1;
      unsigned long TIM6                : 1;
      unsigned long TIM7                : 1;
      unsigned long DMA2_CHANNEL1       : 1;
      unsigned long DMA2_CHANNEL2       : 1;
      unsigned long DMA2_CHANNEL3       : 1;
      unsigned long DMA2_CHANNEL4       : 1;
      unsigned long DMA2_CHANNEL5       : 1;
      unsigned long ETH                 : 1;
      unsigned long ETH_WKUP            : 1;                  
      unsigned long CAN2_TX             : 1;                   
    } BIT;
  } NVIC_SER1;
  
  union{
    unsigned long REG;
    struct{
      unsigned long    CAN2_RX0            : 1;
      unsigned long    CAN2_RX1            : 1;
      unsigned long    CAN2_SCE            : 1;
      unsigned long    OTG_FS              : 1;
    } BIT;
  } NVIC_SER2;
  
} NVIC_Typedef;

__root __no_init NVIC_Typedef NVIC @ 0xE000E100 ;