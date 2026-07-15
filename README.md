## Group Project 1 - Weather App Project!

Yo TJ!

I can be the project manager and you can be the lead coder if you want. Don't think those titles really matter but they are technically part of the project prompt lol.

## Purpose

**Build a weather app that will scrape real-time forecast data from the internet (using the Open-Meteo API).**

## Terminal Command for Compiling and Running the Project:

g++ src/main.cpp src/WeatherEngine.cpp -lcurl -std=c++11 -o weather_app && ./weather_app

*Note: If you add more files etc. just ask Gemini to generate a new terminal command so you can easily run and compile*

## Set Up and Using Githib 

**I KNOW THIS LOOKS LIKE A PAIN IN THE A/*/* BUT I PROMISE IT'LL TAKE LIKE 10 MIN AND IT'S SO WORTH IT**

First thing: Generate a GitHub Personal Access Token. 

Log into Github ––> Settings (click profile icon top-right) --> Developer settings (bottom left) --> Personal access tokens --> Tokens (classic) --> Generate new token (classic) --> Give it a name "CS Project" --> Check the repo box at the top --> Generate token --> **Copy the token immediately and save it somewhere secure! You will paste this into the terminal whenever Git prompts you for your password.**

TYPE THESE COMMANDS INTO YOUR TERMINAL (MAC) OR VSCODE TERMINAL (WINDOWS)

**First time–setting up Github on your machine**

1) git config --global user.name "Your Name"
2) git config --global user.email "your.email@example.com"

Clone repository on your machine. Grab the repo URL by hitting the Code button in Github:

3) cd Documents
4) git clone <PASTE_GITHUB_REPOSITORY_URL_HERE>
5) paste credentials–put in Personal Access Token instead of password

Step inside the newly-created repository

6) cd Group-Project-1

Test-compile and run the project to ensure everything downloaded properly

7) g++ src/main.cpp src/WeatherEngine.cpp -lcurl -std=c++11 -o weather_app && ./weather_app

**Using Github on the daily:**

# BEFORE starting any work (downloads your latest changes):
git pull origin main

# AFTER writing code in src/main.cpp and verifying it compiles:

1) git add -A 
   - Updates entire package --> replace '-A' with 'src/main.cpp' to update driver only

2) git commit -m "describe changes"

3) git push origin main

## Project Details

1) Gemini created a WeatherEngine class for me. You DO NOT need to understand how this object works --> the only function that matters is .get7DayForecast(). Essentially, it will provide the raw data we will use in our functions and our main driver. 

   --> *Go to WeatherEngine.hpp (the header file) now to see thorough details on exactly what this class/helper function does*
   --> *Understand how to instantiate the class. Input the proper lon and lat coordinates when doing so. Understand how to call and utilize .get7DayForecast()*

2) Functions and main driver should be written inside main.cpp in the src folder. If you'd like to create large, complex functions, feel free to split them into .hpp and .cpp files in the 'include' and 'src' folders separately.

3) If you'd like to create additional classes, split them into .hpp and .cpp files in the 'include' and 'src' folders separately.

## To do 
1) Create a menu using do-while in main to determine what the user would like to do with the program

2) A few ideas for functions we can make:
    - Average High for the week
    - Average Lo for the week
    - Diurnal variation (High-Low) for each day ––> Highlight the day with the most dramatic temperatur eswing
    - Seven Day Moving Average
    - The "Ideal Day" Index
    - Weather trend detection
    - Find highest and lowest temp in week

3) TJ–Why don't you work on creating 3-4 functions and basic user interface (star writing the menu for the functions you've created, create titles for the sections etc) and I can write whatever functions you don't wind up getting to? That way I can use the structure of your code rather than rewriting variables/data/functions from scratch?


I think that just about gives us a solid game plan for getting this project done.

Please text/call 732-598-9011 or email Kazimzaidi2010@gmail.com any time!

