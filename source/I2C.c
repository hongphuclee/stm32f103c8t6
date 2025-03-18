#include<i2c.h>
#include<LHP_stm32f103.h>


void I2C_Start(){
  SDA(0);
  SCL(0);
}

void I2C_Stop(){
  SDA(0);
  SCL(1);
  SDA(1);
}

unsigned char I2C_Write_Byte(unsigned char Data){
  SDA(!!(Data & 0x80)); SCL(1); SCL(0);
  SDA(!!(Data & 0x40)); SCL(1); SCL(0);
  SDA(!!(Data & 0x20)); SCL(1); SCL(0);
  SDA(!!(Data & 0x10)); SCL(1); SCL(0);
  SDA(!!(Data & 0x08)); SCL(1); SCL(0);
  SDA(!!(Data & 0x04)); SCL(1); SCL(0);
  SDA(!!(Data & 0x02)); SCL(1); SCL(0);
  SDA(!!(Data & 0x01)); SCL(1); SCL(0);
  unsigned char ACK;
  SDA(1); SCL(1); ACK =IDA() ;SCL(0);
}

void I2C_Write(unsigned char Address ,unsigned char Command ,unsigned char Data) // 0 write, 1 read;
{
  I2C_Start();
  I2C_Write_Byte((Address << 1) | Command);
  I2C_Write_Byte(Data);
  
  I2C_Stop();
}

