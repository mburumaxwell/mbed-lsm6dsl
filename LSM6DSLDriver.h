#ifndef __LSM6DSL_DRIVER_H
#define __LSM6DSL_DRIVER_H
#include <mbed.h>

class LSM6DSLDriver {
public:
    LSM6DSLDriver(I2C *driver, int32_t addr = 0xD4)
    {
        this->i2c_driver = driver;
        this->dev_addr = addr;
    }
    int32_t read_id(uint8_t *id);

    int32_t acc_init();
    int32_t acc_deinit();
    int32_t acc_set_low_power(bool enable);
    int32_t acc_read_xyz(int16_t *x, int16_t *y, int16_t *z);
    
    int32_t gyro_init();
    int32_t gyro_deinit();
    int32_t gyro_set_low_power(bool enable);
    int32_t gyro_read_xyz(float *x, float *y, float *z);

private:
    I2C *i2c_driver;
    int32_t dev_addr;
};

#endif /* __LSM6DSL_DRIVER_H */