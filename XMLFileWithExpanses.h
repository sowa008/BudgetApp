#ifndef XMLFILEWITHEXPANSES_H
#define XMLFILEWITHEXPANSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MoneyRecord.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XMLFileWithExpanses
{
    int idOfTheLoggedUser;

public:
    XMLFileWithExpanses(int IdOfTheLoggedUser)
    {
        idOfTheLoggedUser = IdOfTheLoggedUser;
    }

    void addExpanse(string fileName);
    void addExpanseToXMLFile(string fileName);
    vector <MoneyRecord> getAllMoneyRecords(string fileName);
    void readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord);
    void saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords);
};

#endif
