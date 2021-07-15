#include <iostream>
#include <iostream>
#include <ctime>

#include "Markup.h"
#include "AuxiliaryMethods.h"

#ifndef TIMECONNECTEDMETHODS.h
#define TIMECONNECTEDMETHODS.h

using namespace std;

class TimeConnectedMethods {

public:
    static int getCurrentDate();
    static int setOtherDate();
    static string getCurrentYear(tm *now);
    static string getCurrentMonth(tm *now, char *sign);
    static string getCurrentDay(tm *now, char *sign);
    static string convertDateFormat(string date);
    static bool checkDateFormat(string date);
    static int setCurrentMonth();
    static int getNumberOfDays(int year, int month);
    static bool checkNumberOfDays(int year, int month, int days);

};

#endif // TIMECONNECTEDMETHODS
