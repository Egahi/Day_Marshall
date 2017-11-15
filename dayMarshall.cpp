#include <iostream>

#include "dayMarshall.h"

using namespace std;

/**
 * welcomes the user and introduces the program
 */
void welcomeUser(void)
{
    cout << "\nHello, and welome."
         << "\n\nThis program takes in a date then outputs the day it is in the year."
         << "\ne.g 02/01/2017 is the 32nd day in year 2017"
         << "\n\nPlease enter a date to begin..." << endl; 
}
   
/**
 * prompts user for date in month/day/year format
 * calls function to validate date, and accepts only valid dates.
 */     
void getDate(int *month, int *day, int *year)
{
    // prompt for input until validate() returns true
    do
    {
        cout << "\nDate (month day year): ";
        cin >> *month >> *day >> *year;
        cin.ignore(15, '\n');
    }while(!validate(month, day, year));
}

/**
 * checks that input is a valid date
 * returns true if valid and false otherwise
 */
bool validate(int *month, int *day, int *year)
{   
    // 1 - 12 denotes valid monthss
    if(*month >= January && *month <= December)
    {
        switch(*month)
        {
            // months with only 30 days
            case April:
            case June:
            case September:
            case November:
                if(*day > 0 && *day < CJ)
                    return true;
            break;
            
            // months with 31 days
            case January:
            case March:
            case May:
            case July:
            case August:
            case October:
            case December:
                if(*day > 0 && *day <= CJ)
                    return true;
            break;
            
            case February:
                // february has 29 days in a leap year
                if (*year % 4 == 0 && *day > 0 && *day <= 29)
                   return true;
            
                // and 28 otherwise
                else if (*day > 0 && *day < 29)
                    return true;
             break;
        }
        
    }
    
    // date entered is invalid
    cout << "INVALID DATE!\n"
         << "(MONTH DAY YEAR)" << endl;
    return false;
}

/*
 * calculates the day in the year the entered date falls on.
 */
void calcDay(int month, int day, int year, int *yDay)
{
    // add cumulative days from 1st january to date in question
    switch(month)
    {
        case January:
            *yDay = day;
        break;
        
        // 31 days preceed all days in february
        case February:
                *yDay = day + CJ;
        break;
 
        case March:
            // 60 days preceed all days in march in a leap year
            if (year % 4 == 0)
                *yDay = day + CF;
            
            // 59 days otherwise
            else
                *yDay = day + CF - 1;
        break;
        
        case April:
            // 90 days preceed all days in april in a leap year
            if (year % 4 == 0)
                *yDay = day + CM;
            
            // 89 days otherwise
            else
                *yDay = day + CM - 1;
        break;
        
        case May:
            // 121 days preceed all days in march in a leap year
            if (year % 4 == 0)
                *yDay = day + CA;
            
            // 120 days otherwise
            else
                *yDay = day + CA - 1;
        break;
        
        case June:
            // 151 days preceed all days in june in a leap year
            if (year % 4 == 0)
                *yDay = day + CMY;
            
            // 150 days otherwise
            else
                *yDay = day + CMY - 1;
        break;
        
        case July:
            // 182 days preceed all days in july in a leap year
            if (year % 4 == 0)
                *yDay = day + CJE;
            
            // 181 days otherwise
            else
                *yDay = day + CJE;
        break;
        
        case August:
            // 213 days precced all days in august in a leap year
            if (year % 4 == 0)
                *yDay = day + CJY;
            
            // 212 days otherwise
            else
                *yDay = day + CJY - 1;
        break;
        
        case September:
            // 243 days preceed all days in september in a leap year
            if (year % 4 == 0)
                *yDay = day + CAT;
            
            // 242 days otherwise
            else
                *yDay = day + CAT - 1;
        break;
        
        case October:
            // 274 days preceed all days in october in a leap year
            if (year % 4 == 0)
                *yDay = day + CS;
            
            // 273 days otherwise
            else
                *yDay = day + CS - 1;
        break;
                   
        case November:
            // 304 days preceed all days in November in a leap year
            if (year % 4 == 0)
                *yDay = day + CO;
            
            // 303 days otherwise
            else
                *yDay = day + CO - 1;
        break;
        
        case December:
            // 335 days preceed all days in december in a leap year
            if (year % 4 == 0)
                *yDay = day + CN;
            // 334 days otherwise
            else
                *yDay = day + CN - 1;
        break;
    }
}

/**
 * prints out necessary information
 */
void printInfo(int month, int day, int year, int yDay)
{
    // days witht suffix 'st'
    if (yDay % 10 == 1)
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "st day of the year " << year << endl;
    }
    
    //days with siuffix 'nd'
    else if (yDay % 10 == 2)
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "nd day of the year " << year << endl;
    }
    
    // days with suffix 'rd'
    else if (yDay % 10 == 3)
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "rd day of the year " << year << endl;
    }
    
    // days with suffix 'th'
    else
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "th day of the year " << year << endl;
    }
}

/**
 * prompt to perform another operation.
 * returns true for yes and false otherwise
 */
bool runAgain(void)
{
    char ans;
    
    cout << "\n\nWant to perform another opertion? (enter Y for Yes)" << endl;
    cin >> ans;

    if (ans == 'Y' || ans == 'y')
        return true;

    return false;
}
