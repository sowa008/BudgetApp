#ifndef MONEYRECORDMANAGER_H
#define MONEYRECORDMANAGER_H
#include <iostream>
#include "MoneyRecord.h"
#include "XMLFileWithExpanses.h"
#include "XMLFileWithIncomes.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class MoneyRecordManager
{

//    XMLFileWithExpanses xmlFileWithExpanses(int IdOfTheLoggedUser);
//    XMLFileWithIncomes xmlFileWithIncomes(int IdOfTheLoggedUser);

    MoneyRecord newMoneyRecord;

    vector <MoneyRecord> incomes;
    vector <MoneyRecord> expanses;
    vector <MoneyRecord> moneyRecords;

public:
    MoneyRecordManager(int idOfTheLoggedUser)
    {
        //incomes = xmlFileWithIncomes.getAllMoneyRecords(AuxiliaryMethods::getIncomesFileName());
        //expanses = xmlFileWithExpanses.getAllMoneyRecords(AuxiliaryMethods::getExpansesFileName());
    }

    int getIdOfNewMoneyRecord();

    MoneyRecord askDataOfNewIncome();
    MoneyRecord askDataOfNewExpanse();
    //void addMoneyRecord(string fileName);
    //void addIncome(string fileName);
    //void addExpanse(string fileName);
};

#endif
