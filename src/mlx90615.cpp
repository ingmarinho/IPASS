#include <hwlib.hpp>
#include "mlx90615.h"

/// @file


mlx90615::mlx90615(hwlib::i2c_bus &bus, uint8_t i2c_address, double correction)
    : bus(bus), i2c_address(i2c_address), correction(correction)
{
}

/// \brief
/// Function to read bytes from the mlx90615.
/// \details
/// This function reads 3 bytes with the I2C interface and returns the 2 useful bytes in one combined uint16_t.
uint16_t mlx90615::read()
{
    uint16_t data;
    auto transaction = bus.read(i2c_address);                                                   // make I2C transaction to read bytes from the mlx90615 bus

    data = transaction.read_byte();                                                             // read low byte
    data |= transaction.read_byte() << 8;                                                       // read high byte and combine with low byte
    transaction.read_byte();                                                                    // PEC (useless byte)

    return data;
}

/// \brief
/// Function to write a byte to the mlx90615.
/// \details
/// This function writes to the mlx90615 with the I2C interface.
void mlx90615::write(uint8_t value)
{
    auto transaction = bus.write(i2c_address);                                                  // make I2C transaction to write to the corresponding I2C address
    transaction.prepare_repeated_start();                                                       // the mlx90615 requires a repeated start to function, so we enable that functionality (thanks wouter :D)
    transaction.write(value);                                                                   // write value to I2C bus
}

/// \brief
/// Function to read 2 bytes from a specific register on the mlx90615.
/// \details
/// This function reads 2 bytes from a specific register and returns it as one uint16_t.
uint16_t mlx90615::readWord16(registers reg)
{
    uint16_t data;

    write((uint8_t)reg);                                                                        // write transaction with bus to the correct register
    data = read();                                                                              // read transation with bus from the correct register

    return data;
}

/// \brief
/// Function to get the temperature in kelvin.
/// \details
/// This function gets the object temperature from the mlx90615 and returns it as a temperature object.
temperature mlx90615::getTemperatureData()
{
    return temperature((readWord16(registers::OBJECT_TEMPERATURE) * 0.02), correction);         // * 0.02 to get kelvin
}
