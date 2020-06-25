#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "MoneyRecordManager.h"
#include "MoneyRecord.h"

#include <iostream>

using namespace std;

class IncomeManager : public MoneyRecordManager
{
    vector <MoneyRecord> incomesOfTheLoggedUser;
    string fileName = (AuxiliaryMethods :: getIncomesFileName());

public:
    IncomeManager(int IdOfTheLoggedUser) : MoneyRecordManager(IdOfTheLoggedUser){}

    MoneyRecord askDataOfNewIncome();
    void addIncome();
    int getIdOfTheLastIncome();
    vector <MoneyRecord> showTheIncomesOfTheCurrentMonth();
    vector <MoneyRecord> showTheIncomesOfThePreviousMonth();
    vector <MoneyRecord> showTheIncomesOfTheSelectedPeriod();

};

#endif
