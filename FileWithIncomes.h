#include <iostream>
#include <vector>

#include "Markup.h"
#include "Transaction.h"
#include "Income.h"

#ifndef FILEWITHINCOMES.h
#define FILEWITHINCOMES.h

using namespace std;

class FileWithIncomes {

public:
    FileWithIncomes(string incomesFileName): INCOMES_FILE_NAME(incomesFileName){
        lastIncomeId = 0;
    };
    //void addNewIncome(int activeUserId);
    Income getNewIncomeDetails(int activeUserId);
    void addIncomeToFile(Income newIncome);
    vector <Income> loadIncomesFromFile(int ACTIVE_USER_ID);

private:
    const string INCOMES_FILE_NAME;
    vector <Income> incomes;
    int lastIncomeId;
};

#endif // FILEWITHINCOMES
