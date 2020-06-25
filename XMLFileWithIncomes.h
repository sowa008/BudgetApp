#ifndef XMLFILEWITHINCOMES_H
#define XMLFILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>

#include "MoneyRecord.h"
#include "MoneyRecordManager.h"
#include "AuxiliaryMethods.h"

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

    void addIncome();
    int getIdOfTheLastIncome();
    void addIncomeToXMLFile();
    vector <MoneyRecord> getAllIncomes();
    vector <MoneyRecord> getIncomesOfTheLoggedUser();
    vector <MoneyRecord> sortVectorAccordingToDates();
    float sumTheIncomesOfTheLoggedUser(vector<MoneyRecord> newVector);
    vector <MoneyRecord> showTheIncomesOfTheCurrentMonth();
    vector <MoneyRecord> showTheIncomesOfThePreviousMonth();
    vector <MoneyRecord> showTheIncomesOfTheSelectedPeriod();
    void showVector(vector<MoneyRecord> newVector);
};

#endif
