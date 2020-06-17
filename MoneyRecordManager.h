#ifndef MONEYRECORDMANAGER_H
#define MONEYRECORDMANAGER_H
#include <iostream>
#include "MoneyRecord.h"
#include "XMLFileWithMoneyRecords.h"

using namespace std;

class MoneyRecordManager
{
    XMLFileWithMoneyRecords xmlFileWithMoneyRecords;
    vector <MoneyRecord> moneyRecords;

public:

    int getIdOfNewMoneyRecord();
    int getIdOfTheLoggedUser();
    MoneyRecord askDataOfNewMoneyRecord();
    void addMoneyRecord(string fileName);

};

#endif
