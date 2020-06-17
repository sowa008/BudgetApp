#ifndef MONEYRECORDMANAGER_H
#define MONEYRECORDMANAGER_H
#include <iostream>
#include "MoneyRecord.h"

using namespace std;

class MoneyRecordManager
{
    vector <MoneyRecord> moneyRecords;

public:

    int getIdOfNewMoneyRecord();
    int getIdOfTheLoggedUser();
    MoneyRecord askDataOfNewMoneyRecord();
    void addMoneyRecord(float moneyRecord);

};

#endif
