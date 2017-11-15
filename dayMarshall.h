#ifndef _DAYMARSHALL_H_
#define _DAYMARSHALL_H_

#define CJ 31
#define CF 60
#define CM 91
#define CA 121
#define CMY 152
#define CJE 182
#define CJY 213
#define CAT 244
#define CS 274
#define CO 305
#define CN 335


enum months {January = 1, February, March, April, May, June, July, August, September, October, November, December};

void welcomeUser(void);
        
void getDate(int *, int *, int *);

bool validate(int *, int *, int *);

void calcDay(int, int, int, int *);

void printInfo(int, int, int, int);

bool runAgain(void);

#endif
