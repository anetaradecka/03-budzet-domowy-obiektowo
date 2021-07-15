#include "AuxiliaryMethods.h"

char AuxiliaryMethods::loadChar() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        } else {
            cout << endl;
            cout << "(!)This is not a single character. Please select again: ";
        }
    }

    return character;
}

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;
    return intNumber;
}

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool AuxiliaryMethods::checkAmountForComma(string newAmount) {
    char comma = ',';
    int count = 0;
    for(int i = 0; i < newAmount.length(); i++) {
        if(newAmount[i] == comma)
            count ++;
    }
    if(count > 0)
        return true;
    else
        return false;
}

float AuxiliaryMethods::convertStringToFloat(string newAmount) {
    float amount = 0;
    amount = atof(newAmount.c_str());

    return amount;
}

string AuxiliaryMethods::convertFloatToString(float newAmount) {
    stringstream amountStr;
    amountStr << newAmount;
    string newAmountStr = amountStr.str();

    return newAmountStr;
}

string AuxiliaryMethods::convertCommaToDot(string newAmount) {
    char comma = ',';
    char dot = '.';
    for(int i = 0; i < newAmount.length(); i++) {
        if(newAmount[i] == comma)
            newAmount[i] = dot;
    }

    return newAmount;
}

string AuxiliaryMethods::removeDashesFromDateFormat(string date) {
    char dash = '-';
    string formattedDate = "";
    for(int i = 0; i < date.length(); i++) {
        if(date[i] != dash)
            formattedDate += date[i];
    }

    return formattedDate;
}

string AuxiliaryMethods::addDashesToDateFormat(string date)
{
    date.insert(4,"-");
    date.insert(7,"-");

    return date;
}


