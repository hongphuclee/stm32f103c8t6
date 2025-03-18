#ifndef GPIO_H
#define GPIO_H
#include<my_rcc.h>


typedef struct
{
  union{
    unsigned long REG;
    struct
    {
      unsigned long Mode_0 : 2;
      unsigned long  CNF_0 : 2;
      unsigned long Mode_1 : 2;
      unsigned long  CNF_1 : 2;
      unsigned long Mode_2 : 2;
      unsigned long  CNF_2 : 2;
      unsigned long Mode_3 : 2;
      unsigned long  CNF_3 : 2;
      unsigned long Mode_4 : 2;
      unsigned long  CNF_4 : 2;
      unsigned long Mode_5 : 2;
      unsigned long  CNF_5 : 2;
      unsigned long Mode_6 : 2;
      unsigned long  CNF_6 : 2;
      unsigned long Mode_7 : 2;
      unsigned long  CNF_7 : 2;  
    } BIT;
  } CRL;
  
  union{
    unsigned long REG;
    struct
    {
      unsigned long Mode_8 : 2;
      unsigned long  CNF_8 : 2;
      unsigned long Mode_9 : 2;
      unsigned long  CNF_9 : 2;
      unsigned long Mode_10 : 2;
      unsigned long  CNF_10 : 2;
      unsigned long Mode_11 : 2;
      unsigned long  CNF_11 : 2;
      unsigned long Mode_12 : 2;
      unsigned long  CNF_12 : 2;
      unsigned long Mode_13 : 2;
      unsigned long  CNF_13 : 2;
      unsigned long Mode_14 : 2;
      unsigned long  CNF_14 : 2;
      unsigned long Mode_15 : 2;
      unsigned long  CNF_15 : 2;  
    } BIT;
  } CRH;
  union{
    unsigned long REG;
    struct
    {
      unsigned long B_0 : 1;
      unsigned long B_1 : 1;
      unsigned long B_2 : 1;
      unsigned long B_3 : 1;
      unsigned long B_4 : 1;
      unsigned long B_5 : 1;
      unsigned long B_6 : 1;
      unsigned long B_7 : 1;
      unsigned long B_8 : 1;
      unsigned long B_9 : 1;
      unsigned long B_10 : 1;
      unsigned long B_11 : 1;
      unsigned long B_12 : 1;
      unsigned long B_13 : 1;
      unsigned long B_14 : 1;
      unsigned long B_15 : 1;
      unsigned long Reserved: 16;
    } BIT;
  } IDR;
  
  union{
    unsigned long REG;
    struct
    {
      unsigned long B_0 : 1;
      unsigned long B_1 : 1;
      unsigned long B_2 : 1;
      unsigned long B_3 : 1;
      unsigned long B_4 : 1;
      unsigned long B_5 : 1;
      unsigned long B_6 : 1;
      unsigned long B_7 : 1;
      unsigned long B_8 : 1;
      unsigned long B_9 : 1;
      unsigned long B_10 : 1;
      unsigned long B_11 : 1;
      unsigned long B_12 : 1;
      unsigned long B_13 : 1;
      unsigned long B_14 : 1;
      unsigned long B_15 : 1;
      unsigned long Reserved: 16;
    } BIT;
  } ODR;
  
  struct
  {
    union{
      unsigned short REG;
      struct
      {
        unsigned short B_0 : 1;
        unsigned short B_1 : 1;
        unsigned short B_2 : 1;
        unsigned short B_3 : 1;
        unsigned short B_4 : 1;
        unsigned short B_5 : 1;
        unsigned short B_6 : 1;
        unsigned short B_7 : 1;
      } BIT;
    } BSR;
    union{
      unsigned short REG;
      struct
      {
        unsigned short B_0 : 1;
        unsigned short B_1 : 1;
        unsigned short B_2 : 1;
        unsigned short B_3 : 1;
        unsigned short B_4 : 1;
        unsigned short B_5 : 1;
        unsigned short B_6 : 1;
        unsigned short B_7 : 1;
      } BIT;
    } BR;
  } BSRR;
  
  union{
    unsigned long REG;
    struct
    {
      unsigned long B_0 : 1;
      unsigned long B_1 : 1;
      unsigned long B_2 : 1;
      unsigned long B_3 : 1;
      unsigned long B_4 : 1;
      unsigned long B_5 : 1;
      unsigned long B_6 : 1;
      unsigned long B_7 : 1;
      unsigned long B_8 : 1;
      unsigned long B_9 : 1;
      unsigned long B_10 : 1;
      unsigned long B_11 : 1;
      unsigned long B_12 : 1;
      unsigned long B_13 : 1;
      unsigned long B_14 : 1;
      unsigned long B_15 : 1;
      unsigned long Reserved: 16;
    } BIT;
  } BRR;
  union{
    unsigned long REG;
    struct
    {
      unsigned long B_0 : 1;
      unsigned long B_1 : 1;
      unsigned long B_2 : 1;
      unsigned long B_3 : 1;
      unsigned long B_4 : 1;
      unsigned long B_5 : 1;
      unsigned long B_6 : 1;
      unsigned long B_7 : 1;
      unsigned long B_8 : 1;
      unsigned long B_9 : 1;
      unsigned long B_10 : 1;
      unsigned long B_11 : 1;
      unsigned long B_12 : 1;
      unsigned long B_13 : 1;
      unsigned long B_14 : 1;
      unsigned long B_15 : 1;
      unsigned long LCKK : 1;
      unsigned long Reserved: 15;
    } BIT;
  } LCK;
  
} GPIO_Typedef;


typedef enum {
    input_analog    = (0 << 2) | 0,
    input_floating  = (1 << 2) | 0,
    input_push_pull = (2 << 2) | 0,
    input_reserved  = (3 << 2) | 0,
    
    output_push_pull_10Mhz     = (0 << 2) | 1,
    output_open_drain_10Mhz    = (1 << 2) | 1,
    af_output_push_pull_10Mhz  = (2 << 2) | 1,
    af_output_open_drain_10Mhz = (3 << 2) | 1,
    
    output_push_pull_2Mhz     = (0 << 2) | 2,
    output_open_drain_2Mhz    = (1 << 2) | 2,
    af_output_push_pull_2Mhz  = (2 << 2) | 2,
    af_output_open_drain_2Mhz = (3 << 2) | 2,
    
    output_push_pull_50Mhz     = (0 << 2) | 3,
    output_open_drain_50Mhz    = (1 << 2) | 3,
    af_output_push_pull_50Mhz  = (2 << 2) | 3,
    af_output_open_drain_50Mhz = (3 << 2) | 3
} GPIO_MODE;

__root __no_init GPIO_Typedef GPIOC @ 0x40011000;
__root __no_init GPIO_Typedef GPIOA @ 0x40010800;
__root __no_init GPIO_Typedef GPIOB @ 0x40010C00;

void GPIO_Mode(volatile GPIO_Typedef* GPIO, unsigned int PIN, GPIO_MODE mode);

#endif
