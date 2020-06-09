#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

using namespace std;

class User
{
public:
    int userId;
    string login;
    string password;
    string name;
    string surname;
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);
    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
