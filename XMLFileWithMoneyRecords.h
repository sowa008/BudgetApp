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
protected:
    int idOfTheLoggedUser;

public:
    XMLFileWithMoneyRecords(int IdOfTheLoggedUser)
    {
        idOfTheLoggedUser=IdOfTheLoggedUser;
    }

    virtual ~XMLFileWithMoneyRecords() {}

    virtual void addMoneyRecordToXMLFile(string fileName) = 0;
    virtual vector <MoneyRecord> getAllMoneyRecords(string fileName) = 0;
    virtual void readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord) = 0;
    virtual void saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords) = 0;
};

class XMLFileWithExpanses : public XMLFileWithMoneyRecords
{
public:
    XMLFileWithExpanses(int IdOfTheLoggedUser) : XMLFileWithMoneyRecords(IdOfTheLoggedUser)
    {
    }

    void addMoneyRecordToXMLFile(string fileName);
    vector <MoneyRecord> getAllMoneyRecords(string fileName);
    void readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord);
    void saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords);
};

class XMLFileWithIncomes : public XMLFileWithMoneyRecords
{

public:
    XMLFileWithIncomes(int IdOfTheLoggedUser) : XMLFileWithMoneyRecords(IdOfTheLoggedUser)
    {
    }

    void addMoneyRecordToXMLFile(string fileName);
    vector <MoneyRecord> getAllMoneyRecords(string fileName);
    void readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord);
    void saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords);
};

#endif
