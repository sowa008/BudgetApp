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

void PersonalBudgetManager :: addExpanse()
{
    expanseManager->addExpanse();
}

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
        xmlFileWithExpanses = new XMLFileWithExpanses (userManager.getIdOfLoggedUser(), AuxiliaryMethods::getExpansesFileName());

        incomeManager = new IncomeManager (userManager.getIdOfLoggedUser());
        expanseManager = new ExpanseManager (userManager.getIdOfLoggedUser());
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
    cout << endl;
    cout << "Incomes:" << endl;
    vector <MoneyRecord> incomesOfTheCurrentMonth = incomeManager->showTheIncomesOfTheCurrentMonth();
    incomeManager->showVector(incomesOfTheCurrentMonth);

    cout << endl;
    cout << "Expanses:" << endl;
    vector <MoneyRecord> expansesOfTheCurrentMonth = expanseManager->showTheExpansesOfTheCurrentMonth();
    expanseManager->showVector(expansesOfTheCurrentMonth);

    float sumOfIncomes = incomeManager->sumTheMoneyRecordsOfTheLoggedUser(incomesOfTheCurrentMonth);
    float sumOfExpanses = expanseManager->sumTheMoneyRecordsOfTheLoggedUser(expansesOfTheCurrentMonth);

    cout << endl;
    cout << "Balance:" << endl;
    cout << "Sum of your incomes from the current month: " << setprecision(2) << fixed << sumOfIncomes << endl;
    cout << "Sum of your expanses from the current month: " << setprecision(2) << fixed << sumOfExpanses << endl;
    cout << endl;
    cout << "The balance of the current month: " << setprecision(2) << fixed << sumOfIncomes-sumOfExpanses << endl;
    cout << endl;

    system("pause");
}

void PersonalBudgetManager :: showTheBalanceOfThePreviousMonth()
{
    cout << endl;
    cout << "Incomes:" << endl;
    vector <MoneyRecord> incomesOfThePreviousMonth = incomeManager->showTheIncomesOfThePreviousMonth();
    incomeManager->showVector(incomesOfThePreviousMonth);

    cout << endl;
    cout << "Expanses:" << endl;
    vector <MoneyRecord> expansesOfThePreviousMonth = expanseManager->showTheExpansesOfThePreviousMonth();
    expanseManager->showVector(expansesOfThePreviousMonth);

    float sumOfIncomes = incomeManager->sumTheMoneyRecordsOfTheLoggedUser(incomesOfThePreviousMonth);
    float sumOfExpanses = expanseManager->sumTheMoneyRecordsOfTheLoggedUser(expansesOfThePreviousMonth);

    cout << endl;
    cout << "Balance:" << endl;
    cout << "Sum of your incomes from the previous month: " << setprecision(2) << fixed << sumOfIncomes << endl;
    cout << "Sum of your expanses from the previous month: " << setprecision(2) << fixed << sumOfExpanses << endl;
    cout << endl;
    cout << "The balance of the previous month: " << setprecision(2) << fixed << sumOfIncomes-sumOfExpanses << endl;
    cout << endl;

    system("pause");
}

void PersonalBudgetManager :: showTheBalanceOfTheSelectedPeriod()
{
    cout << endl;
    cout << "Incomes:" << endl;

    //najpierw pyta o zakres dat, potem pokazuje wektor

    vector <MoneyRecord> incomesOfTheSelectedPeriod = incomeManager->showTheIncomesOfTheSelectedPeriod();
    incomeManager->showVector(incomesOfTheSelectedPeriod);

    cout << endl;
    cout << "Expanses:" << endl;
    vector <MoneyRecord> expansesOfTheSelectedPeriod = expanseManager->showTheExpansesOfTheSelectedPeriod();
    expanseManager->showVector(expansesOfTheSelectedPeriod);

    float sumOfIncomes = incomeManager->sumTheMoneyRecordsOfTheLoggedUser(incomesOfTheSelectedPeriod);
    float sumOfExpanses = expanseManager->sumTheMoneyRecordsOfTheLoggedUser(expansesOfTheSelectedPeriod);

    cout << endl;
    cout << "Balance:" << endl;
    cout << "Sum of your incomes from the selected period: " << setprecision(2) << fixed << sumOfIncomes << endl;
    cout << "Sum of your expanses from the selected period: " << setprecision(2) << fixed << sumOfExpanses << endl;
    cout << endl;
    cout << "The balance of the previous month: " << setprecision(2) << fixed << sumOfIncomes-sumOfExpanses << endl;
    cout << endl;

    system("pause");
}
