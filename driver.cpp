/**
 * DAYMARSHALl.cpp
 *
 * this program demands the date from a user (month/day/year)
 * then outputs the day it is in the year.
 * e.g 02/01/2017 is the 32nd day in year 2017.
 *
 * @s_egahi
 *
 * this is DAYMARSHALL
 */

#include <iostream>

#include "dayMarshall.h"

using namespace std;

int main(void)
{
    int month, day, year, yDay;
    
    do
    {
        welcomeUser();
        
        getDate(&month, &day, &year);
        
        calcDay(month, day, year, &yDay);
        
        printInfo(month, day, year, yDay);
    } while(runAgain());
    
    return 0;
}