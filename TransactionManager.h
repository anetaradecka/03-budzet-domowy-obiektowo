#include <iostream>
#include <algorithm>
#include "Transaction.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

#include "Markup.h"

#ifndef TRANSACTIONMANAGER.h
#define TRANSACTIONMANAGER.h

using namespace std;

class TransactionManager {

public:
    TransactionManager(string INCOMES_FILE_NAME, string EXPENSES_FILE_NAME, int activeUserId) : fileWithIncomes(INCOMES_FILE_NAME), fileWithExpenses(EXPENSES_FILE_NAME), ACTIVE_USER_ID(activeUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(ACTIVE_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(ACTIVE_USER_ID);
    };

    struct sortByDate
{
    inline bool operator() (Transaction& firstDate, Transaction& secondDate)
    {
        return (firstDate.getDate() < secondDate.getDate());
    }
};
    void addNewIncome();
    void addNewExpense();
    void showAllRevenues();
    void showAllExpenses();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();

private:
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    const int ACTIVE_USER_ID;
    vector <Income> findIncomesFromCurrentMonth(int currentMonth);
    vector <Income> findIncomesFromPreviousMonth(int previousMonth);
    vector <Income> findIncomesFromSelectedPeriod(int periodBegin, int periodEnd);
    vector <Expense> findExpensesFromCurrentMonth(int currentMonth);
    vector <Expense> findExpensesFromPreviousMonth(int previousMonth);
    vector <Expense> findExpensesFromSelectedPeriod(int periodBegin, int periodEnd);
    void showIncomesFromCurrentMonth(vector <Income> incomesRange);
    void showExpensesFromCurrentMonth(vector <Expense> expensesRange);
    void showIncomesFromPreviousMonth(vector <Income> incomesRange);
    void showExpensesFromPreviousMonth(vector <Expense> expensesRange);
    void showIncomesFromSelectedPeriod(vector <Income> incomesRange, string pBeginStr, string pEndStr);
    void showExpensesFromSelectedPeriod(vector <Expense> expensesRange, string pBeginStr, string pEndStr);
    float sumIncomes(vector <Income> incomesRange);
    float sumExpenses(vector <Expense> expensesRange);
    void showMonths(int month);

};

#endif // TRANSACTIONMANAGER
