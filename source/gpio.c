#include<gpio.h>



void GPIO_Mode(volatile GPIO_Typedef* GPIO, unsigned int PIN, GPIO_MODE mode)
{
  
  unsigned int set = 0, reset = 0;
  for(unsigned int i = 0; i < 8; i++)
  {
    set <<= 4;
    reset <<= 4;
    if(PIN & (1UL << 15))
    {
      set |= mode;
    }
    else{
      reset |= 0x0F;
    }
    PIN <<= 1;
  }
  GPIO->CRH.REG &= reset;
  GPIO->CRH.REG |= set;
  
  set = 0, reset = 0;
  for(unsigned int i = 0; i < 8; i++)
  {
    set <<= 4;
    reset <<= 4;
    if(PIN & (1UL << 15))
    {
      set |= mode;
    }
    else{
      reset |= 0x0F;
    }
    PIN <<= 1;
  }
  GPIO->CRL.REG &= reset;
  GPIO->CRL.REG |= set;

}