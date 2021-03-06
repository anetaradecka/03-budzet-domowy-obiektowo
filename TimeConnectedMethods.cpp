#include "TimeConnectedMethods.h"

int TimeConnectedMethods::getCurrentDate()
{
    char sign = '0';
    char *_sign = &sign;

    time_t t = time(0);
    tm* now = localtime(&t);

    string currentYearStr = getCurrentYear(now);
    string currentMonthStr = getCurrentMonth(now, _sign);
    string currentDayStr = getCurrentDay(now, _sign);

    string currentDateStr = currentYearStr + currentMonthStr + currentDayStr;

    int currentDate = AuxiliaryMethods::convertStringToInt(currentDateStr);

    return currentDate;
}

string TimeConnectedMethods::getCurrentYear(tm *now)
{
    int currentYear = now->tm_year + 1900;
    string currentYearStr = "";
    currentYearStr = AuxiliaryMethods::convertIntToString(currentYear);

    return currentYearStr;
}

string TimeConnectedMethods::getCurrentMonth(tm *now, char *_sign)
{
    int currentMonth = now->tm_mon + 1;
    string currentMonthStr = "";
    currentMonthStr = AuxiliaryMethods::convertIntToString(currentMonth);

    if(currentMonthStr.length() == 1)
        currentMonthStr = *_sign + currentMonthStr;

    return currentMonthStr;
}

string TimeConnectedMethods::getCurrentDay(tm *now, char *_sign)
{
    int currentDay = now->tm_mday;
    string currentDayStr = "";
    currentDayStr = AuxiliaryMethods::convertIntToString(currentDay);
    if(currentDayStr.length() == 1)
        currentDayStr = *_sign +currentDayStr;

    return currentDayStr;
}

string TimeConnectedMethods::convertDateFormat(string date)
{
    char dash = '-';
    string year = date.substr(0, 4);
    string month = date.substr(4, 2);
    string day = date.substr(6, 2);
    string formattedDate = year + dash + month + dash + day;

    return formattedDate;
}

bool TimeConnectedMethods::checkDateFormat(string date) {
    int numberOfIntegers = 0;
    int numberOfDashes = 0;
    char dash = '-';

    for(int i = 0; i < date.length(); i++) {
        if((date[i] >= 48) && (date[i] <= 57)) {
            numberOfIntegers++;
        } else if(date[i] == dash) {
            numberOfDashes++;
        }
    }
    if((numberOfIntegers == 8) && (numberOfDashes == 2))
        return true;
    else
        return false;
}

int TimeConnectedMethods::setCurrentMonth()
{
    int currentDate = TimeConnectedMethods::getCurrentDate();
    string currentDateStr = AuxiliaryMethods::convertIntToString(currentDate);
    string currentMonthStr = currentDateStr.substr(4,2);
    int currentMonth = AuxiliaryMethods::convertStringToInt(currentMonthStr);

    return currentMonth;
}

int TimeConnectedMethods::getNumberOfDays(int year, int month)
{
    	//leap year condition, if month is 2
	if( month == 2)
	{
		if((year%400==0) || (year%4==0 && year%100!=0))
			return 29;
		else
			return 28;
	}
	//months which has 31 days
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	||month == 10 || month==12)
		return 31;
	else
		return 30;
}

bool TimeConnectedMethods::checkNumberOfDays(int year, int month, int days)
{
    int numberOfDays = getNumberOfDays(year, month);
    if(days <= numberOfDays)
        return true;
    else
        return false;
}
