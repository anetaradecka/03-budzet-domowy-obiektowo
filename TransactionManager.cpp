#include "TransactionManager.h"

void TransactionManager::addNewIncome() {
    fileWithIncomes.addNewIncome(ACTIVE_USER_ID);
    incomes = fileWithIncomes.loadIncomesFromFile(ACTIVE_USER_ID);
}

void TransactionManager::addNewExpense() {
    fileWithExpenses.addNewExpense(ACTIVE_USER_ID);
    expenses = fileWithExpenses.loadExpensesFromFile(ACTIVE_USER_ID);
}

void TransactionManager::showAllRevenues() {
    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }

    system("pause");
}

void TransactionManager::showAllExpenses() {
    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }

    system("pause");
}

void TransactionManager::showBalanceFromCurrentMonth() {

    int currentMonth = TimeConnectedMethods::setCurrentMonth();

    sort(incomes.begin(), incomes.end(), sortByDate());
    sort(expenses.begin(), expenses.end(), sortByDate());

    vector <Income> incomesRange;
    vector <Expense> expensesRange;

    showMonths(currentMonth);

    incomesRange = findIncomesFromCurrentMonth(currentMonth);
    showIncomesFromCurrentMonth(incomesRange);
    expensesRange = findExpensesFromCurrentMonth(currentMonth);
    showExpensesFromCurrentMonth(expensesRange);

    float incomesTotal = sumIncomes(incomesRange);
    cout << endl;
    cout << "Incomes total sum from current month:  " << incomesTotal << endl;

    float expensesTotal = sumExpenses(expensesRange);
    cout << "Expenses total sum from current month: " << expensesTotal << endl;

    float balance = incomesTotal - expensesTotal;
    cout << "Balance from current month:            " << balance << endl;
    system("pause");

}

void TransactionManager::showBalanceFromPreviousMonth() {

    int currentMonth = TimeConnectedMethods::setCurrentMonth();
    int previousMonth = currentMonth-1;

    sort(incomes.begin(), incomes.end(), sortByDate());
    sort(expenses.begin(), expenses.end(), sortByDate());

    vector <Income> incomesRange;
    vector <Expense> expensesRange;

    showMonths(previousMonth);

    incomesRange = findIncomesFromPreviousMonth(previousMonth);
    showIncomesFromPreviousMonth(incomesRange);
    expensesRange = findExpensesFromPreviousMonth(previousMonth);
    showExpensesFromPreviousMonth(expensesRange);

    float incomesTotal = sumIncomes(incomesRange);
    cout << endl;
    cout << "Incomes total sum from previous month:  " << incomesTotal << endl;

    float expensesTotal = sumExpenses(expensesRange);
    cout << "Expenses total sum from previous month: " << expensesTotal << endl;

    float balance = incomesTotal - expensesTotal;
    cout << "Balance from previous month:            " << balance << endl;
    system("pause");

}

void TransactionManager::showBalanceFromSelectedPeriod() {

    string periodBeginStr = "";
    cout << "Enter the period you want to get your balance sheet for in the YYYY-MM-DD format : " << endl;
    cout << "Period from: ";
    periodBeginStr = AuxiliaryMethods::loadLine();
    string pBeginStr = periodBeginStr;
    string periodEndStr = "";
    cout << " to: ";
    periodEndStr = AuxiliaryMethods::loadLine();
    string pEndStr = periodEndStr;

    periodBeginStr = AuxiliaryMethods::removeDashesFromDateFormat(periodBeginStr);
    periodEndStr = AuxiliaryMethods::removeDashesFromDateFormat(periodEndStr);

    int periodBegin = AuxiliaryMethods::convertStringToInt(periodBeginStr);
    int periodEnd = AuxiliaryMethods::convertStringToInt(periodEndStr);

    sort(incomes.begin(), incomes.end(), sortByDate());
    sort(expenses.begin(), expenses.end(), sortByDate());

    vector <Income> incomesRange;
    vector <Expense> expensesRange;

    incomesRange = findIncomesFromSelectedPeriod(periodBegin, periodEnd);
    showIncomesFromSelectedPeriod(incomesRange, pBeginStr, pEndStr);
    expensesRange = findExpensesFromSelectedPeriod(periodBegin, periodEnd);
    showExpensesFromSelectedPeriod(expensesRange, pBeginStr, pEndStr);

    float incomesTotal = sumIncomes(incomesRange);
    cout << endl;
    cout << "Incomes total sum:  " << incomesTotal << endl;

    float expensesTotal = sumExpenses(expensesRange);
    cout << "Expenses total sum: " << expensesTotal << endl;

    float balance = incomesTotal - expensesTotal;
    cout << "Balance:            " << balance << endl;
    system("pause");

}

vector <Income> TransactionManager::findIncomesFromCurrentMonth(int currentMonth) {
    vector <Income> currentRange;
    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        cout << endl;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        string monthStr = dateStr.substr(4,2);
        int month = AuxiliaryMethods::convertStringToInt(monthStr);
        if(month == currentMonth) {
            currentRange.push_back(*itr);
        }
    }
    return currentRange;
}

vector <Income> TransactionManager::findIncomesFromPreviousMonth(int previousMonth) {
    vector <Income> currentRange;
    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        cout << endl;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        string monthStr = dateStr.substr(4,2);
        int month = AuxiliaryMethods::convertStringToInt(monthStr);
        if(month == previousMonth) {
            currentRange.push_back(*itr);
        }
    }
    return currentRange;
}

