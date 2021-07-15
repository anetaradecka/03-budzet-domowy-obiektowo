#include <iostream>
#include <sstream>
#include<string>

#include "Markup.h"

#ifndef AUXILIARYMETHODS.h
#define AUXILIARYMETHODS.h

using namespace std;

class AuxiliaryMethods {

public:
    static char loadChar();
    static string loadLine();
    static int convertStringToInt(string number);
    static string convertIntToString(int number);
    static bool checkAmountForComma(string newAmount);
    static float convertStringToFloat(string newAmount);
    static string convertCommaToDot(string newAmount);
    static string convertFloatToString(float newAmount);
    static string removeDashesFromDateFormat(string date);
    static bool checkDateFormat(string date);
    static string addDashesToDateFormat(string date);

};

#endif // AUXILIARYMETHODS
