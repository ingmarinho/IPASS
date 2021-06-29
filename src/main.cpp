#include <hwlib.hpp>
#include "mlx90615.h"
#include "scanner.h"

int main()
{
    const double correction = 4.5;                                                                  // correction value to get more accurate results from the temperature sensor
    auto scl_mlx = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda_mlx = hwlib::target::pin_oc(hwlib::target::pins::sda);

    auto i2c_bus_mlx = hwlib::i2c_bus_bit_banged_scl_sda(scl_mlx, sda_mlx);
    mlx90615 mlx(i2c_bus_mlx, 0x5b, correction);

    auto scl_oled = hwlib::target::pin_oc(hwlib::target::pins::d9);
    auto sda_oled = hwlib::target::pin_oc(hwlib::target::pins::d10);

    auto i2c_bus_oled = hwlib::i2c_bus_bit_banged_scl_sda(scl_oled, sda_oled);
    auto oled = hwlib::glcd_oled(i2c_bus_oled, 0x3c);
    auto font = hwlib::font_default_16x16();
    auto display = hwlib::terminal_from(oled, font);
    
    auto led = hwlib::target::pin_out(hwlib::target::pins::d8);
    auto trigger = hwlib::target::pin_in(hwlib::target::pins::d19);
    const unsigned int timeBeforeAlert = 5;                                                         // sets the time to which the readSpecific function will stop scanning

    scanner scanner(mlx, display, trigger, led, timeBeforeAlert);

    scanner.changeScale(temperatureScale::celsius);                                                 // change the temperature scale if needed

    // scanner.readContinuous();
    scanner.readSpecific();
}
