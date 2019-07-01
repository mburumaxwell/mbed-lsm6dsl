#ifndef __LSM6DSL_DEF_H
#define __LSM6DSL_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

// /* Registers */
#define LSM6DSL_REGISTER_FUNC_CFG_ACCESS            (uint8_t)0x01
#define LSM6DSL_REGISTER_SENSOR_SYNC_TIME_FRAME     (uint8_t)0x04
#define LSM6DSL_REGISTER_SENSOR_SYNC_RES_RATIO      (uint8_t)0x05
#define LSM6DSL_REGISTER_FIFO_CTRL1                 (uint8_t)0x06
#define LSM6DSL_REGISTER_FIFO_CTRL2                 (uint8_t)0x07
#define LSM6DSL_REGISTER_FIFO_CTRL3                 (uint8_t)0x08
#define LSM6DSL_REGISTER_FIFO_CTRL4                 (uint8_t)0x09
#define LSM6DSL_REGISTER_FIFO_CTRL5                 (uint8_t)0x0A
#define LSM6DSL_REGISTER_DRDY_PULSE_CFG_G           (uint8_t)0x0B
#define LSM6DSL_REGISTER_INT1_CTRL                  (uint8_t)0x0D
#define LSM6DSL_REGISTER_INT2_CTRL                  (uint8_t)0x0E
#define LSM6DSL_REGISTER_WHO_AM_I                   (uint8_t)0x0F // Device identification
#define LSM6DSL_REGISTER_CTRL1_XL                   (uint8_t)0x10
#define LSM6DSL_REGISTER_CTRL2_G                    (uint8_t)0x11
#define LSM6DSL_REGISTER_CTRL3_C                    (uint8_t)0x12
#define LSM6DSL_REGISTER_CTRL4_C                    (uint8_t)0x13
#define LSM6DSL_REGISTER_CTRL5_C                    (uint8_t)0x14
#define LSM6DSL_REGISTER_CTRL6_C                    (uint8_t)0x15
#define LSM6DSL_REGISTER_CTRL7_G                    (uint8_t)0x16
#define LSM6DSL_REGISTER_CTRL8_XL                   (uint8_t)0x17
#define LSM6DSL_REGISTER_CTRL9_XL                   (uint8_t)0x18
#define LSM6DSL_REGISTER_CTRL10_C                   (uint8_t)0x19
#define LSM6DSL_REGISTER_MASTER_CONFIG              (uint8_t)0x1A
#define LSM6DSL_REGISTER_WAKE_UP_SRC                (uint8_t)0x1B
#define LSM6DSL_REGISTER_TAP_SRC                    (uint8_t)0x1C
#define LSM6DSL_REGISTER_D6D_SRC                    (uint8_t)0x1D
#define LSM6DSL_REGISTER_STATUS_REG                 (uint8_t)0x1E
#define LSM6DSL_REGISTER_OUT_TEMP_L                 (uint8_t)0x20
#define LSM6DSL_REGISTER_OUT_TEMP_H                 (uint8_t)0x21
#define LSM6DSL_REGISTER_OUTX_L_G                   (uint8_t)0x22
#define LSM6DSL_REGISTER_OUTX_H_G                   (uint8_t)0x23
#define LSM6DSL_REGISTER_OUTY_L_G                   (uint8_t)0x24
#define LSM6DSL_REGISTER_OUTY_H_G                   (uint8_t)0x25
#define LSM6DSL_REGISTER_OUTZ_L_G                   (uint8_t)0x26
#define LSM6DSL_REGISTER_OUTZ_H_G                   (uint8_t)0x27
#define LSM6DSL_REGISTER_OUTX_L_XL                  (uint8_t)0x28
#define LSM6DSL_REGISTER_OUTX_H_XL                  (uint8_t)0x29
#define LSM6DSL_REGISTER_OUTY_L_XL                  (uint8_t)0x2A
#define LSM6DSL_REGISTER_OUTY_H_XL                  (uint8_t)0x2B
#define LSM6DSL_REGISTER_OUTZ_L_XL                  (uint8_t)0x2C
#define LSM6DSL_REGISTER_OUTZ_H_XL                  (uint8_t)0x2D
#define LSM6DSL_REGISTER_SENSORHUB1_REG             (uint8_t)0x2E
#define LSM6DSL_REGISTER_SENSORHUB2_REG             (uint8_t)0x2F
#define LSM6DSL_REGISTER_SENSORHUB3_REG             (uint8_t)0x30
#define LSM6DSL_REGISTER_SENSORHUB4_REG             (uint8_t)0x31
#define LSM6DSL_REGISTER_SENSORHUB5_REG             (uint8_t)0x32
#define LSM6DSL_REGISTER_SENSORHUB6_REG             (uint8_t)0x33
#define LSM6DSL_REGISTER_SENSORHUB7_REG             (uint8_t)0x34
#define LSM6DSL_REGISTER_SENSORHUB8_REG             (uint8_t)0x35
#define LSM6DSL_REGISTER_SENSORHUB9_REG             (uint8_t)0x36
#define LSM6DSL_REGISTER_SENSORHUB10_REG            (uint8_t)0x37
#define LSM6DSL_REGISTER_SENSORHUB11_REG            (uint8_t)0x38
#define LSM6DSL_REGISTER_SENSORHUB12_REG            (uint8_t)0x39
#define LSM6DSL_REGISTER_FIFO_STATUS1               (uint8_t)0x3A
#define LSM6DSL_REGISTER_FIFO_STATUS2               (uint8_t)0x3B
#define LSM6DSL_REGISTER_FIFO_STATUS3               (uint8_t)0x3C
#define LSM6DSL_REGISTER_FIFO_STATUS4               (uint8_t)0x3D
#define LSM6DSL_REGISTER_FIFO_DATA_OUT_L            (uint8_t)0x3E
#define LSM6DSL_REGISTER_FIFO_DATA_OUT_H            (uint8_t)0x3F
#define LSM6DSL_REGISTER_TIMESTAMP0_REG             (uint8_t)0x40
#define LSM6DSL_REGISTER_TIMESTAMP1_REG             (uint8_t)0x41
#define LSM6DSL_REGISTER_TIMESTAMP2_REG             (uint8_t)0x42
#define LSM6DSL_REGISTER_STEP_TIMESTAMP_L           (uint8_t)0x49
#define LSM6DSL_REGISTER_STEP_TIMESTAMP_H           (uint8_t)0x4A
#define LSM6DSL_REGISTER_STEP_COUNTER_L             (uint8_t)0x4B
#define LSM6DSL_REGISTER_STEP_COUNTER_H             (uint8_t)0x4C
#define LSM6DSL_REGISTER_SENSORHUB13_REG            (uint8_t)0x4D
#define LSM6DSL_REGISTER_SENSORHUB14_REG            (uint8_t)0x4E
#define LSM6DSL_REGISTER_SENSORHUB15_REG            (uint8_t)0x4F
#define LSM6DSL_REGISTER_SENSORHUB16_REG            (uint8_t)0x50
#define LSM6DSL_REGISTER_SENSORHUB17_REG            (uint8_t)0x51
#define LSM6DSL_REGISTER_SENSORHUB18_REG            (uint8_t)0x52
#define LSM6DSL_REGISTER_FUNC_SRC1                  (uint8_t)0x53
#define LSM6DSL_REGISTER_FUNC_SRC2                  (uint8_t)0x54
#define LSM6DSL_REGISTER_WRIST_TILT_IA              (uint8_t)0x55
#define LSM6DSL_REGISTER_TAP_CFG                    (uint8_t)0x58
#define LSM6DSL_REGISTER_TAP_THS_6D                 (uint8_t)0x59
#define LSM6DSL_REGISTER_INT_DUR2                   (uint8_t)0x5A
#define LSM6DSL_REGISTER_WAKE_UP_THS                (uint8_t)0x5B
#define LSM6DSL_REGISTER_WAKE_UP_DUR                (uint8_t)0x5C
#define LSM6DSL_REGISTER_FREE_FALL                  (uint8_t)0x5D
#define LSM6DSL_REGISTER_MD1_CFG                    (uint8_t)0x5E
#define LSM6DSL_REGISTER_MD2_CFG                    (uint8_t)0x5F
#define LSM6DSL_REGISTER_MASTER_CMD_CODE            (uint8_t)0x60
#define LSM6DSL_REGISTER_SENS_SYNC_SPI_ERROR_CODE   (uint8_t)0x61
#define LSM6DSL_REGISTER_OUT_MAG_RAW_X_L            (uint8_t)0x66
#define LSM6DSL_REGISTER_OUT_MAG_RAW_X_H            (uint8_t)0x67
#define LSM6DSL_REGISTER_OUT_MAG_RAW_Y_L            (uint8_t)0x68
#define LSM6DSL_REGISTER_OUT_MAG_RAW_Y_H            (uint8_t)0x69
#define LSM6DSL_REGISTER_OUT_MAG_RAW_Z_L            (uint8_t)0x6A
#define LSM6DSL_REGISTER_OUT_MAG_RAW_Z_H            (uint8_t)0x6B
#define LSM6DSL_REGISTER_X_OFS_USR                  (uint8_t)0x73
#define LSM6DSL_REGISTER_Y_OFS_USR                  (uint8_t)0x74
#define LSM6DSL_REGISTER_Z_OFS_USR                  (uint8_t)0x75

