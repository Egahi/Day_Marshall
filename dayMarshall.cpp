#include <iostream>

#include "dayMarshall.h"

using namespace std;

/**
 * welcomes the user
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
 */
bool validate(int *month, int *day, int *year)
{
    int start = January, end = December;
    
    if(*month >= start && *month <= end)
    {
        switch(*month)
        {
            case April:
            case June:
            case September:
            case November:
                if(*day > 0 && *day < 31)
                    return true;
            break;
            
            case January:
            case March:
            case May:
            case July:
            case August:
            case October:
            case December:
                if(*day > 0 && *day <= 31)
                    return true;
            break;
            
            case February:
                if (*year % 4 == 0 && *day > 0 && *day <= 29)
                   return true;
            
                else if (*day > 0 && *day < 29)
                    return true;
             break;
        }
        
    }
    
    cout << "INVALID DATE!\n"
         << "(MONTH DAY YEAR)" << endl;
    return false;
}

/*
 * calculates the day in the year the entered date falls on.
 */
void calcDay(int month, int day, int year, int *yDay)
{
    switch(month)
    {
        case January:
            *yDay = day;
        break;
        
        case February:
                *yDay = day + CJ;
        break;
        
        case March:
            if (year % 4 == 0)
                *yDay = day + CF;
            else
                *yDay = day + CF - 1;
        break;
        
        case April:
            if (year % 4 == 0)
                *yDay = day + CM;
            else
                *yDay = day + CM - 1;
        break;
        
        case May:
            if (year % 4 == 0)
                *yDay = day + CA;
            else
                *yDay = day + CA - 1;
        break;
        
        case June:
            if (year % 4 == 0)
                *yDay = day + CMY;
            else
                *yDay = day + CMY - 1;
        break;
        
        case July:
            if (year % 4 == 0)
                *yDay = day + CJE;
            else
                *yDay = day + CJE;
        break;
        
        case August:
            if (year % 4 == 0)
                *yDay = day + CJY;
            else
                *yDay = day + CJY - 1;
        break;
        
        case September:
            if (year % 4 == 0)
                *yDay = day + CAT;
            else
                *yDay = day + CAT - 1;
        break;
        
        case October:
            if (year % 4 == 0)
                *yDay = day + CS;
            else
                *yDay = day + CS - 1;
        break;
                   
        case November:
            if (year % 4 == 0)
                *yDay = day + CO;
            else
                *yDay = day + CO - 1;
        break;
        
        case December:
            if (year % 4 == 0)
                *yDay = day + CN;
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
    if (yDay % 10 == 1)
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "st day of the year " << year << endl;
    }
    
    else if (yDay % 10 == 2)
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "nd day of the year " << year << endl;
    }
    
    else if (yDay % 10 == 3)
    {
        cout <<"\n" << month << "/" << day << "/" << year << " is the " << yDay << "rd day of the year " << year << endl;
    }
    
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