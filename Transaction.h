#include <iostream>

#include "Markup.h"
#include "TimeConnectedMethods.h"

#ifndef TRANSACTION.h
#define TRANSACTION.h

using namespace std;

class Transaction {

public:
    void setCategory(string newCategory);
    void setDate(int newDate);
    void setAmount(string newAmount);
    string getCategory();
    int getDate();
    float getAmount();

private:
    string category;
    int date;
    float amount;

};

#endif // TRANSACTION