// #define LSM6DSL_BIT(x) ((uint8_t)x) /* Bitfield positioning. */

/* WHO_AM_I Register */
#define LSM6DSL_WHO_AM_I_VALUE           (uint8_t)0x6A

/************** Embedded functions register mapping  *******************/
#define LSM6DSL_ACC_GYRO_SLV0_ADD                     0x02
#define LSM6DSL_ACC_GYRO_SLV0_SUBADD                  0x03
#define LSM6DSL_ACC_GYRO_SLAVE0_CONFIG                0x04
#define LSM6DSL_ACC_GYRO_SLV1_ADD                     0x05
#define LSM6DSL_ACC_GYRO_SLV1_SUBADD                  0x06
#define LSM6DSL_ACC_GYRO_SLAVE1_CONFIG                0x07
#define LSM6DSL_ACC_GYRO_SLV2_ADD                     0x08
#define LSM6DSL_ACC_GYRO_SLV2_SUBADD                  0x09
#define LSM6DSL_ACC_GYRO_SLAVE2_CONFIG                0x0A
#define LSM6DSL_ACC_GYRO_SLV3_ADD                     0x0B
#define LSM6DSL_ACC_GYRO_SLV3_SUBADD                  0x0C
#define LSM6DSL_ACC_GYRO_SLAVE3_CONFIG                0x0D
#define LSM6DSL_ACC_GYRO_DATAWRITE_SRC_MODE_SUB_SLV0  0x0E
#define LSM6DSL_ACC_GYRO_CONFIG_PEDO_THS_MIN          0x0F

