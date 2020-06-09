#ifndef PERSONALBUDGETMANAGER_H
#define PERSONALBUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudgetManager
{
   // const string USERS_FILE_NAME;
    //AdresatManager *adresatManager;
    UserManager userManager;
    AuxiliaryMethods auxiliaryMethod;

public:

   /* KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowego)
    : uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI (nazwaPlikuTymczasowego)
    {
    adresatManager=NULL;
    };

    ~KsiazkaAdresowa()
    {
    delete adresatManager;
    adresatManager=NULL;
    }
*/
  //  void dodajAdresata();
  //  void usunAdresata();
   // int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
   // void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
   // void wyszukajAdresatowPoImieniu();
   // void wyszukajAdresatowPoNazwisku();
   // void edytujAdresata();

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
