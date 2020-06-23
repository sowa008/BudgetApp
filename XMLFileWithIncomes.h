#ifndef XMLFILEWITHINCOMES_H
#define XMLFILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MoneyRecord.h"
#include "MoneyRecordManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XMLFileWithIncomes
{
    int idOfTheLoggedUser;
    string fileName;
    vector <MoneyRecord> allIncomes;

public:
    XMLFileWithIncomes(int IdOfTheLoggedUser, string FileName)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
        fileName = FileName;
    }

    void addIncome();
    int getIdOfTheLastIncome();
    void addIncomeToXMLFile();
    vector <MoneyRecord> getAllIncomes();
    void readAllIncomesFromXMLFile();
    void readIncomesOfTheLoggedUserFromXMLFile();
};

#endif
