#ifndef MONEYRECORDMANAGER_H
#define MONEYRECORDMANAGER_H
#include <iostream>
#include "MoneyRecord.h"
#include "XMLFileWithMoneyRecords.h"

using namespace std;

class MoneyRecordManager
{
    XMLFileWithMoneyRecordsExpanse xmlFileWithMoneyRecordsExpanse;
    XMLFileWithMoneyRecordsIncome xmlFileWithMoneyRecordsIncome;

    vector <MoneyRecord> incomes;
    vector <MoneyRecord> expanses;
    vector <MoneyRecord> moneyRecords;

public:
    MoneyRecordManager(int idOfTheLoggedUser) : xmlFileWithMoneyRecordsExpanse(idOfTheLoggedUser), xmlFileWithMoneyRecordsIncome(idOfTheLoggedUser)
    {
        incomes = xmlFileWithMoneyRecordsIncome.getAllMoneyRecords(AuxiliaryMethods::getIncomesFileName());
        expanses = xmlFileWithMoneyRecordsExpanse.getAllMoneyRecords(AuxiliaryMethods::getExpansesFileName());
    }

    int getIdOfNewMoneyRecord();
    int getIdOfTheLoggedUser();
    MoneyRecord askDataOfNewMoneyRecord();
    //void addMoneyRecord(string fileName);
    void addIncome(string fileName);
    void addExpanse(string fileName);
};

#endif