#define LSM6DSL_ACC_GYRO_SM_STEP_THS                  0x13
#define LSM6DSL_ACC_GYRO_PEDO_DEB_REG                 0x14
#define LSM6DSL_ACC_GYRO_STEP_COUNT_DELTA             0x15

#define LSM6DSL_ACC_GYRO_MAG_SI_XX                    0x24
#define LSM6DSL_ACC_GYRO_MAG_SI_XY                    0x25
#define LSM6DSL_ACC_GYRO_MAG_SI_XZ                    0x26
#define LSM6DSL_ACC_GYRO_MAG_SI_YX                    0x27
#define LSM6DSL_ACC_GYRO_MAG_SI_YY                    0x28
#define LSM6DSL_ACC_GYRO_MAG_SI_YZ                    0x29
#define LSM6DSL_ACC_GYRO_MAG_SI_ZX                    0x2A
#define LSM6DSL_ACC_GYRO_MAG_SI_ZY                    0x2B
#define LSM6DSL_ACC_GYRO_MAG_SI_ZZ                    0x2C
#define LSM6DSL_ACC_GYRO_MAG_OFFX_L                   0x2D
#define LSM6DSL_ACC_GYRO_MAG_OFFX_H                   0x2E
#define LSM6DSL_ACC_GYRO_MAG_OFFY_L                   0x2F
#define LSM6DSL_ACC_GYRO_MAG_OFFY_H                   0x30
#define LSM6DSL_ACC_GYRO_MAG_OFFZ_L                   0x31
#define LSM6DSL_ACC_GYRO_MAG_OFFZ_H                   0x32

/* Accelero Full_ScaleSelection */
#define LSM6DSL_ACC_FULLSCALE_2G          ((uint8_t)0x00) /*!< �2 g */
#define LSM6DSL_ACC_FULLSCALE_4G          ((uint8_t)0x08) /*!< �4 g */
#define LSM6DSL_ACC_FULLSCALE_8G          ((uint8_t)0x0C) /*!< �8 g */
#define LSM6DSL_ACC_FULLSCALE_16G         ((uint8_t)0x04) /*!< �16 g */

