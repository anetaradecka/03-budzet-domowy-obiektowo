#include "FileWithExpenses.h"

void FileWithExpenses::addNewExpense(int activeUserId) {
    Expense newExpense;

    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;
    newExpense = getNewExpenseDetails(activeUserId);

    expenses.push_back(newExpense);
    addExpenseToFile(newExpense);
}

Expense FileWithExpenses::getNewExpenseDetails(int activeUserId) {
    Expense newExpense;

    newExpense.setExpenseId(++lastExpenseId);
    newExpense.setUserId(activeUserId);

    cout << "Category: ";
    newExpense.setCategory(AuxiliaryMethods::loadLine());

    cout << endl;
    cout << "Add Expense with: " << endl;
    cout << "    1. current date" << endl;
    cout << "    2. other date" << endl;

    char choice = AuxiliaryMethods::loadChar();

    switch(choice) {
    case '1': {
        int date = 0;
        date = TimeConnectedMethods::getCurrentDate();
        newExpense.setDate(date);
        break;
    }
    case '2': {
        cout << "Enter date in the format YYYY-MM-DD: ";
        string dateStr = "";
        dateStr = AuxiliaryMethods::loadLine();

        string daysStr = dateStr.substr(8,2);
        int days = AuxiliaryMethods::convertStringToInt(daysStr);

        string monthStr = dateStr.substr(5,2);
        int month = AuxiliaryMethods::convertStringToInt(monthStr);

        string yearStr = dateStr.substr(0,4);
        int year = AuxiliaryMethods::convertStringToInt(yearStr);

        bool result = TimeConnectedMethods::checkNumberOfDays(year, month, days);

        if(result == false) {
            do {
                cout << endl;
                cout << "Incorrect number of days. Enter again: ";
                dateStr = AuxiliaryMethods::loadLine();
                string daysStr = dateStr.substr(8,2);
                int days = AuxiliaryMethods::convertStringToInt(daysStr);
                string monthStr = dateStr.substr(5,2);
                int month = AuxiliaryMethods::convertStringToInt(monthStr);
                string yearStr = dateStr.substr(0,4);
                int year = AuxiliaryMethods::convertStringToInt(yearStr);
                bool result = TimeConnectedMethods::checkNumberOfDays(year, month, days);
            } while(result != false);
        }


        if(!TimeConnectedMethods::checkDateFormat(dateStr)) {
            cout << "Incorrect date format. Enter again: ";
            dateStr = AuxiliaryMethods::loadLine();
            if(!TimeConnectedMethods::checkDateFormat(dateStr)) {
                cout << "Failed to add a date. " << endl;
            } else {
                dateStr = AuxiliaryMethods::removeDashesFromDateFormat(dateStr);
                int date = AuxiliaryMethods::convertStringToInt(dateStr);
                newExpense.setDate(date);
            }
        } else {
            dateStr = AuxiliaryMethods::removeDashesFromDateFormat(dateStr);
            int date = AuxiliaryMethods::convertStringToInt(dateStr);
            newExpense.setDate(date);
        }

        break;
    }
    default:
        cout << endl << "False option selected." << endl << endl;
        system("pause");
        break;
    }


    cout << "Amount : ";
    newExpense.setAmount(AuxiliaryMethods::loadLine());

    return newExpense;
}

void FileWithExpenses::addExpenseToFile(Expense newExpense) {
    CMarkup xml;

    bool fileExists = xml.Load( EXPENSES_FILE_NAME );

    if(!fileExists) {
        xml.AddElem( "EXPENSESLIST" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "EXPENSE" );
    xml.IntoElem();
    xml.AddElem( "ID", newExpense.getExpenseId() );
    xml.AddElem( "USERID", newExpense.getUserId() );
    xml.AddElem( "CATEGORY", newExpense.getCategory() );
    int date = newExpense.getDate();
    string dateStr = AuxiliaryMethods::convertIntToString(date);
    dateStr = TimeConnectedMethods::convertDateFormat(dateStr);
    xml.AddElem( "DATE", dateStr );
    float amount = newExpense.getAmount();
    string amountStr = AuxiliaryMethods::convertFloatToString(amount);
    xml.AddElem( "AMOUNT", amountStr );

    xml.Save( "Expenses.xml" );
}

vector <Expense> FileWithExpenses::loadExpensesFromFile(int activeUserId) {
    Expense expense;
    vector <Expense> expenses;

    int id = 0;
    int userId = 0;
    int date = 0;
    string idNumber = "";
    string userIdNumber = "";
    string category = "";
    string dateStr = "";
    string amountStr = "";

    CMarkup xml;

    bool fileExists = xml.Load( EXPENSES_FILE_NAME );

    if(!fileExists) {
        cout << "No Expenses saved." << endl;
    }
    xml.FindElem(); // root EXPENSESLIST element
    xml.IntoElem(); // inside EXPENSESLIST

    while ( xml.FindElem( "EXPENSE" ) ) {

        xml.IntoElem();
        xml.FindElem( "ID" );
        idNumber = xml.GetData();
        id = AuxiliaryMethods::convertStringToInt(idNumber);
        expense.setExpenseId(id);
        if (expense.getExpenseId() > lastExpenseId)
            lastExpenseId = expense.getExpenseId();
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "USERID" );
        userIdNumber = xml.GetData();
        userId = AuxiliaryMethods::convertStringToInt(userIdNumber);
        expense.setUserId(userId);
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "CATEGORY" );
        category = xml.GetData();
        expense.setCategory(category);
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "DATE" );
        dateStr = xml.GetData();
        dateStr = AuxiliaryMethods::removeDashesFromDateFormat(dateStr);
        date = AuxiliaryMethods::convertStringToInt(dateStr);
        expense.setDate(date);
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "AMOUNT" );
        amountStr = xml.GetData();
        expense.setAmount(amountStr);
        xml.OutOfElem();

        if (expense.getUserId() == activeUserId)
            expenses.push_back(expense);
    }

    return expenses;
}


