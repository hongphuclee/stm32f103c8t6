#ifndef _I2C_H
#define _I2C_H

#define SDA(Isset)      GPIOB.ODR.BIT.B_9 = Isset; for(unsigned char i = 0; i < 60; i++)
#define SCL(Isset)      GPIOB.ODR.BIT.B_8 = Isset; for(unsigned char i = 0; i < 60; i++)
#define IDA()           GPIOB.IDR.BIT.B_9
#define Read            1
#define Write           0

void I2C_Start();

void I2C_Stop();

void I2C_Write(unsigned char Address ,unsigned char Command ,unsigned char Data); // 0 write, 1 red;

unsigned char I2C_Write_Byte(unsigned char Data);

#endif