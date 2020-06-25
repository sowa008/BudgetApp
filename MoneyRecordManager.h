#ifndef MONEYRECORDMANAGER_H
#define MONEYRECORDMANAGER_H

#include "MoneyRecord.h"
#include "XMLFileWithExpanses.h"
#include "XMLFileWithIncomes.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

#include <iostream>

using namespace std;

class MoneyRecordManager
{
    MoneyRecord newMoneyRecord;

    int idOfTheLoggedUser;

    vector <MoneyRecord> incomes;
    vector <MoneyRecord> expanses;
    vector <MoneyRecord> moneyRecords;

public:
    MoneyRecordManager(int IdOfTheLoggedUser)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
    }

    int getIdOfNewMoneyRecord();

    MoneyRecord askDataOfNewIncome();
    MoneyRecord askDataOfNewExpanse();
    int getIdOfTheLastMoneyRecord(string fileName);
    vector <MoneyRecord> getAllMoneyRecords(string fileName);
};

#endif
