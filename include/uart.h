#ifndef UART_H
#define UART_H

typedef struct{
  union{
    unsigned long REG;
    struct{
      unsigned long PE : 1;
      unsigned long FE : 1;
      unsigned long NE : 1;
      unsigned long ORE : 1;
      unsigned long IDLE : 1;
      unsigned long RXNE : 1;
      unsigned long TC : 1;
      unsigned long TXE : 1;
      unsigned long LBD : 1;
      unsigned long CTS : 1;
    } BIT;
  } SR;
  
  unsigned long DR; //MAXIMUM 9 BITS ARE USED 
  
  union{
    unsigned long REG;
    struct{
      unsigned long DIV_Fraction : 4;
      unsigned long DIV_Mantissa : 12;
    } BIT;
  } BRR;
  
  union{
    unsigned long REG;
    struct{
      unsigned long SBK : 1;
      unsigned long RWU : 1;
      unsigned long RE : 1;
      unsigned long TE : 1;
      unsigned long IDLEIE : 1;
      unsigned long RXNEIE : 1;
      unsigned long TCIE : 1;
      unsigned long TXEIE : 1;
      unsigned long PEIE : 1;
      unsigned long PS : 1;
      unsigned long PCE : 1;
      unsigned long WAKE : 1;
      unsigned long M : 1;
      unsigned long UE : 1;
    } BIT;
  } CR1;
  
  union{
    unsigned long REG;
    struct{
      unsigned long ADD : 4;
      unsigned long REVERSED : 1;
      unsigned long LBDL : 1;
      unsigned long LBDIE : 1;
      unsigned long REVERSED1 : 1;
      unsigned long LBCL : 1;
      unsigned long CPHA : 1;
      unsigned long CPOL : 1;
      unsigned long CLKEN : 1;
      unsigned long STOP : 2;
      unsigned long LINEN : 1;
    } BIT;
  } CR2;
  
  union{
    unsigned long REG;
    struct{
      unsigned long EIE : 1;
      unsigned long IREN : 1;
      unsigned long IRLP : 1;
      unsigned long HDSEL : 1;
      unsigned long NACK : 1;
      unsigned long SCEN : 1;
      unsigned long DMAR : 1;
      unsigned long DMAT : 1;
      unsigned long RTSE : 1;
      unsigned long CTSE : 1;
      unsigned long CTSIE : 1;
    } BIT;
  } CR3;
  
  union{
    unsigned long REG;
    struct{
      unsigned long PSC : 8;
      unsigned long GT : 8;
    } BIT;
  } GTPR;
  
} UART_Typedef;

__root __no_init UART_Typedef UART1 @ 0x40013800;
__root __no_init UART_Typedef UART2 @ 0x40004400;

void UART_Write(UART_Typedef* UART, unsigned char Data);
void UART_Writes(UART_Typedef* UART, const unsigned char* Data, unsigned Size); // Data is a pointer but Array donot use *;
void UART1_Init();
#endif