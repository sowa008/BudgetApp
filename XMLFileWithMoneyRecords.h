#ifndef XMLFILEWITHMONEYRECORDS_H
#define XMLFILEWITHMONEYRECORDS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MoneyRecord.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XMLFileWithMoneyRecords
{

public:
    void addMoneyRecordToXMLFile(string fileName);
    vector <MoneyRecord> getAllMoneyRecords(string fileName);
    void readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord);
    void saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords);
};

#endif
