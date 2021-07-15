#include <iostream>
#include <vector>

#include "Markup.h"
#include "Transaction.h"
#include "Expense.h"

#ifndef FILEWITHEXPENSES.h
#define FILEWITHEXPENSES.h

using namespace std;

class FileWithExpenses {

public:
    FileWithExpenses(string expensesFileName): EXPENSES_FILE_NAME(expensesFileName){
        lastExpenseId = 0;
    };
    void addNewExpense(int activeUserId);
    Expense getNewExpenseDetails(int activeUserId);
    void addExpenseToFile(Expense newExpense);
    vector <Expense> loadExpensesFromFile(int ACTIVE_USER_ID);

private:
    const string EXPENSES_FILE_NAME;
    vector <Expense> expenses;
    int lastExpenseId;
};

#endif // FILEWITHEXPENSES
