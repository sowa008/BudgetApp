#ifndef PERSONALBUDGETMANAGER_H
#define PERSONALBUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpanseManager.h"

using namespace std;

class XMLFileWithIncomes;
class XMLFileWithExpanses;

class PersonalBudgetManager
{

    float income, expanse;

    //MoneyRecordManager *moneyRecordManager;
    XMLFileWithIncomes *xmlFileWithIncomes;
    XMLFileWithExpanses *xmlFileWithExpanses;
    UserManager userManager;
    AuxiliaryMethods auxiliaryMethod;
    //IncomeManager incomeManager;
    //ExpanseManager expanseManager;
    //XMLFileWithMoneyRecords xmlFileWithMoneyRecords;

public:

   /* KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowego)
    : uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI (nazwaPlikuTymczasowego)
    */
    PersonalBudgetManager()
    {
    xmlFileWithIncomes=NULL;
    xmlFileWithExpanses=NULL;
    };

    ~PersonalBudgetManager()
    {
    delete xmlFileWithIncomes;
    delete xmlFileWithExpanses;
    xmlFileWithIncomes=NULL;
    xmlFileWithExpanses=NULL;;
    }

  //  void dodajAdresata();
  //  void usunAdresata();
   // int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
   // void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
   // void wyszukajAdresatowPoImieniu();
   // void wyszukajAdresatowPoNazwisku();
   // void edytujAdresata();


    //float askAboutIncome();
    //float askAboutExpanse();

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

};

#endif
