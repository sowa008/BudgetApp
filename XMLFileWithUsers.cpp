#include "XMLFileWithUsers.h"
#include "UserManager.h"
#include "Markup.h"
#include "User.h"

#include <iostream>
#include <vector>

void XMLFileWithUsers :: addUserToXMLFile(string fileName)
{
    fstream file;
    int lastUserId = 0;
    string login="", password="", name="", surname="";
    UserManager userManager;

    User newUser = userManager.askDataOfNewUser();

    file.open(fileName.c_str(), ios::out | ios::app);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            lastUserId=0;;
        }
        else
        {
            vector <User> allUsers = getAllUsers(fileName);
            lastUserId=allUsers.back().userId;
        }
    }
    else
        cout << "Could not open the file " << fileName << " and save the data." << endl;
    file.close();

    newUser.userId = lastUserId+1;

    CMarkup xml;

    xml.Load(AuxiliaryMethods::getUsersFileName());

    if (xml.FindElem() == false)
    {
        xml.AddElem("users");
    }

    xml.IntoElem();
    xml.AddElem( "user" );
    xml.IntoElem();
    xml.AddElem( "userId", newUser.userId );
    xml.AddElem( "login", newUser.login );
    xml.AddElem( "password", newUser.password );
    xml.AddElem( "name", newUser.name );
    xml.AddElem( "surname", newUser. surname );

    if (xml.FindElem() == false)
    {
        xml.AddElem("users");
    }

    string csXML = xml.GetDoc();

    file.open(AuxiliaryMethods::getUsersFileName(), ios::out);

    file << csXML << endl;

    file.close();
}

vector <User> XMLFileWithUsers :: getAllUsers(string fileName)
{
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

    if (bSuccess==false)
    {
        cout << "There is no such file!" << endl;
        return {};
    }

    xml.FindElem();
    xml.IntoElem();

    vector <User> allUsers;

    while (xml.FindElem("user"))
    {
        User newUser;

        xml.IntoElem();
        xml.FindElem( "userId" );
        int nUserId = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "login" );
        string strLogin = xml.GetData();
        xml.FindElem( "password" );
        string strPassword = xml.GetData();
        xml.FindElem( "name" );
        string strName = xml.GetData();
        xml.FindElem( "surname" );
        string strSurname = xml.GetData();
        xml.OutOfElem();

        newUser.userId = nUserId;
        newUser.login = strLogin;
        newUser.password = strPassword;
        newUser.name = strName;
        newUser.surname = strSurname;

        allUsers.push_back(newUser);
    }

    return allUsers;
}

void XMLFileWithUsers :: readUsersFromXMLFile(User newUser)
{
    fstream file;
    string userId, login, password, name, surname;
    vector <User> allUsers;
    CMarkup xml;

    file.open( AuxiliaryMethods::getUsersFileName(), ios::in);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            cout << "This file is empty" << endl;
        }
        else
        {
            allUsers = getAllUsers(AuxiliaryMethods::getUsersFileName());
            cout << "The number of saved users: " << allUsers.size() << endl;
            cout << endl;
        }
    }
    else
        cout << "Could not open the file " << AuxiliaryMethods::getUsersFileName() << endl;

    file.close();

    for (int i=0; i<allUsers.size(); i++)
    {
        cout << allUsers[i].userId << endl;
        cout << allUsers[i].login << endl;
        cout << allUsers[i].password << endl;
        cout << allUsers[i].name << endl;
        cout << allUsers[i].surname << endl;
        cout << endl;
    }
}

void XMLFileWithUsers :: saveAllUsersToXMLFile(vector<User> allUsers)
{
    fstream file;
    string login="", password="", name="", surname="";

    file.open(AuxiliaryMethods::getUsersFileName(), ios::out);

    CMarkup xml;

    xml.AddElem("users");
    xml.IntoElem();

    for (int i=0; i<allUsers.size(); i++)
    {
        xml.AddElem( "user" );
        xml.IntoElem();
        xml.AddElem( "userId", allUsers[i].userId );
        xml.AddElem( "login", allUsers[i].login );
        xml.AddElem( "password", allUsers[i].password );
        xml.AddElem( "name", allUsers[i].name );
        xml.AddElem( "surname", allUsers[i]. surname );
        xml.OutOfElem();
    }

    string csXML = xml.GetDoc();

    file << csXML << endl;

    file.close();
}
