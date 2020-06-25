#include <iostream>
#include "PersonalBudgetManager.h"

using namespace std;

int main()
{
    int loggedUserId = 0;

    PersonalBudgetManager personalBudgetManager;

    while (true)
    {
        if (loggedUserId == 0)
        {
            char choice=personalBudgetManager.chooseOneOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudgetManager.registerUser();
                break;
            case '2':
                personalBudgetManager.logInUser();
                loggedUserId=personalBudgetManager.getIdOfLoggedUser();
                break;
            case '3':
                personalBudgetManager.showAllUsers();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            char choice;
            if (true)

                choice = personalBudgetManager.chooseOneOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                personalBudgetManager.addIncome();
                break;
            case '2':
                //personalBudgetManager.addExpanse();
                  break;
            case '3':
                personalBudgetManager.showTheBalanceOfTheCurrentMonth();
                break;
            case '4':
                personalBudgetManager.showTheBalanceOfThePreviousMonth();
                break;
            case '5':
                personalBudgetManager.showTheBalanceOfTheSelectedPeriod();
                break;
            case '7':
                personalBudgetManager.changePassword();
                break;
            case '8':
                personalBudgetManager.logOutUser();
                loggedUserId=personalBudgetManager.getIdOfLoggedUser();
                break;
            }
        }
    }

    return 0;
}
