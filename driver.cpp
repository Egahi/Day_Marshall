/**
 * dayMarshall.cpp
 *
 * this program demands the date from a user (month/day/year)
 * then outputs the day it is in the year.
 * e.g 02/01/2017 is the 32nd day in year 2017.
 *
 * @s_egahi
 *
 * this is day marshall
 */

#include <iostream>

#include "dayMarshall.h"

using namespace std;

int main(void)
{
    int month, day, year, yDay;
    
    do
    {
        // welcomes user
        welcomeUser();
        
        // gets valid date from user
        getDate(&month, &day, &year);
        
        // calculates the day it falls in the year
        calcDay(month, day, year, &yDay);
        
        // displays result
        printInfo(month, day, year, yDay);
        
     // prompt for another operation
    } while(runAgain());
    
    // success
    return 0;
}
