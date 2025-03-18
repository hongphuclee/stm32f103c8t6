#ifndef TIMER1_H
#define TIMER1_H

typedef struct{
  
  union{
    unsigned long REG;
    struct{
      unsigned long CEN : 1;
      unsigned long UDIS : 1;
      unsigned long URS: 1;
      unsigned long OPM : 1;
      unsigned long DIR : 1;
      unsigned long CMS : 2;
      unsigned long APPE : 1;
      unsigned long CKD : 2;
    } BIT;
  } CR1;
  
  union{
    unsigned long REG;
    struct{
      unsigned long CCPC : 1;
      unsigned long REVERSED : 1;
      unsigned long CCUS : 1;
      unsigned long CCDS  : 1;
      unsigned long MMS : 3;
      unsigned long TI1S : 1;
      unsigned long OIS1 : 1;
      unsigned long OIS1N: 1;
      unsigned long OIS2 : 1;
      unsigned long OIS2N : 1;
      unsigned long OIS3 : 1;
      unsigned long OIS3N : 1;
      unsigned long OIS4 : 1;
    } BIT;
  } CR2;
  
  union{
    unsigned long REG;
    struct{
      unsigned long SMS : 3;
      unsigned long REVERSED : 1;
      unsigned long TS : 3;
      unsigned long MSM : 1;
      unsigned long ETF : 4;
      unsigned long ETPS : 2;
      unsigned long ECE : 1;
      unsigned long ETP : 1;
    } BIT;
  } SMCR;
  
  union{
    unsigned long REG;
    struct{
      unsigned long UIE : 1;
      unsigned long CC1IE : 1;
      unsigned long CC2IE : 1; 
      unsigned long CC3IE : 1;
      unsigned long CC4IE : 1;
      unsigned long COMIE : 1;
      unsigned long TIE : 1;
      unsigned long BIE : 1;
      unsigned long UDE : 1;
      unsigned long CC1DE : 1;
      unsigned long CC2DE : 1;
      unsigned long CC3DE : 1;
      unsigned long CC4DE : 1;
      unsigned long COMDE : 1;
      unsigned long TDE : 1;
    } BIT;
  } DIER;
  
  union{
    unsigned long REG;
    struct{
      unsigned long UIF : 1;
      unsigned long CC1IF : 1;
      unsigned long CC2IF : 1;
      unsigned long CC3IF : 1;
      unsigned long CC4IF : 1;
      unsigned long COMIF : 1;
      unsigned long TIF : 1;
      unsigned long BIF : 1;
      unsigned long REVERSED : 1;
      unsigned long CC1OF : 1;
      unsigned long CC2OF : 1;
      unsigned long CC3OF : 1;
      unsigned long CC4OF : 1;
    } BIT;
  } SR;
  
  union{
    unsigned long REG;
    struct{
      unsigned long UG : 1;
      unsigned long CC1G : 1;
      unsigned long CC2G : 1;
      unsigned long CC3G : 1;
      unsigned long CC4G : 1;
      unsigned long COMG : 1;
      unsigned long TG : 1;
      unsigned long BG : 1;
    } BIT;
  } EGR;
  
  union{
    unsigned short REG; 
    struct{
      unsigned long CC1S : 2;
      unsigned long OC1FE : 1;
      unsigned long OC1PE : 1;
      unsigned long OC1M : 3;
      unsigned long OC1CE : 1;
      unsigned long CC2S : 2;
      unsigned long OC2FE : 1;
      unsigned long OC2PE : 1;
      unsigned long OC2M : 3;
      unsigned long OC2CE : 1;
    } BIT;
  }CCMR1_O;
  
  
  
  union{
    unsigned long REG;
    struct{
      unsigned long CCS3 : 2;
      unsigned long OC3FE : 1;
      unsigned long OC3PE : 1;
      unsigned long OC3M : 3;
      unsigned long OC3CE : 1;
      unsigned long CC4S : 2;
      unsigned long OC4FE : 1;
      unsigned long OC4PE : 1;
      unsigned long OC4M : 3;
      unsigned long OC4CE : 1;
    } BIT;
  } CCMR2_O;
  
  
  union{
    unsigned long REG;
    struct{
      unsigned long CC1E : 1;
      unsigned long CC1P : 1;
      unsigned long CC1NE : 1;
      unsigned long CC1NP: 1;
      unsigned long CC2E : 1;
      unsigned long CC2P : 1;
      unsigned long CC2NE : 1;
      unsigned long CC2NP: 1;
      unsigned long CC3E : 1;
      unsigned long CC3P : 1;
      unsigned long CC3NE : 1;
      unsigned long CC3NP: 1;
      unsigned long CC4E : 1;
      unsigned long CC4P : 1;
      unsigned long CC4NE : 1;
      unsigned long CC4NP: 1;
    } BIT;
  } CCER;
  
  unsigned long CNT; // maximum 16 bits are used
  unsigned long PSC; // maximum 16 bits are used
  unsigned long ARR; // maximum 16 bits are used
  unsigned long Reversed;
  unsigned long RCR; // maximum 8 bits are used
  unsigned long CCR1; // maximum 16 bits are used
  unsigned long CCR2; // maximum 16 bits are used
  unsigned long CCR3; // maximum 16 bits are used
  unsigned long CCR4; // maximum 16 bits are used
  
  union{
    unsigned long REG;
    struct{
      unsigned long DT : 8;
      unsigned long LOCK : 2;
      unsigned long OSSI : 1;
      unsigned long OSSR : 1;
      unsigned long BKE : 1;
      unsigned long BKP : 1;
      unsigned long AOE : 1;
      unsigned long MOE : 1;
    } BIT;
  } BDTR;
  
  union{
    unsigned long REG; 
    struct{
      unsigned long DBA : 5;
      unsigned long RESERVED : 3;
      unsigned long DBL : 5;
    } BIT;
  } DCR; 
  
  unsigned long DMAB; // maximum 32 bits are used
    
} Timer1_Typedef;

__root __no_init Timer1_Typedef Timer1 @ 0x40012C00;

void Timer1_Init(Timer1_Typedef* Timer1,unsigned char Time);

#endif