/* Accelero Full Scale Sensitivity */
#define LSM6DSL_ACC_SENSITIVITY_2G     ((float)0.061f)  /*!< accelerometer sensitivity with 2 g full scale  [mgauss/LSB] */
#define LSM6DSL_ACC_SENSITIVITY_4G     ((float)0.122f)  /*!< accelerometer sensitivity with 4 g full scale  [mgauss/LSB] */
#define LSM6DSL_ACC_SENSITIVITY_8G     ((float)0.244f)  /*!< accelerometer sensitivity with 8 g full scale  [mgauss/LSB] */
#define LSM6DSL_ACC_SENSITIVITY_16G    ((float)0.488f)  /*!< accelerometer sensitivity with 12 g full scale [mgauss/LSB] */

/* Accelero Power Mode selection */
#define LSM6DSL_ACC_GYRO_LP_XL_DISABLED     ((uint8_t)0x00) /* LP disabled*/
#define LSM6DSL_ACC_GYRO_LP_XL_ENABLED      ((uint8_t)0x10) /* LP enabled*/

/* Output Data Rate */
#define LSM6DSL_ODR_BITPOSITION      ((uint8_t)0xF0)  /*!< Output Data Rate bit position */  
#define LSM6DSL_ODR_POWER_DOWN       ((uint8_t)0x00) /* Power Down mode       */
#define LSM6DSL_ODR_13Hz             ((uint8_t)0x10) /* Low Power mode        */
#define LSM6DSL_ODR_26Hz             ((uint8_t)0x20) /* Low Power mode        */ 
#define LSM6DSL_ODR_52Hz             ((uint8_t)0x30) /* Low Power mode        */
#define LSM6DSL_ODR_104Hz            ((uint8_t)0x40) /* Normal mode           */
#define LSM6DSL_ODR_208Hz            ((uint8_t)0x50) /* Normal mode           */
#define LSM6DSL_ODR_416Hz            ((uint8_t)0x60) /* High Performance mode */
#define LSM6DSL_ODR_833Hz            ((uint8_t)0x70) /* High Performance mode */
#define LSM6DSL_ODR_1660Hz           ((uint8_t)0x80) /* High Performance mode */
#define LSM6DSL_ODR_3330Hz           ((uint8_t)0x90) /* High Performance mode */
#define LSM6DSL_ODR_6660Hz           ((uint8_t)0xA0) /* High Performance mode */ 

/* Gyro Full Scale Selection */
#define LSM6DSL_GYRO_FS_245            ((uint8_t)0x00)  
#define LSM6DSL_GYRO_FS_500            ((uint8_t)0x04)  
#define LSM6DSL_GYRO_FS_1000           ((uint8_t)0x08)  
#define LSM6DSL_GYRO_FS_2000           ((uint8_t)0x0C)

/* Gyro Full Scale Sensitivity */ 
#define LSM6DSL_GYRO_SENSITIVITY_245DPS            ((float)8.750f) /**< Sensitivity value for 245 dps full scale  [mdps/LSB] */ 
#define LSM6DSL_GYRO_SENSITIVITY_500DPS            ((float)17.50f) /**< Sensitivity value for 500 dps full scale  [mdps/LSB] */ 
#define LSM6DSL_GYRO_SENSITIVITY_1000DPS           ((float)35.00f) /**< Sensitivity value for 1000 dps full scale [mdps/LSB] */ 
#define LSM6DSL_GYRO_SENSITIVITY_2000DPS           ((float)70.00f) /**< Sensitivity value for 2000 dps full scale [mdps/LSB] */ 

/* Gyro Power Mode selection */
#define LSM6DSL_ACC_GYRO_LP_G_DISABLED     ((uint8_t)0x00) /* LP disabled*/
#define LSM6DSL_ACC_GYRO_LP_G_ENABLED      ((uint8_t)0x80) /* LP enabled*/

/* Block Data Update */  
#define LSM6DSL_BDU_CONTINUOS               ((uint8_t)0x00)
#define LSM6DSL_BDU_BLOCK_UPDATE            ((uint8_t)0x40)

/* Auto-increment */
#define LSM6DSL_ACC_GYRO_IF_INC_DISABLED    ((uint8_t)0x00)
#define LSM6DSL_ACC_GYRO_IF_INC_ENABLED     ((uint8_t)0x04)


#ifdef __cplusplus
}
#endif

#endif /* __LSM6DSL_DEF_H */
