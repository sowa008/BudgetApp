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

protected:
    MoneyRecord newMoneyRecord;
    int idOfTheLoggedUser;
    vector <MoneyRecord> moneyRecords;

public:
    MoneyRecordManager(int IdOfTheLoggedUser)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
    }

    int getIdOfNewMoneyRecord();
    float sumTheMoneyRecordsOfTheLoggedUser(vector<MoneyRecord> moneyRecords);
    vector <MoneyRecord> sortVectorAccordingToDates(vector<MoneyRecord> moneyRecords);
    void showVector(vector<MoneyRecord> moneyRecords);
};

#endif
