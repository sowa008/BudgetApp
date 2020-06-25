#include "PersonalBudgetManager.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "XMLFileWithIncomes.h"
#include "XMLFileWithExpanses.h"

#include <iomanip>


void PersonalBudgetManager :: addIncome()
{
    incomeManager->addIncome();
}

/*void PersonalBudgetManager :: addExpanse()
{
    xmlFileWithExpanses->addExpanse();
}*/

void PersonalBudgetManager :: registerUser()
{
    userManager.registerUser();
}

void PersonalBudgetManager :: logInUser()
{
    userManager.logInUser();
    if (userManager.isUserLoggedIn())
    {
        xmlFileWithIncomes = new XMLFileWithIncomes (userManager.getIdOfLoggedUser(), AuxiliaryMethods::getIncomesFileName());
        incomeManager = new IncomeManager (userManager.getIdOfLoggedUser());
        //xmlFileWithExpanses
    }
}

void PersonalBudgetManager :: logOutUser()
{
    userManager.logOutUser();
}

int PersonalBudgetManager :: getIdOfLoggedUser()
{
    return userManager.getIdOfLoggedUser();
}

void PersonalBudgetManager :: showAllUsers()
{
    userManager.showAllUsers();
}

void PersonalBudgetManager :: changePassword()
{
    userManager.changePassword();
}

char PersonalBudgetManager :: chooseOneOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>>   MAIN MENU   <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Show all users" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethod.getCharacter();

    return choice;
}

char PersonalBudgetManager :: chooseOneOptionFromUserMenu()
{
    char choice;
    system("cls");
    cout << "    >>>   USER MENU   <<<   " << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expanse" << endl;
    cout << "3. Show the balance of the current month" << endl;
    cout << "4. Show the balance of the previous month" << endl;
    cout << "5. Show the balance of the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethod.getCharacter();

    return choice;
}

void PersonalBudgetManager :: showTheBalanceOfTheCurrentMonth()
{
    vector <MoneyRecord> incomesOfTheCurrentMonth = incomeManager->showTheIncomesOfTheCurrentMonth();
    incomeManager->showVector(incomesOfTheCurrentMonth);

    float sum = incomeManager->sumTheMoneyRecordsOfTheLoggedUser(incomesOfTheCurrentMonth);

    cout << endl;
    cout << "Sum of your incomes from the current month: " << setprecision(2) << fixed << sum << endl;
    cout << endl;

    system("pause");
}

void PersonalBudgetManager :: showTheBalanceOfThePreviousMonth()
{
    vector <MoneyRecord> incomesOfThePreviousMonth = incomeManager->showTheIncomesOfThePreviousMonth();
    incomeManager->showVector(incomesOfThePreviousMonth);

    float sum = incomeManager->sumTheMoneyRecordsOfTheLoggedUser(incomesOfThePreviousMonth);

    cout << endl;
    cout << "Sum of your incomes from the previous month: " << setprecision(2) << fixed << sum << endl;
    cout << endl;

    system("pause");
}

void PersonalBudgetManager :: showTheBalanceOfTheSelectedPeriod()
{
    vector <MoneyRecord> incomesOfTheSelectedPeriod = incomeManager->showTheIncomesOfTheSelectedPeriod();
    incomeManager->showVector(incomesOfTheSelectedPeriod);

    float sum = incomeManager->sumTheMoneyRecordsOfTheLoggedUser(incomesOfTheSelectedPeriod);

    cout << endl;
    cout << "Sum of your incomes from the selected period: " << setprecision(2) << fixed << sum << endl;
    cout << endl;

    system("pause");
}
