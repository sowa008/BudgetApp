#ifndef PERSONALBUDGETMANAGER_H
#define PERSONALBUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpanseManager.h"
#include "XMLFileWithMoneyRecords.h"

using namespace std;

class PersonalBudgetManager
{

    float income, expanse;

   // const string USERS_FILE_NAME;
    MoneyRecordManager *moneyRecordManager;
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
    moneyRecordManager=NULL;
    };

    ~PersonalBudgetManager()
    {
    delete moneyRecordManager;
    moneyRecordManager=NULL;
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

};

#endif
