#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "FileWithUsers.h"

#ifndef USERMANAGER.h
#define USERMANAGER.h

using namespace std;

class UserManager {

public:
    UserManager(string usersFileName): fileWithUsers(usersFileName){
        activeUserId = 0;
    }
    void registerNewUser();
    void loadUsersFromFile();
    void displayAllUsers();
    int loginUser();
    int logoutUser();
    int getActiveUserId();
    void changePassword();
    void changePasswordInFile(int activeUserId, string newPassword);
    bool isUserActive();

private:
  vector <User> users;
  FileWithUsers fileWithUsers;
  int activeUserId;

  User getNewUserData();
  int getNewUserId();
  bool loginExists(string login);
};

#endif // USERMANAGER