vector <Income> TransactionManager::findIncomesFromSelectedPeriod(int periodBegin, int periodEnd) {
    vector <Income> currentRange;
    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        cout << endl;
        int date = itr -> getDate();
        if((date >= periodBegin)&&(date <= periodEnd)){
            currentRange.push_back(*itr);
        }
    }
    return currentRange;
}

void TransactionManager::showIncomesFromCurrentMonth(vector <Income> incomesRange) {
    cout << "Incomes from current month:" << endl ;
    cout << "----------------------------"<< endl;
    for(vector <Income>::iterator itr = incomesRange.begin(); itr != incomesRange.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }
}

void TransactionManager::showIncomesFromPreviousMonth(vector <Income> incomesRange) {
    cout << "Incomes from previous month:" << endl ;
    cout << "----------------------------"<< endl;
    for(vector <Income>::iterator itr = incomesRange.begin(); itr != incomesRange.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }
}

void TransactionManager::showIncomesFromSelectedPeriod(vector <Income> incomesRange, string pBeginStr, string pEndStr) {
    cout << "Incomes from period: " << pBeginStr << " to: " << pEndStr << endl ;
    cout << "-------------------------------------------------------------------"<< endl;
    for(vector <Income>::iterator itr = incomesRange.begin(); itr != incomesRange.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }
}

vector <Expense> TransactionManager::findExpensesFromCurrentMonth(int currentMonth) {
    vector <Expense> currentRange;
    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        cout << endl;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        string monthStr = dateStr.substr(4,2);
        int month = AuxiliaryMethods::convertStringToInt(monthStr);
        if(month == currentMonth) {
            currentRange.push_back(*itr);
        }
    }
    return currentRange;
}

vector <Expense> TransactionManager::findExpensesFromPreviousMonth(int previousMonth) {
    vector <Expense> currentRange;
    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        cout << endl;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        string monthStr = dateStr.substr(4,2);
        int month = AuxiliaryMethods::convertStringToInt(monthStr);
        if(month == previousMonth) {
            currentRange.push_back(*itr);
        }
    }
    return currentRange;
}

vector <Expense> TransactionManager::findExpensesFromSelectedPeriod(int periodBegin, int periodEnd) {
    vector <Expense> currentRange;
    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        cout << endl;
        int date = itr -> getDate();
        if((date >= periodBegin)&&(date <= periodEnd)){
            currentRange.push_back(*itr);
        }
    }
    return currentRange;
}

void TransactionManager::showExpensesFromCurrentMonth(vector<Expense> expensesRange) {
    cout << "Expenses from current month:" << endl ;
    cout << "----------------------------"<< endl;
    for(vector <Expense>::iterator itr = expensesRange.begin(); itr != expensesRange.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }

}

void TransactionManager::showExpensesFromPreviousMonth(vector <Expense> expensesRange) {
    cout << "Expenses from previous month:" << endl ;
    cout << "----------------------------"<< endl;
    for(vector <Expense>::iterator itr = expensesRange.begin(); itr != expensesRange.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }

}

void TransactionManager::showExpensesFromSelectedPeriod(vector <Expense> expensesRange, string pBeginStr, string pEndStr) {
    cout << "Expenses from period: " << pBeginStr << " to: " << pEndStr << endl ;
    cout << "-------------------------------------------------------------------"<< endl;
    for(vector <Expense>::iterator itr = expensesRange.begin(); itr != expensesRange.end(); itr++) {
        cout << endl;
        cout << "1. Category: " << itr -> getCategory() << endl;
        cout << "2. Date: " ;
        int date = itr -> getDate();
        string dateStr = AuxiliaryMethods::convertIntToString(date);
        dateStr = AuxiliaryMethods::addDashesToDateFormat(dateStr);
        cout << dateStr << endl;
        cout << "3. Amount: " <<itr -> getAmount() << endl;
    }
}

float TransactionManager::sumIncomes(vector <Income> incomesRange) {
    float total = 0;
    for(vector <Income>::iterator itr = incomesRange.begin(); itr != incomesRange.end(); itr++) {
        float income = 0;
        income = itr -> getAmount();
        total += income;
    }

    return total;
}

float TransactionManager::sumExpenses(vector <Expense> expensesRange) {
    float total = 0;
    for(vector <Expense>::iterator itr = expensesRange.begin(); itr != expensesRange.end(); itr++) {
        float expense = 0;
        expense = itr -> getAmount();
        total += expense;
    }

    return total;
}

void TransactionManager::showMonths(int currentMonth)
{
        cout << endl;
        cout << "       >> BALANCE SHEET FROM ";
    switch(currentMonth) {
    case 1:
        cout << "I JANUARY <<" << endl << endl;
        break;
    case 2:
        cout << "II FEBRUARY <<" << endl << endl;
        break;
    case 3:
        cout << "III MARCH <<" << endl << endl;
        break;
    case 4:
        cout << "IV APRIL <<" << endl << endl;
        break;
    case 5:
        cout << "V MAY <<" << endl << endl;
        break;
    case 6:
        cout << "VI JUNE <<" << endl << endl;
        break;
    case 7:
        cout << "VII JULY <<" << endl << endl;
        break;
    case 8:
        cout << "VIII AUGUST <<" << endl << endl;
        break;
    case 9:
        cout << "IX SEPTEMBER <<" << endl << endl;
        break;
    case 10:
        cout << "X OCTOBER <<" << endl << endl;
        break;
    case 11:
        cout << "XI NOVEMBER <<" << endl << endl;
        break;
    case 12:
        cout << "XII DECEMBER <<" << endl << endl;
        break;
    default:
        cout << endl << "Incorrect date format" << endl << endl;
        system("pause");
        break;
    }
}
