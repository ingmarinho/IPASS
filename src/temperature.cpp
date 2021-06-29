#include "temperature.h"

/// @file


/// \brief
/// Constructor which translates temperature data
/// \details
/// This constructor translates temperature data (in kelvin) to numbers, fractions and the complete temperatures in 3 different temperature scales.
temperature::temperature(double temperatureData, double correction) : temperatureInK(temperatureData + correction),
                                                                      numberInK((int)(temperatureData + correction)),
                                                                      fractionInK((int)((temperatureData + correction) * 10) % 10),
                                                                      temperatureInC((temperatureData - 273.15) + correction),
                                                                      numberInC((int)((temperatureData - 273.15) + correction)),
                                                                      fractionInC((int)(((temperatureData - 273.15) + correction) * 10) % 10),
                                                                      temperatureInF((((temperatureData * 1.8) - 459.67) + ((correction * 1.8) + 3))),
                                                                      numberInF((int)(((temperatureData * 1.8) - 459.67) + ((correction * 1.8) + 3))),
                                                                      fractionInF((int)((((temperatureData * 1.8) - 459.67) + ((correction * 1.8) + 3)) * 10) % 10)
{
}

/// \brief
/// Function for getting the temperature.
/// \details
/// This function returns the temperature in a specific temperature scale.
double temperature::getTemperature(temperatureScale scale)
{
    switch (scale)
    {
    case temperatureScale::kelvin:
        return temperatureInK;
    case temperatureScale::celsius:
        return temperatureInC;
    case temperatureScale::fahrenheit:
        return temperatureInF;
    default:
        return 0.0;
    }
}

/// \brief
/// Function for getting the temperature level.
/// \details
/// This function returns the temperature level (whether or not it's a normal human body temperature).
const char *temperature::getTemperatureLevel()
{
    if (temperatureInC > 37.5)
        return "HIGH";
    else if (temperatureInC < 36)
        return "LOW";
    else
        return "NORMAL";
}

/// \brief
/// Function for getting the temperature number.
/// \details
/// This function returns the temperature number in a specific temperature scale.
int temperature::getTemperatureNumber(temperatureScale scale)
{
    switch (scale)
    {
    case temperatureScale::kelvin:
        return numberInK;
    case temperatureScale::celsius:
        return numberInC;
    case temperatureScale::fahrenheit:
        return numberInF;
    default:
        return 0;
    }
}

/// \brief
/// Function for getting the temperature fraction.
/// \details
/// This function returns the temperature fraction in a specific temperature scale.
int temperature::getTemperatureFraction(temperatureScale scale)
{
    switch (scale)
    {
    case temperatureScale::kelvin:
        return fractionInK;
    case temperatureScale::celsius:
        return fractionInC;
    case temperatureScale::fahrenheit:
        return fractionInF;
    default:
        return 0;
    }
}

/// \brief
/// Function for getting the temperature unit.
/// \details
/// This function returns the temperature unit char in a specific temperature scale.
char temperature::getTemperatureUnit(temperatureScale scale)
{
    switch (scale)
    {
    case temperatureScale::celsius:
        return 'C';
    case temperatureScale::fahrenheit:
        return 'F';
    case temperatureScale::kelvin:
        return 'K';
    default:
        return '0';
    }
}
