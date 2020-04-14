#ifndef _LIS302DSH
#define _LIS302DSH

//Dependencies
#include "LIS302dsh_Defines.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>


#define LIS302DSH_CS_LOW        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
#define LIS302DSH_CS_HIGH       HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);


//Initialization parameter
struct _LIS302DSH_InitTypedef
{
    uint8_t DataRate;
    uint8_t EnableAxis;
    uint8_t FullScale;
    uint8_t AliasFilter;
};
typedef struct _LIS302DSH_InitTypedef LIS302DSH_InitTypedef;

// Raw Data Struct
struct _LIS302DSH_Raw_Data
{
    int16_t x,y,z;
};
typedef struct _LIS302DSH_Raw_Data LIS302DSH_Raw_Data;

// Low Level IO function
void _DeviceRead(uint8_t reg,uint8_t *rData,uint8_t size);
void _DeviceWrite(uint8_t reg,uint8_t *wData,uint8_t size);

// Initialization of Device
void LIS302DSH_Init(SPI_HandleTypeDef *accSPI,LIS302DSH_InitTypedef hconfig);

//Driver function
LIS302DSH_Raw_Data getRawXYZ();

#endif //endif _LIS302dl