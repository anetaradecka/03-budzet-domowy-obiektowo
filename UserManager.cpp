#include "UserManager.h"

void UserManager::registerNewUser() {
    User newUser = getNewUserData();

    users.push_back(newUser);

    fileWithUsers.addUserToFile(newUser);

    cout << endl << "Congratulations, your account has been successfully created." << endl << endl;
    system("pause");
}

User UserManager::getNewUserData() {
    User newUser;

    newUser.setUserId(getNewUserId());

    string login;
    cout << endl;
    do {
        cout << "Set your login:       ";
        cin >> login;
        newUser.setLogin(login);

    } while (loginExists(newUser.getLogin()) == true);

    string name;
    cout << "Type your name:       ";
    cin >> name;
    newUser.setName(name);

    string surname;
    cout << "Type your surname:    ";
    cin >> surname;
    newUser.setSurname(surname);

    string password;
    cout << "Set your password:    ";
    cin >> password;
    newUser.setPassword(password);

    return newUser;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "This login is taken. Try another one." << endl;
            return true;
        }
    }
    return false;

}

void UserManager::loadUsersFromFile() {
    users = fileWithUsers.loadUsersFromFile();
}

void UserManager::displayAllUsers() {
        cout << endl;
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        cout << "ID:       " << itr->getUserId() << endl;
        cout << "name:     " << itr->getName() << endl;
        cout << "surname:  " << itr->getSurname() << endl;
        cout << "login:    " << itr->getLogin() << endl;
        cout << "password: " << itr->getPassword() << endl << endl;
    }

    system("pause");
}

int UserManager::loginUser()
{
    string login = "", password = "";
    cout << endl;
    cout << "Enter your login:                       ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attemptNumber = 3; attemptNumber > 0; attemptNumber--)
            {
                cout << "Enter your password. Attempts left: " << attemptNumber << ":  ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "         >> Login successful <<         " << endl << endl;
                    system("pause");
                    activeUserId = itr -> getUserId();

                    return activeUserId;
                }

            }

            cout << "You have exceeded the number of attempts. Login unsuccessful." << endl;
            system("pause");
            activeUserId = 0;
            return 0;
        }
        itr++;
    }

    cout << "User with this login does not exist." << endl << endl;
    system("pause");
    activeUserId = 0;
    return 0;
}

int UserManager::logoutUser()
{
    activeUserId = 0;

    return activeUserId;
}

int UserManager::getActiveUserId()
{
    return activeUserId;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << endl;
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == activeUserId)
        {
            itr -> setPassword(newPassword);
            cout << endl;
            cout << "   >> Password has been changed <<" << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePasswordInFile(activeUserId, newPassword);
}

bool UserManager::isUserActive()
{
    if (activeUserId > 0)
        return true;
    else
        return false;
}
