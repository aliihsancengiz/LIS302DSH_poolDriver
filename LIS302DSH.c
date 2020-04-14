#include "LIS302DSH.h"
#include <string.h>


static SPI_HandleTypeDef deviceHandler;


void _DeviceRead(uint8_t reg,uint8_t *rData,uint8_t size)
{
    // Make read event by masking msb of reg
    reg |=(0x80);

    uint8_t receiveBuff[3],i;

    // Start SPI Transaction
    LIS302DSH_CS_LOW;

    // Set register adress
    HAL_SPI_Transmit(&deviceHandler,&reg,1,20);

    HAL_SPI_Receive(&deviceHandler,receiveBuff,size,20);

    // End SPI Transaction
    LIS302DSH_CS_HIGH;

    for (i = 0; i < (size & 0x3); i++)
    {
        rData[i]=receiveBuff[i];
    }
}
void _DeviceWrite(uint8_t reg,uint8_t *wData,uint8_t size)
{
    // Start SPI Transaction
    LIS302DSH_CS_LOW;

    // Set Written register
    HAL_SPI_Transmit(&deviceHandler,&reg,1,15);

    // Write the Data
    HAL_SPI_Transmit(&deviceHandler,wData,size,15);

    // End SPI Transaction
    LIS302DSH_CS_HIGH;

}


void LIS302DSH_Init(SPI_HandleTypeDef *accSPI,LIS302DSH_InitTypedef hconfig)
{
	memcpy(&deviceHandler,accSPI, sizeof(*accSPI));
    uint8_t regval=0;

    //Setting ctrl 4 reg
    regval |=(hconfig.DataRate & 0xf0);
    regval |=(hconfig.EnableAxis & 0x07);
    _DeviceWrite(LIS302DSH_CTRL_REG4,&regval,1);

    regval=0;
    //Setting ctrl 5 reg
    regval |=(hconfig.FullScale & 0x38);
    regval |=(hconfig.AliasFilter & 0xC0);
    _DeviceWrite(LIS302DSH_CTRL_REG5,&regval,1);
    
}


LIS302DSH_Raw_Data getRawXYZ(void)
{
	uint8_t recvBuff[2];
	LIS302DSH_Raw_Data tempDataRaw;
	//Read X data
	_DeviceRead(LIS302DSH_OUT_X_L, recvBuff, 2);
	tempDataRaw.x = ((recvBuff[1] << 8) + recvBuff[0]);
	
	//Read Y data
	_DeviceRead(LIS302DSH_OUT_Y_L, recvBuff, 2);
	tempDataRaw.y = ((recvBuff[1] << 8) + recvBuff[0]);
	
	//Read Z data
	_DeviceRead(LIS302DSH_OUT_Z_L, recvBuff, 2);
	tempDataRaw.z = ((recvBuff[1] << 8) + recvBuff[0]);
	
	return tempDataRaw;	
}
