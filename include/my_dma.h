#ifndef MY_DMA_H
#define MY_DMA_H

typedef struct{
  
  union{
    unsigned long REG;
    struct{
      unsigned long  GIF1 : 1;
      unsigned long TCIF1 : 1;
      unsigned long HTIF1 : 1;
      unsigned long TEIF1 : 1;
      unsigned long  GIF2 : 1;
      unsigned long TCIF2 : 1;
      unsigned long HTIF2 : 1;
      unsigned long TEIF2 : 1;
      unsigned long  GIF3 : 1;
      unsigned long TCIF3 : 1;
      unsigned long HTIF3 : 1;
      unsigned long TEIF3 : 1;
      unsigned long  GIF4 : 1;
      unsigned long TCIF4 : 1;
      unsigned long HTIF4 : 1;
      unsigned long TEIF4 : 1;
      unsigned long  GIF5 : 1;
      unsigned long TCIF5 : 1;
      unsigned long HTIF5 : 1;
      unsigned long TEIF5 : 1;
      unsigned long  GIF6 : 1;
      unsigned long TCIF6 : 1;
      unsigned long HTIF6 : 1;
      unsigned long TEIF6 : 1;
      unsigned long  GIF7 : 1;
      unsigned long TCIF7 : 1;
      unsigned long HTIF7 : 1;
      unsigned long TEIF7 : 1;
    } BIT;
  } ISR;
  
  union{
    unsigned long REG;
    struct{
      unsigned long  CGIF1 : 1;
      unsigned long CTCIF1 : 1;
      unsigned long CHTIF1 : 1;
      unsigned long CTEIF1 : 1;
      unsigned long  CGIF2 : 1;
      unsigned long CTCIF2 : 1;
      unsigned long CHTIF2 : 1;
      unsigned long CTEIF2 : 1;
      unsigned long  CGIF3 : 1;
      unsigned long CTCIF3 : 1;
      unsigned long CHTIF3 : 1;
      unsigned long CTEIF3 : 1;
      unsigned long  CGIF4 : 1;
      unsigned long CTCIF4 : 1;
      unsigned long CHTIF4 : 1;
      unsigned long CTEIF4 : 1;
      unsigned long  CGIF5 : 1;
      unsigned long CTCIF5 : 1;
      unsigned long CHTIF5 : 1;
      unsigned long CTEIF5 : 1;
      unsigned long  CGIF6 : 1;
      unsigned long CTCIF6 : 1;
      unsigned long CHTIF6 : 1;
      unsigned long CTEIF6 : 1;
      unsigned long  CGIF7 : 1;
      unsigned long CTCIF7 : 1;
      unsigned long CHTIF7 : 1;
      unsigned long CTEIF7 : 1;
    } BIT;
  } IFCR;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR1;
    
    unsigned long CNDTR1;
    unsigned long CPAR1;
    unsigned long CMAR1;
  } channel_1;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR2;
    
    unsigned long CNDTR2;
    unsigned long CPAR2;
    unsigned long CMAR2;
  } channel_2;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR3;
    
    unsigned long CNDTR3;
    unsigned long CPAR3;
    unsigned long CMAR3;
  } channel_3;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR4;
    
    unsigned long CNDTR4;
    unsigned long CPAR4;
    unsigned long CMAR4;
  } channel_4;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR5;
    
    unsigned long CNDTR5;
    unsigned long CPAR5;
    unsigned long CMAR5;
  } channel_5;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR6;
    
    unsigned long CNDTR6;
    unsigned long CPAR6;
    unsigned long CMAR6;
  } channel_6;
  
  struct{
    union{
      unsigned long REG;
      struct{
        unsigned long EN      : 1;
        unsigned long TCIE    : 1;
        unsigned long HTIE    : 1;
        unsigned long TEIE    : 1;
        unsigned long DIR     : 1;
        unsigned long CIRC    : 1;
        unsigned long PINC    : 1;
        unsigned long MINC    : 1;
        unsigned long PSIZE   : 2;
        unsigned long MSIZE   : 2;
        unsigned long PL      : 2;
        unsigned long MEM2MEM : 1;
      } BIT;
    } CCR7;
    unsigned long CNDTR7;
    unsigned long CPAR7;
    unsigned long CMAR7;
  } channel_7;
  
} DMA_Typedef;

__root __no_init DMA_Typedef DMA1 @ 0x40020000;

#endif