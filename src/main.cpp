#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "../include/WeatherEngine.hpp"
using namespace std;

void displayMenu();

void displayForecast(const vector<WeatherDay> &forecast);
void displayAverages(const vector<WeatherDay> &forecast);
void displayHottestDay(const vector<WeatherDay> &forecast);
void displayColdestDay(const vector<WeatherDay> &forecast);
void displayIdealDay(const vector<WeatherDay> &forecast);

int main()
{
    // Instantiate new class object
    WeatherEngine weather;

    cout << "--- Welcome to the Team Driver Sandbox ---"
         << endl;

    // Use WeatherEngine method .get7DayForecast (lat, lon) to return 7 WeatherDay structs;
    // Store structs in WeatherDay vector 'data'.

    vector<WeatherDay> data =
        weather.get7DayForecast(40.71, -74.00);

    // Use the 'data' vector to print, calculate, format, and build menus.

    // exception handling – if data vector is empty, no forecast information was extracted; inform user

    if (data.empty())
    {
        cout << "Weather data could not be loaded."
             << endl;

        return 1;
    }

    int choice;

    // Do-while is used so that the menus is shown before the first input is given

    do
    {
        displayMenu();

        // ===========================================================================
        /*

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        This line clears the input buffer. "Cin, you should ignore any input that came after the first
        valid integer, up to the maximum possible input size, indicated by the constant 'streamsize'."

       */
        // ===========================================================================

        while (!(cin >> choice))
        {
            cout
                << "Invalid input. Enter a number from 1 to 6: ";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Switch code blocks triggered by user input stored in 'choice'

        switch (choice)
        {
        case 1:
            displayForecast(data);
            break;

        case 2:
            displayAverages(data);
            break;

        case 3:
            displayHottestDay(data);
            break;

        case 4:
            displayColdestDay(data);
            break;

        case 5:
            displayIdealDay(data);
            break;

        case 6:
            cout
                << "\nThank you for using the Weather App!\n";
            break;

        default:
            cout
                << "\nPlease enter a number from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}

void displayMenu()
{
    cout << "\n=============================\n";
    cout << "      WEATHER APP MENU\n";
    cout << "=============================\n";
    cout << "1. Show 7-Day Forecast\n";
    cout << "2. Show Average Temperatures\n";
    cout << "3. Show Hottest Day\n";
    cout << "4. Show Coldest Day\n";
    cout << "5. Show Ideal Weather Day\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void displayForecast(const vector<WeatherDay> &forecast)
{
    cout << "\n7-Day Forecast\n";
    cout << "-----------------------------\n";

    cout << fixed << setprecision(1);

    // Modern for-loop – loop through each element of the vector 'data'
    // ensuring nothing inside the vector is changed (const). Detect the
    // data-type automatically. Each element we inspect is called 'day'.

    for (const auto &day : forecast)
    {
        cout << day.date
             << " | High: " << day.maxTemp
             << " | Low: " << day.minTemp
             << endl;
    }
}

void displayAverages(const vector<WeatherDay> &forecast)
{
    double totalHigh = 0.0;
    double totalLow = 0.0;

    for (const auto &day : forecast)
    {
        totalHigh += day.maxTemp;
        totalLow += day.minTemp;
    }

    double averageHigh = totalHigh / forecast.size();
    double averageLow = totalLow / forecast.size();

    cout << "\nAverage Temperatures\n";
    cout << "-----------------------------\n";

    cout << fixed << setprecision(1);

    cout << "Average high: "
         << averageHigh << endl;

    cout << "Average low: "
         << averageLow << endl;
}

void displayHottestDay(const vector<WeatherDay> &forecast)
{
    int hottestIndex = 0;

    for (int i = 1; i < static_cast<int>(forecast.size()); i++)
    {
        if (forecast[i].maxTemp > forecast[hottestIndex].maxTemp)
        {
            hottestIndex = i;
        }
    }

    cout << "\nHottest Day\n";
    cout << "-----------------------------\n";

    cout << "Date: "
         << forecast[hottestIndex].date << endl;

    cout << "High temperature: "
         << forecast[hottestIndex].maxTemp << endl;
}

void displayColdestDay(const vector<WeatherDay> &forecast)
{
    int coldestIndex = 0;

    for (int i = 1; i < static_cast<int>(forecast.size()); i++)
    {
        if (forecast[i].minTemp < forecast[coldestIndex].minTemp)
        {
            coldestIndex = i;
        }
    }

    cout << "\nColdest Day\n";
    cout << "-----------------------------\n";

    cout << "Date: "
         << forecast[coldestIndex].date << endl;

    cout << "Low temperature: "
         << forecast[coldestIndex].minTemp << endl;
}

void displayIdealDay(const vector<WeatherDay> &forecast)
{
    const double idealTemperature = 72.0;

    int idealIndex = 0;

    double firstAverage =
        (forecast[0].maxTemp + forecast[0].minTemp) / 2.0;

    double smallestDifference =
        abs(firstAverage - idealTemperature);

    for (int i = 1; i < static_cast<int>(forecast.size()); i++)
    {
        double dailyAverage =
            (forecast[i].maxTemp + forecast[i].minTemp) / 2.0;

        double difference =
            abs(dailyAverage - idealTemperature);

        if (difference < smallestDifference)
        {
            smallestDifference = difference;
            idealIndex = i;
        }
    }

    double idealAverage =
        (forecast[idealIndex].maxTemp +
         forecast[idealIndex].minTemp) /
        2.0;

    cout << "\nIdeal Weather Day\n";
    cout << "-----------------------------\n";

    cout << "Date: "
         << forecast[idealIndex].date << endl;

    cout << "High temperature: "
         << forecast[idealIndex].maxTemp << endl;

    cout << "Low temperature: "
         << forecast[idealIndex].minTemp << endl;

    cout << "Average temperature: "
         << idealAverage << endl;

    cout << "This day is closest to 72 degrees."
         << endl;
}