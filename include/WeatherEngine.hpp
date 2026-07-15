#ifndef WEATHER_ENGINE_HPP
#define WEATHER_ENGINE_HPP

#include <string>
#include <vector>

// =========================================================================================================
// WeatherDay is a struct (a custom data structure) that provides date, maxTemp, and minTemp for a given day
//
// =========================================================================================================

struct WeatherDay {
    std::string date;
    double maxTemp;
    double minTemp;
};                                    

// =====================================================================================================================================
// Weather engine uses an API (OpenMeteo) to grab weather forecast data for 7 days, including today
// TO USE IN MAIN:
// 1. Create object --> WeatherEngine ForecastGenerator;
// 2. Run get7DayForecast function to generate a 7-element forecast vector containing WeatherDay structs; save this vector to a variable
//.     --> vector<WeatherDay> myForecast = ForecastGenerator.get7DayForecast(40.71, -74.00)
// 3. Use myForecast[i].date, myForecast[i].maxTemp, myForecast[i].minTemp to get specific data
// =====================================================================================================================================


class WeatherEngine {
public:

// =========================================================================================================================================
//                                                            default constructor
// =========================================================================================================================================
    WeatherEngine();    
     
// =========================================================================================================================================
//                   destructor – closes network and erases extraneous data upon task completion (when the object 'dies')
// =========================================================================================================================================

    ~WeatherEngine();    

// =========================================================================================================================================
// MVP function – latitude and longitude as input (40.71, -74.00) for NY area; returns 7-vector containing a WeatherDay struct in each spot
// =========================================================================================================================================

    std::vector<WeatherDay> get7DayForecast(double lat, double lon); // The bread and butter 

private:

// =========================================================================================================================================
//                                                          Network stuff – IGNORE
// =========================================================================================================================================

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
};

#endif