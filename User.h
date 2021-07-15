#include <iostream>

#include "Markup.h"

#ifndef USER.h
#define USER.h

using namespace std;

class User {

public:
    void setUserId(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    int getUserId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

private:
    int id;
    string login;
    string password;
    string name;
    string surname;

};

#endif // USERMANAGER
