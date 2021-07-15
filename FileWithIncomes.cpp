#include "FileWithIncomes.h"

/*void FileWithIncomes::addNewIncome(int activeUserId) {
    Income newIncome;

    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;
    newIncome = getNewIncomeDetails(activeUserId);

    incomes.push_back(newIncome);
    addIncomeToFile(newIncome);
}*/

Income FileWithIncomes::getNewIncomeDetails(int activeUserId) {
    Income newIncome;

    newIncome.setIncomeId(++lastIncomeId);
    newIncome.setUserId(activeUserId);

    cout << "Category: ";
    newIncome.setCategory(AuxiliaryMethods::loadLine());

    cout << endl;
    cout << "Add income with: " << endl;
    cout << "    1. current date" << endl;
    cout << "    2. other date" << endl;

    char choice = AuxiliaryMethods::loadChar();

    switch(choice) {
    case '1': {
        int date = 0;
        date = TimeConnectedMethods::getCurrentDate();
        newIncome.setDate(date);
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
                newIncome.setDate(date);
            }
        } else {
            dateStr = AuxiliaryMethods::removeDashesFromDateFormat(dateStr);
            int date = AuxiliaryMethods::convertStringToInt(dateStr);
            newIncome.setDate(date);
        }

        break;
    }
    default:
        cout << endl << "False option selected." << endl << endl;
        system("pause");
        break;
    }


    cout << "Amount : ";
    newIncome.setAmount(AuxiliaryMethods::loadLine());

    return newIncome;
}

void FileWithIncomes::addIncomeToFile(Income newIncome) {
    CMarkup xml;

    bool fileExists = xml.Load( INCOMES_FILE_NAME );

    if(!fileExists) {
        xml.AddElem( "INCOMESLIST" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "INCOME" );
    xml.IntoElem();
    xml.AddElem( "ID", newIncome.getIncomeId() );
    xml.AddElem( "USERID", newIncome.getUserId() );
    xml.AddElem( "CATEGORY", newIncome.getCategory() );
    int date = newIncome.getDate();
    string dateStr = AuxiliaryMethods::convertIntToString(date);
    dateStr = TimeConnectedMethods::convertDateFormat(dateStr);
    xml.AddElem( "DATE", dateStr );
    float amount = newIncome.getAmount();
    string amountStr = AuxiliaryMethods::convertFloatToString(amount);
    xml.AddElem( "AMOUNT", amountStr );

    xml.Save( "Incomes.xml" );
}

vector <Income> FileWithIncomes::loadIncomesFromFile(int activeUserId) {
    Income income;
    vector <Income> incomes;

    int id = 0;
    int userId = 0;
    int date = 0;
    string idNumber = "";
    string userIdNumber = "";
    string category = "";
    string dateStr = "";
    string amountStr = "";

    CMarkup xml;

    bool fileExists = xml.Load( INCOMES_FILE_NAME );

    if(!fileExists) {
        cout << "No incomes saved." << endl;
    }
    xml.FindElem(); // root INCOMESLIST element
    xml.IntoElem(); // inside INCOMESLIST

    while ( xml.FindElem( "INCOME" ) ) {

        xml.IntoElem();
        xml.FindElem( "ID" );
        idNumber = xml.GetData();
        id = AuxiliaryMethods::convertStringToInt(idNumber);
        income.setIncomeId(id);
        if (income.getIncomeId() > lastIncomeId)
            lastIncomeId = income.getIncomeId();
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "USERID" );
        userIdNumber = xml.GetData();
        userId = AuxiliaryMethods::convertStringToInt(userIdNumber);
        income.setUserId(userId);
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "CATEGORY" );
        category = xml.GetData();
        income.setCategory(category);
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "DATE" );
        dateStr = xml.GetData();
        dateStr = AuxiliaryMethods::removeDashesFromDateFormat(dateStr);
        date = AuxiliaryMethods::convertStringToInt(dateStr);
        income.setDate(date);
        xml.OutOfElem();

        xml.IntoElem();
        xml.FindElem( "AMOUNT" );
        amountStr = xml.GetData();
        income.setAmount(amountStr);
        xml.OutOfElem();

        if (income.getUserId() == activeUserId)
            incomes.push_back(income);
    }

    return incomes;
}


