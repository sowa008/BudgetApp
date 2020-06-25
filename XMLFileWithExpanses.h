#ifndef XMLFILEWITHEXPANSES_H
#define XMLFILEWITHEXPANSES_H

#include "MoneyRecord.h"
#include "MoneyRecordManager.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class XMLFileWithExpanses
{
    MoneyRecord newMoneyRecord;
    int idOfTheLoggedUser;
    string fileName;
    vector <MoneyRecord> allExpanses;
    vector <MoneyRecord> expansesOfTheLoggedUser;

public:
    XMLFileWithExpanses(int IdOfTheLoggedUser, string FileName)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
        fileName = FileName;
    }

    void addExpanseToXMLFile();
    vector <MoneyRecord> getAllExpanses();
    vector <MoneyRecord> getExpansesOfTheLoggedUser();
};

#endif
