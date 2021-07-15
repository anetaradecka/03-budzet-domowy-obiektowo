#include "HomeBudget.h"

char HomeBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> NAVIGATION BAR <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Display registered users" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Select what you want to do: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

char HomeBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER NAVIGATION BAR <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add revenue" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance sheet for the current month" << endl;
    cout << "4. Display balance sheet for the previous month" << endl;
    cout << "5. Display balance sheet for a selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change your password" << endl;
    cout << "7. Log out" << endl;
    cout << "8. Show all incomes" << endl;
    cout << "9. Show all expenses" << endl;
    cout << "---------------------------" << endl;
    cout << "Select what you want to do: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void HomeBudget::navigateMenu(char choice) {
    switch (choice) {
    case '1':
        registerNewUser();
        break;
    case '2':
        loginUser();

        if (userManager.getActiveUserId() != 0) {
            bool isUserActive = true;

            while (isUserActive == true) {

                switch(selectOptionFromUserMenu()) {
                case '1':
                    transactionManager->addNewIncome();
                    break;
                case '2':
                    transactionManager->addNewExpense();
                    break;
                case '3':
                    transactionManager->showBalanceFromCurrentMonth();
                    break;
                case '4':
                    transactionManager->showBalanceFromPreviousMonth();
                    break;
                case '5':
                    transactionManager->showBalanceFromSelectedPeriod();
                    break;
                case '6':
                    changePassword();
                    break;
                case '7':
                    isUserActive = false;
                    logoutUser();
                    break;
                case '8':
                    transactionManager->showAllRevenues();
                    break;
                case '9':
                    transactionManager->showAllExpenses();
                    break;
                }
            }
        }
        break;
    case '3':
        displayAllUsers();
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "False option selected." << endl << endl;
        system("pause");
        break;
    }
}

void HomeBudget::registerNewUser() {
    userManager.registerNewUser();
}

void HomeBudget::displayAllUsers() {
    userManager.displayAllUsers();
}

void HomeBudget::loginUser() {
    userManager.loginUser();
    if (userManager.isUserActive()) {
        transactionManager = new TransactionManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getActiveUserId());
    }
}

void HomeBudget::logoutUser() {
    userManager.logoutUser();
}

void HomeBudget::getActiveUserId() {
    userManager.getActiveUserId();
}

void HomeBudget::changePassword() {
    userManager.changePassword();
}
