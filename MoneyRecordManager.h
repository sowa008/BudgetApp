#ifndef MONEYRECORDMANAGER_H
#define MONEYRECORDMANAGER_H
#include <iostream>
#include "MoneyRecord.h"
#include "XMLFileWithMoneyRecords.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class MoneyRecordManager
{
    MoneyRecord newMoneyRecord;

    XMLFileWithExpanses xmlFileWithExpanses;
    XMLFileWithIncomes xmlFileWithIncomes;

    vector <MoneyRecord> incomes;
    vector <MoneyRecord> expanses;
    vector <MoneyRecord> moneyRecords;

public:
    MoneyRecordManager(int idOfTheLoggedUser) : xmlFileWithExpanses(idOfTheLoggedUser), xmlFileWithIncomes(idOfTheLoggedUser)
    {
        incomes = xmlFileWithIncomes.getAllMoneyRecords(AuxiliaryMethods::getIncomesFileName());
        expanses = xmlFileWithExpanses.getAllMoneyRecords(AuxiliaryMethods::getExpansesFileName());
    }

    int getIdOfNewMoneyRecord();

    MoneyRecord askDataOfNewIncome();
    MoneyRecord askDataOfNewExpanse();
    //void addMoneyRecord(string fileName);
    void addIncome(string fileName);
    void addExpanse(string fileName);
};

#endif
