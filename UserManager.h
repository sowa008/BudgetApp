#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "XMLFileWithUsers.h"

using namespace std;

class UserManager
{
    //const string USERS_FILE_NAME="users.xml";
    int idOfLoggedUser;
    vector <User> users;
    XMLFileWithUsers xmlFileWithUsers;
    User user;

    int getIdOfNewUser();
    bool doesLoginExist(string login);

public:
    UserManager() {
    idOfLoggedUser=0;
    //users=xmlFileWithUsers.getAllUsers(nameOfXMLFileWithUsers);
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
