#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XMLFileWithUsers
{

public:
    void addUserToXMLFile(string fileName);
    vector <User> getAllUsers(string fileName);
    void readUsersFromXMLFile(User newUser);
    void saveAllUsersToXMLFile(vector<User> allUsers);
};

#endif
