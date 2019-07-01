#include "lsm6dsl_def.h"
#include "LSM6DSLDriver.h"
#include "mbed_debug.h"

#define DEBUG_ERR_WRITE(res, reg)  debug_if(res, "LPS22HB write 0x%02X failed with result %ld\r\n", reg, res)
#define DEBUG_ERR_READ(res, reg)   debug_if(res, "LPS22HB read 0x%02X failed with result %ld\r\n", reg, res)

int32_t LSM6DSLDriver::read_id(uint8_t *id)
{  
    int ret = 0;
    char reg, val;
  
    /* Read WHO_AM_I */
    reg = LSM6DSL_REGISTER_WHO_AM_I;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret == 0) *id = (uint8_t)val;
    return ret;
}

int32_t LSM6DSLDriver::acc_init()
{
    int ret = 0;
    char reg, val, buf[2];
    uint8_t ctrl = 0x00;

    /* Configure MEMS: data rate, full scale  */
    ctrl =  (LSM6DSL_ODR_52Hz | LSM6DSL_ACC_FULLSCALE_2G);
    
    /* Configure MEMS: BDU and Auto-increment for multi read/write */
    ctrl |= ((LSM6DSL_BDU_BLOCK_UPDATE | LSM6DSL_ACC_GYRO_IF_INC_ENABLED) << 8);

    /* Read CTRL1_XL */
    reg = LSM6DSL_REGISTER_CTRL1_XL;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Write value to ACC MEMS CTRL1_XL register: FS and Data Rate */
    val &= ~(0xFC);
    val |= ctrl;
    buf[0] = LSM6DSL_REGISTER_CTRL1_XL;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);
    if (ret) return ret;

    /* Read CTRL3_C */
    reg = LSM6DSL_REGISTER_CTRL3_C;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Write value to ACC MEMS CTRL3_C register: BDU and Auto-increment */
    ctrl = ((uint8_t) (ctrl >> 8));
    val &= ~(0x44);
    val |= ctrl; 
    buf[0] = LSM6DSL_REGISTER_CTRL3_C;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);

    return ret;
}

int32_t LSM6DSLDriver::acc_deinit()
{
    int ret = 0;
    char reg, val, buf[2];
    
    /* Read CTRL1_XL */
    reg = LSM6DSL_REGISTER_CTRL1_XL;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Clear ODR bits */
    val &= ~(LSM6DSL_ODR_BITPOSITION);

    /* Set Power down */
    val |= LSM6DSL_ODR_POWER_DOWN;
    
    /* write back control register */
    buf[0] = LSM6DSL_REGISTER_CTRL1_XL;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);

    return ret;
}

int32_t LSM6DSLDriver::acc_set_low_power(bool enable)
{
    int ret = 0;
    char reg, val, buf[2];
    
    /* Read CTRL6_C */
    reg = LSM6DSL_REGISTER_CTRL6_C;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Clear Low Power Mode bit */
    val &= ~(0x10);

    /* Set Low Power Mode */
    if (enable) val |= LSM6DSL_ACC_GYRO_LP_XL_ENABLED;
    else        val |= LSM6DSL_ACC_GYRO_LP_XL_DISABLED;
    
    /* write back control register */
    buf[0] = LSM6DSL_REGISTER_CTRL6_C;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);

    return ret;
}

int32_t LSM6DSLDriver::acc_read_xyz(int16_t *x, int16_t *y, int16_t *z)
{
    int ret = 0;
    char reg, ctrlx, buf[6];
    int16_t raw[3];
    uint8_t i = 0;
    float sensitivity = 0;
    
    /* Read the acceleration control register content */
    reg = LSM6DSL_REGISTER_CTRL1_XL;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &ctrlx, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;
    
    /* Read output register X, Y & Z acceleration */
    reg = LSM6DSL_REGISTER_OUTX_L_XL;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, buf, 6);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;
    
    for (i = 0; i < 3; i++)
    {
        raw[i] = ((((uint16_t)buf[2 * i + 1]) << 8) + (uint16_t)buf[2 * i]);
    }
    
    /* Normal mode */
    /* Switch the sensitivity value set in the CRTL1_XL */
    switch(ctrlx & 0x0C)
    {
        case LSM6DSL_ACC_FULLSCALE_2G:
            sensitivity = LSM6DSL_ACC_SENSITIVITY_2G;
            break;
        case LSM6DSL_ACC_FULLSCALE_4G:
            sensitivity = LSM6DSL_ACC_SENSITIVITY_4G;
            break;
        case LSM6DSL_ACC_FULLSCALE_8G:
            sensitivity = LSM6DSL_ACC_SENSITIVITY_8G;
            break;
        case LSM6DSL_ACC_FULLSCALE_16G:
            sensitivity = LSM6DSL_ACC_SENSITIVITY_16G;
            break;    
    }
    
    /* Obtain the mg value for the three axis */
    *x = (int16_t)(raw[0] * sensitivity);
    *y = (int16_t)(raw[1] * sensitivity);
    *z = (int16_t)(raw[2] * sensitivity);

    return ret;
}


