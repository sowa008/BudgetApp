#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "XMLFileWithUsers.h"

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class UserManager
{
    int idOfLoggedUser;
    vector <User> users;
    XMLFileWithUsers xmlFileWithUsers;
    User user;

    int getIdOfNewUser();
    bool doesLoginExist(string login);

public:
    UserManager()
    {
    idOfLoggedUser=0;
    };

    User askDataOfNewUser();

    void registerUser();
    void showAllUsers();
    void logInUser();
    void changePassword();
    void logOutUser();
    bool isUserLoggedIn();
    int getIdOfLoggedUser();
};

#endif
