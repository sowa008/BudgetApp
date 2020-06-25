#ifndef EXPANSEMANAGER_H
#define EXPANSEMANAGER_H

#include "MoneyRecordManager.h"
#include "MoneyRecord.h"

#include <iostream>

using namespace std;

class ExpanseManager : public MoneyRecordManager
{
    vector <MoneyRecord> expansesOfTheLoggedUser;
    string fileName = (AuxiliaryMethods :: getExpansesFileName());

public:
    ExpanseManager(int IdOfTheLoggedUser) : MoneyRecordManager(IdOfTheLoggedUser){}

    MoneyRecord askDataOfNewExpanse();
    void addExpanse();
    int getIdOfTheLastExpanse();
    vector <MoneyRecord> showTheExpansesOfTheCurrentMonth();
    vector <MoneyRecord> showTheExpansesOfThePreviousMonth();
    vector <MoneyRecord> showTheExpansesOfTheSelectedPeriod(int dateBegin, int dateEnd);

};

#endif