int32_t LSM6DSLDriver::gyro_init()
{
    int ret = 0;
    char reg, val, buf[2];
    uint8_t ctrl = 0x00;

    /* Configure MEMS: data rate, full scale  */
    ctrl = (LSM6DSL_GYRO_FS_2000 | LSM6DSL_ODR_52Hz);

    /* Configure MEMS: BDU and Auto-increment for multi read/write */
    ctrl |= ((LSM6DSL_BDU_BLOCK_UPDATE | LSM6DSL_ACC_GYRO_IF_INC_ENABLED) << 8);

    /* Read CTRL2_G */
    reg = LSM6DSL_REGISTER_CTRL2_G;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Write value to GYRO MEMS CTRL2_G register: FS and Data Rate */
    val &= ~(0xFC);
    val |= ctrl;
    buf[0] = LSM6DSL_REGISTER_CTRL2_G;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);
    if (ret) return ret;

    /* Read CTRL3_C */
    reg = LSM6DSL_REGISTER_CTRL3_C;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Write value to GYRO MEMS CTRL3_C register: BDU and Auto-increment */
    ctrl = ((uint8_t) (ctrl >> 8));
    val &= ~(0x44);
    val |= ctrl; 
    buf[0] = LSM6DSL_REGISTER_CTRL3_C;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);
    return ret;
}

int32_t LSM6DSLDriver::gyro_deinit()
{
    int ret = 0;
    char reg, val, buf[2];
    
    /* Read CTRL2_G */
    reg = LSM6DSL_REGISTER_CTRL2_G;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Clear ODR bits */
    val &= ~(LSM6DSL_ODR_BITPOSITION);

    /* Set Power down */
    val |= LSM6DSL_ODR_POWER_DOWN;
    
    /* write back control register */
    buf[0] = LSM6DSL_REGISTER_CTRL2_G;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);

    return ret;
}

int32_t LSM6DSLDriver::gyro_set_low_power(bool enable)
{
    int ret = 0;
    char reg, val, buf[2];
    
    /* Read CTRL7_G value */
    reg = LSM6DSL_REGISTER_CTRL7_G;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &val, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;

    /* Clear Low Power Mode bit */
    val &= ~(0x80);

    /* Set Low Power Mode */
    if (enable) val |= LSM6DSL_ACC_GYRO_LP_G_ENABLED;
    else        val |= LSM6DSL_ACC_GYRO_LP_G_DISABLED;
    
    /* write back control register */
    buf[0] = LSM6DSL_REGISTER_CTRL7_G;
    buf[1] = val;
    ret = i2c_driver->write(dev_addr, buf, 2);
    DEBUG_ERR_WRITE(ret, buf[0]);

    return ret;
}

int32_t LSM6DSLDriver::gyro_read_xyz(float *x, float *y, float *z)
{
    int ret = 0;
    char reg, ctrlg, buf[6];
    int16_t raw[3];
    uint8_t i = 0;
    float sensitivity = 0;
    
    /* Read the gyro control register content */
    reg = LSM6DSL_REGISTER_CTRL2_G;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, &ctrlg, 1);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;
    
    /* Read output register X, Y & Z acceleration */
    reg = LSM6DSL_REGISTER_OUTX_L_G;
    ret = i2c_driver->write(dev_addr, &reg, 1);
    DEBUG_ERR_WRITE(ret, reg);
    if (ret) return ret;
    ret = i2c_driver->read(dev_addr, buf, 6);
    DEBUG_ERR_READ(ret, reg);
    if (ret) return ret;
    
    for (i = 0; i < 3; i++)
    {
        raw[i] = ((((uint16_t)buf[2 * i + 1]) << 8) + (uint16_t)buf[2 * i]);
    }
    
    /* Normal mode */
    /* Switch the sensitivity value set in the CRTL2_G */
    switch(ctrlg & 0x0C)
    {
        case LSM6DSL_GYRO_FS_245:
            sensitivity = LSM6DSL_GYRO_SENSITIVITY_245DPS;
            break;
        case LSM6DSL_GYRO_FS_500:
            sensitivity = LSM6DSL_GYRO_SENSITIVITY_500DPS;
            break;
        case LSM6DSL_GYRO_FS_1000:
            sensitivity = LSM6DSL_GYRO_SENSITIVITY_1000DPS;
            break;
        case LSM6DSL_GYRO_FS_2000:
            sensitivity = LSM6DSL_GYRO_SENSITIVITY_2000DPS;
            break;    
    }
    
    /* Obtain the mg value for the three axis */
    *x = (float)(raw[0] * sensitivity);
    *y = (float)(raw[1] * sensitivity);
    *z = (float)(raw[2] * sensitivity);

    return ret;
}
