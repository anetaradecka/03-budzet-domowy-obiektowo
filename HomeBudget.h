#include <iostream>

#include "Markup.h"
#include "UserManager.h"
#include "TransactionManager.h"

#ifndef HOMEBUDGET.h
#define HOMEBUDGET.h

using namespace std;

class HomeBudget {

public:
    HomeBudget(string usersFileName, string incomesFileName, string expensesFileName): userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
        userManager.loadUsersFromFile();
        transactionManager = NULL;
        while (true) {
            navigateMenu(selectOptionFromMainMenu());
        }
    };

    ~HomeBudget()
    {
        delete transactionManager;
        transactionManager = NULL;
    }
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void navigateMenu(char choice);
    void registerNewUser();
    void displayAllUsers();
    void loginUser();
    void logoutUser();
    void getActiveUserId();
    void changePassword();

private:
    UserManager userManager;
    TransactionManager *transactionManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
};

#endif // HOMEBUDGET
