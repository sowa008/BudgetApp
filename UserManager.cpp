#include "UserManager.h"
#include "XMLFileWithUsers.h"

void UserManager :: registerUser()
{
    xmlFileWithUsers.addUserToXMLFile(AuxiliaryMethods::getUsersFileName());
    cout << endl << "Your account has been created. Enjoy!" << endl << endl;
    system("pause");
}

User UserManager :: askDataOfNewUser()
{
    User user;
    user.setId(getIdOfNewUser());
    string login, password, name, surname;

    cin.sync();

    do
    {
        cout << "Propose your login: ";
        getline(cin, login);
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin()) == true);

    cout << "Set your password: ";
    getline(cin, password);
    user.setPassword(password);

    cout << "What is your name?: ";
    getline(cin, name);
    string changedName = AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToSmall(name);
    user.setName(changedName);

    cout << "What is your surname?: ";
    getline(cin, surname);
    string changedSurname = AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToSmall(surname);
    user.setSurname(changedSurname);

    return user;
}

int UserManager :: getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager :: doesLoginExist(string login)
{
    XMLFileWithUsers xmlFileWithUsers;
    vector<User> users = xmlFileWithUsers.getAllUsers(AuxiliaryMethods::getUsersFileName());

    for (unsigned int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << "There is user with this login. Try again." << endl;
            cout << endl;
            return true;
        }
    } return false;
}

void UserManager :: showAllUsers()
{
    xmlFileWithUsers.readUsersFromXMLFile(user);
    system("pause");
}

void UserManager :: logInUser()
{
    XMLFileWithUsers xmlFileWithUsers;
    vector<User> users = xmlFileWithUsers.getAllUsers(AuxiliaryMethods::getUsersFileName());

    string login = "", password = "";

    cout << endl << "What is your login: ";
    login = AuxiliaryMethods :: getLine();

    vector<User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberToTry = 3; numberToTry > 0; numberToTry--)
            {
                cout << "Give your password. You can try " << numberToTry << " times: ";
                password = AuxiliaryMethods :: getLine();

                if (itr -> getPassword() == password)
                {
                    idOfLoggedUser = itr -> getId();
                    cout << endl << "You are logged in. Your id = " <<  idOfLoggedUser << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "You entered wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with such login" << endl << endl;
    system("pause");
    return;
}

void UserManager :: changePassword()
{
    XMLFileWithUsers xmlFileWithUsers;
    vector<User> users = xmlFileWithUsers.getAllUsers(AuxiliaryMethods::getUsersFileName());

    string newPassword = "";
    cout << "Set new password: ";
    newPassword = AuxiliaryMethods :: getLine();
    cout << endl;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> userId == idOfLoggedUser)
        {
            itr -> password = newPassword;
            cout << "Your password has been changed." << endl;
            cout << "Your new password is: " << newPassword << endl << endl;
        }
    } system("pause");

   xmlFileWithUsers.saveAllUsersToXMLFile(users);
}

void UserManager :: logOutUser()
{
    idOfLoggedUser=0;
}

bool UserManager :: isUserLoggedIn()
{
    if (idOfLoggedUser > 0)
    {
        return true;
    }
    else return false;
}

int UserManager :: getIdOfLoggedUser()
{
    return idOfLoggedUser;
}
