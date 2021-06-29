#include "scanner.h"

/// @file


scanner::scanner(mlx90615 &MLX, hwlib::terminal_from &display, hwlib::target::pin_in &trigger, hwlib::target::pin_out &led, const unsigned int timeBeforeAlert)
    : MLX(MLX), display(display), trigger(trigger), led(led), timeBeforeAlert(timeBeforeAlert)
{
}


/// \brief
/// Function to change the scale.
/// \details
/// This function changes the current scale that is shown on screen to fahrenheit, celsius or kelvin.
void scanner::changeScale(temperatureScale newScale)
{
    scale = newScale;
}

/// \brief
/// Function to continuously read the temperature.
/// \details
/// This function will continuously scan and show the measured temperature with a toggle based system.
void scanner::readContinuous()
{
    while (true)
    {
        bool triggered = false;

        if (!trigger.read())                                                                        // wait for trigger down and toggle ON
        {
            triggered = true;
            hwlib::wait_ms(250);
        }

        while (triggered)                                                                           // while toggled, keep scanning the temperature
        {
            if (!trigger.read())                                                                    // wait for trigger down and toggle OFF
            {
                triggered = false;
                hwlib::wait_ms(250);
            }

            temperature data = MLX.getTemperatureData();                                            // get the measured temperature data
            const char temperatureUnit = data.getTemperatureUnit(scale);
            const int number = data.getTemperatureNumber(scale);
            const int fraction = data.getTemperatureFraction(scale);
            const char *level = data.getTemperatureLevel();

            scanner::showTemperatureScreen(temperatureUnit, number, fraction, level);               // show the temperature data on screen
            led.write(1);

            hwlib::wait_ms(10);
        }

        scanner::showStandByScreen();                                                               // show stand-by screen whilst not toggled ON
        led.write(0);

        hwlib::wait_ms(10);
    }
}

/// \brief
/// Function to read the temperature for a specific time.
/// \details
/// This function reads the temperature whilst the trigger is down for an x amount of time.
/// After the elapsed time it will keep showing the last recorded temperature on screen.
void scanner::readSpecific()
{
    while (true)
    {
        unsigned int timer = 0;                                                                     // timer variable to keep track of how many seconds have passed

        while (!trigger.read())
        {
            temperature data = MLX.getTemperatureData();                                            // get the measured temperature data
            const char temperatureUnit = data.getTemperatureUnit(scale);
            const int number = data.getTemperatureNumber(scale);
            const int fraction = data.getTemperatureFraction(scale);
            const char *level = data.getTemperatureLevel();

            scanner::showTemperatureScreen(temperatureUnit, number, fraction, level);               // while the timer hasn't reached it's limit, keep showing/measuring the temperature
            led.write(1);

            hwlib::wait_ms(10);

            while (timer >= (timeBeforeAlert * 4) && !trigger.read())                                // check if the timer has reached it's limit and show the 'confirmed' temperature data
            {
                scanner::showTemperatureScreen(temperatureUnit, number, fraction, level, true);
                led.write(1);

                hwlib::wait_ms(10);
            }

            timer++;
        }

        scanner::showStandByScreen();                                                               // while trigger isn't down show stand-by screen
        led.write(0);

        hwlib::wait_ms(10);
    }
}

/// \brief
/// Function to show stand-by screen.
/// \details
/// This function shows a stand-by screen on screen.
void scanner::showStandByScreen()
{
    display << "\f"
            << "ON\n"
            << "STANDBY"
            << hwlib::flush;
}

/// \brief
/// Function to show the actual temperature data on screen.
/// \details
/// This function is used by scan functions above to show temperature data on screen.
void scanner::showTemperatureScreen(const char &temperatureUnit, const int &number, const int &fraction, const char *level, const bool &confirmed)
{
    confirmed ? display << "\f"                                                                     // depending on whether or not its a 'confirmed temperature'                                                                         
                        << "RECORDED\n"                                                             // it'll show the correctly formatted temperature data
                        << "TEMP:\n"
                        << number << '.' << fraction << temperatureUnit << "\n"
                        << '=' << level << hwlib::flush
              : display << "\f"
                        << "TEMP:\n"
                        << number << '.' << fraction << temperatureUnit << "\n\n"
                        << '=' << level << hwlib::flush;
}
