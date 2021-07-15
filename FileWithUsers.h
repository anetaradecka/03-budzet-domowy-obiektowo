#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"

#ifndef FILEWITHUSERS.h
#define FILEWITHUSERS.h

using namespace std;

class FileWithUsers {

public:
    FileWithUsers(string usersFileName): USERS_FILE_NAME(usersFileName){};
    void addUserToFile(User newUser);
    vector <User> loadUsersFromFile();
    void changePasswordInFile(int activeUserId, string newPassword);

private:
    const string USERS_FILE_NAME;
};

#endif // FILEWITHUSERS
