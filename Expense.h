#include <iostream>
#include "Transaction.h"

#ifndef EXPENSE.h
#define EXPENSE.h

using namespace std;

class Expense : public Transaction {

public:
    void setExpenseId(int newId);
    void setUserId(int newUserId);
    int getExpenseId();
    int getUserId();

private:
    int id;
    int userId;
};

#endif // EXPENSE
