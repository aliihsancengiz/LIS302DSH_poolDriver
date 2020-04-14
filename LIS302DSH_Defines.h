#ifndef _LIS302Defines
#define _LIS302Defines

/*
    Register mapping of LIS302dsh acclerometer
*/

//Who_am_i register 
#define WHO_AM_I 0x0F

//Offset Correction 
#define OFF_X    0x10
#define OFF_Y    0x11
#define OFF_Z    0x12

//Control Registers
#define LIS302DSH_CTRL_REG4 0x20
#define LIS302DSH_CTRL_REG1 0x21
#define LIS302DSH_CTRL_REG2 0x22
#define LIS302DSH_CTRL_REG3 0x23
#define LIS302DSH_CTRL_REG5 0x24
#define LIS302DSH_CTRL_REG6 0x25

//Output registers
#define LIS302DSH_OUT_X_L 0x28
#define LIS302DSH_OUT_X_H 0x29
#define LIS302DSH_OUT_Y_L 0x2A
#define LIS302DSH_OUT_Y_H 0x2B
#define LIS302DSH_OUT_Z_L 0x2C
#define LIS302DSH_OUT_Z_H 0x2D


// CTRL_REG4 İnternals

// Data Rate
#define LIS302DSH_DATA_RATE_PowerDown (uint8_t)(0x00)
#define LIS302DSH_DATA_RATE_3_125     (uint8_t)(0x10)
#define LIS302DSH_DATA_RATE_6_25      (uint8_t)(0x20)
#define LIS302DSH_DATA_RATE_12_5      (uint8_t)(0x30)
#define LIS302DSH_DATA_RATE_25        (uint8_t)(0x40)
#define LIS302DSH_DATA_RATE_50        (uint8_t)(0x50)
#define LIS302DSH_DATA_RATE_100       (uint8_t)(0x60)
#define LIS302DSH_DATA_RATE_400       (uint8_t)(0x70)
#define LIS302DSH_DATA_RATE_800       (uint8_t)(0x80)
#define LIS302DSH_DATA_RATE_1600      (uint8_t)(0x90)

// Axis anbale
#define LIS302DSH_X_AXIS_ENABLE       (uint8_t)(0x01)
#define LIS302DSH_Y_AXIS_ENABLE       (uint8_t)(0x02)
#define LIS302DSH_Z_AXIS_ENABLE       (uint8_t)(0x04)
#define LIS302DSH_XYZ_AXIS_ENABLE     (uint8_t)(0x07)


// CTRL_REG5 İnternals

// BW filter
#define LIS302DSH_BW_800Hz             (uint8_t)(0x00)
#define LIS302DSH_BW_200Hz             (uint8_t)(0x40)
#define LIS302DSH_BW_400Hz             (uint8_t)(0x80)
#define LIS302DSH_BW_50Hz              (uint8_t)(0xC0)

// Full Scale
#define LIS302DSH_FULL_SCALE_2G        (uint8_t)(0x00)
#define LIS302DSH_FULL_SCALE_4G        (uint8_t)(0x08)
#define LIS302DSH_FULL_SCALE_6G        (uint8_t)(0x10)
#define LIS302DSH_FULL_SCALE_8G        (uint8_t)(0x18)
#define LIS302DSH_FULL_SCALE_16G       (uint8_t)(0x20)



#endif 