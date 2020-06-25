#ifndef PERSONALBUDGETMANAGER_H
#define PERSONALBUDGETMANAGER_H

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpanseManager.h"

#include <iostream>

using namespace std;

class XMLFileWithIncomes;
class XMLFileWithExpanses;

class PersonalBudgetManager
{

    float income, expanse;

    XMLFileWithIncomes *xmlFileWithIncomes;
    XMLFileWithExpanses *xmlFileWithExpanses;
    IncomeManager *incomeManager;
    UserManager userManager;
    AuxiliaryMethods auxiliaryMethod;

public:

    PersonalBudgetManager()
    {
    incomeManager=NULL;
    xmlFileWithIncomes=NULL;
//    xmlFileWithExpanses=NULL;
    };

    ~PersonalBudgetManager()
    {
    delete xmlFileWithIncomes;
    delete incomeManager;
//    delete xmlFileWithExpanses;
    xmlFileWithIncomes=NULL;
    incomeManager=NULL;
//    xmlFileWithExpanses=NULL;;
    }

    void addIncome();
    void addExpanse();
    void registerUser();
    void logInUser();
    void logOutUser();
    int getIdOfLoggedUser();
    void showAllUsers();
    void changePassword();
    char chooseOneOptionFromMainMenu();
    char chooseOneOptionFromUserMenu();

    void showTheBalanceOfTheCurrentMonth();
    void showTheBalanceOfThePreviousMonth();
    void showTheBalanceOfTheSelectedPeriod();

};

#endif
