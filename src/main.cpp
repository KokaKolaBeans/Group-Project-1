#include <iostream>
#include "../include/WeatherEngine.hpp"

int main() {
    // Instantiating your new Class object

    
    WeatherEngine weather;

    std::cout << "--- Welcome to the Team Driver Sandbox ---" << std::endl;
    
    // Example call to your class engine (NJ/NY region coordinates)
    std::vector<WeatherDay> data = weather.get7DayForecast(40.71, -74.00);

    // YOUR TEAM TAKES OVER HERE: 
    // They utilize the 'data' vector to print, calculate, format, or build menus.
    if (!data.empty()) {
        std::cout << "Engine connection verified. Data successfully loaded for " 
                  << data.size() << " days." << std::endl;
    }

    return 0;
}

// cd .. && g++ src/main.cpp -lcurl -std=c++11 -o weather_app && ./weather_app