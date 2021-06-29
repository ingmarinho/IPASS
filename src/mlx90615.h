#pragma once

#include <hwlib.hpp>
#include "temperature.h"


/// \brief
/// Class for communicating with the mlx90615.
/// \details
/// This class is responsible for the communication with the mlx90615 and getting temperature data.
class mlx90615
{
public:
    enum class registers : uint8_t                                  // all available registers on the mlx90615
    {
        // I2C
        I2CADDR                 = 0x5B,

        // TEMPS
        OBJECT_TEMPERATURE      = 0x27,
        AMBIENT_TEMPERATURE     = 0x26,

        // RAM
        RAWIR1                  = 0x04,
        RAWIR2                  = 0x05,
        TA                      = 0x06,
        TOBJ1                   = 0x07,
        TOBJ2                   = 0x08,

        // EEPROM
        TOMAX                   = 0x20,
        TOMIN                   = 0x21,
        PWMCTRL                 = 0x22,
        TARANGE                 = 0x23,
        EMISS                   = 0x24,
        CONFIG                  = 0x25,
        ADDR                    = 0x0E,
        ID1                     = 0x3C,
        ID2                     = 0x3D,
        ID3                     = 0x3E,
        ID4                     = 0x3F
    };

private:
    hwlib::i2c_bus &bus;
    uint8_t i2c_address;
    const double correction;

private:
    uint16_t read();
    void write(uint8_t value);
    uint16_t readWord16(registers reg);

public:
    mlx90615(hwlib::i2c_bus &bus, uint8_t i2c_address, double correction);
    temperature getTemperatureData();
};
