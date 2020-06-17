#include "PersonalBudgetManager.h"
#include "UserManager.h"

//void PersonalBudgetManager :: dodajAdresata()
//{
//    adresatManager->dodajAdresata();
//}

void PersonalBudgetManager :: addIncome()
{
    moneyRecordManager->addMoneyRecord(AuxiliaryMethods :: getIncomesFileName());
    //income=incomeManager.askAboutIncome();
    //incomeManager.addMoneyRecord(income);
    //xmlFileWithMoneyRecords.addMoneyRecordToXMLFile(AuxiliaryMethods :: getIncomesFileName()); //made for incomes only
}

void PersonalBudgetManager :: addExpanse()
{
    moneyRecordManager->addMoneyRecord(AuxiliaryMethods :: getExpansesFileName());
}

void PersonalBudgetManager :: registerUser()
{
    userManager.registerUser();
}

void PersonalBudgetManager :: logInUser()
{
    userManager.logInUser();
    //if (userManager.isUserLoggedIn())
    //{
    //    adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    //}
}

void PersonalBudgetManager :: logOutUser()
{
    userManager.logOutUser();
    //delete adresatManager;
    //adresatManager = NULL;
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

//void PersonalBudgetManager :: usunAdresata()
//{
//    adresatManager->usunAdresata();
//}

//void PersonalBudgetManager :: edytujAdresata()
//{
//    adresatManager->edytujAdresata();
//}

//int PersonalBudgetManager :: podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata)
//{
//    return adresatManager->podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata, idOstatniegoAdresata);
//}

//void PersonalBudgetManager :: wyswietlWszystkichAdresatowZalogowanegoUzytkownika()
//{
//    adresatManager->wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
//}

//void PersonalBudgetManager :: wyszukajAdresatowPoImieniu()
//{
//    adresatManager->wyszukajAdresatowPoImieniu();
//}

//void PersonalBudgetManager :: wyszukajAdresatowPoNazwisku()
//{
//    adresatManager->wyszukajAdresatowPoNazwisku();
//}

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
