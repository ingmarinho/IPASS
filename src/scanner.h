#pragma once

#include <hwlib.hpp>
#include "mlx90615.h"

/// @file


/// \brief
/// Application class for the actual scanner.
/// \details
/// This class gives functionality to a mlx90615 by combining it's use with a oled display and a trigger.
class scanner
{
private:
    mlx90615 &MLX;                                      // mlx class to get temperature class
    hwlib::terminal_from &display;
    hwlib::target::pin_in &trigger;
    hwlib::target::pin_out &led;
    temperatureScale scale = temperatureScale::celsius; // default scale is celsius
    const unsigned int timeBeforeAlert;                 // time in seconds

public:
    scanner(mlx90615 &MLX, hwlib::terminal_from &display, hwlib::target::pin_in &trigger, hwlib::target::pin_out &led, const unsigned int timeBeforeAlert = 5);
    void changeScale(temperatureScale newScale);
    void readContinuous();
    void readSpecific();
    void showStandByScreen();
    void showTemperatureScreen(const char &temperatureUnit, const int &number, const int &fraction, const char *level, const bool &confirmed = false);
};
