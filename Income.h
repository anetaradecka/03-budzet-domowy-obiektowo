#include <iostream>
#include "Transaction.h"

#ifndef INCOME.h
#define INCOME.h

using namespace std;

class Income : public Transaction {

public:
    void setIncomeId(int newId);
    void setUserId(int newUserId);
    int getIncomeId();
    int getUserId();

private:
    int id;
    int userId;
};

#endif // INCOME
