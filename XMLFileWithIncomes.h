#ifndef XMLFILEWITHINCOMES_H
#define XMLFILEWITHINCOMES_H

#include "MoneyRecord.h"
#include "MoneyRecordManager.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class XMLFileWithIncomes
{
    MoneyRecord newMoneyRecord;
    int idOfTheLoggedUser;
    string fileName;
    vector <MoneyRecord> allIncomes;
    vector <MoneyRecord> incomesOfTheLoggedUser;

public:
    XMLFileWithIncomes(int IdOfTheLoggedUser, string FileName)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
        fileName = FileName;
    }

    void addIncomeToXMLFile();
    vector <MoneyRecord> getAllIncomes();
    vector <MoneyRecord> getIncomesOfTheLoggedUser();
};

#endif
