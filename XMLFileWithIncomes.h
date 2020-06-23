#ifndef XMLFILEWITHINCOMES_H
#define XMLFILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MoneyRecord.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XMLFileWithIncomes
{

int idOfTheLoggedUser;
MoneyRecord newMoneyRecord;

public:
    XMLFileWithIncomes(int IdOfTheLoggedUser)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
    }
    void addIncome(string fileName);
    void addIncomeToXMLFile(string fileName);
    vector <MoneyRecord> getAllMoneyRecords(string fileName);
    void readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord);
    void saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords);
};

#endif
