#pragma once

enum class temperatureScale                                             // enum class that contains the possible scales in which temperature data can be displayed
{
    kelvin,
    celsius,
    fahrenheit
};

/// \brief
/// Temperature class that manipulates temperature data.
/// \details
/// This class is can output temperature data in various ways.
class temperature
{
private:
    const double temperatureInK;
    const int numberInK;
    const int fractionInK;

    const double temperatureInC;
    const int numberInC;
    const int fractionInC;

    const double temperatureInF;
    const int numberInF;
    const int fractionInF;

public:
    temperature(double temperatureData, double correction = 0.0);
    double getTemperature(temperatureScale scale);
    const char *getTemperatureLevel();
    int getTemperatureNumber(temperatureScale scale);
    int getTemperatureFraction(temperatureScale scale);
    char getTemperatureUnit(temperatureScale scale);
};
