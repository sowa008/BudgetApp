#include <iostream>
#include "PersonalBudgetManager.h"

using namespace std;

int main()
{
    int loggedUserId = 0;
    //int lastMoneyRecordId = 0;

    //PersonalBudgetManager personalBudgetManager("Users.xml", "Incomes.xml", "Expanses.xml");
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
                //personalBudgetManager.addMoneyRecord();
                break;
              case '2':
                 // personalBudgetManager.searchMoneyRecordFromCurrentMonth();
                  break;
              case '3':
                 // personalBudgetManager.searchMoneyRecordFromPreviousMonth();
                  break;
              case '4':
                 // personalBudgetManager.searchMoneyRecordFromSelectedPeriod();
                  break;
              case '5':
                 // personalBudgetManager.showAllMoneyRecords();
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
