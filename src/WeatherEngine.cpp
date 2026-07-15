#include "../include/WeatherEngine.hpp"
#include "../include/json.hpp"
#include <curl/curl.h>
#include <iostream>


using json = nlohmann::json;

WeatherEngine::WeatherEngine() {
    // Initialize global curl environment if needed
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

WeatherEngine::~WeatherEngine() {
    curl_global_cleanup();
}

// Private helper to stream internet data into our string buffer
size_t WeatherEngine::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}
std::vector<WeatherDay> WeatherEngine::get7DayForecast(double lat, double lon) {
    std::vector<WeatherDay> forecast;
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if(curl) {
        std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + std::to_string(lat) + 
                          "&longitude=" + std::to_string(lon) + 
                          "&daily=temperature_2m_max,temperature_2m_min&forecast_days=7&timezone=auto";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        
        if(res == CURLE_OK) {
            try {
                auto data = json::parse(readBuffer);
                auto dates = data["daily"]["time"];
                auto max_temps = data["daily"]["temperature_2m_max"];
                auto min_temps = data["daily"]["temperature_2m_min"];
                
                for (size_t i = 0; i < dates.size(); ++i) {
                    WeatherDay day;
                    day.date = dates[i];
                    day.maxTemp = max_temps[i];
                    day.minTemp = min_temps[i];
                    forecast.push_back(day); 
                }
            } catch (json::parse_error& e) {
                std::cerr << "Engine JSON Parse Error: " << e.what() << std::endl;
            }
        }
        curl_easy_cleanup(curl);
    }
    return forecast;
}
