#include "XMLFileWithIncomes.h"
#include "XMLFileWithExpanses.h"
#include "MoneyRecordManager.h"
#include "Markup.h"
#include "MoneyRecord.h"
#include "UserManager.h"
#include <iostream>
#include <vector>

void XMLFileWithIncomes :: addIncome(string fileName)
{
    addIncomeToXMLFile(fileName);
    cout << "You have added an income" << endl;
    system("pause");
}

void XMLFileWithIncomes :: addIncomeToXMLFile(string fileName)
{
    fstream file;
    int lastMoneyRecordId = 0;
//    int moneyRecordId=0;
//    int userId=0;
//    int date=0;
    string source="";
//    float amount=0;

    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);

    newMoneyRecord = moneyRecordManager.askDataOfNewIncome();

    file.open(fileName.c_str(), ios::out | ios::app);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            lastMoneyRecordId=0;
        }
        else
        {
            vector <MoneyRecord> allMoneyRecords = getAllMoneyRecords(fileName);
            lastMoneyRecordId=allMoneyRecords.back().moneyRecordId;
        }
    }
    else
        cout << "Could not open the file " << fileName << " and save the data." << endl;
    file.close();

    newMoneyRecord.moneyRecordId = lastMoneyRecordId+1;

    CMarkup xml;

    xml.Load(fileName);

    if (xml.FindElem() == false)
    {
        xml.AddElem("incomes");
    }

    xml.IntoElem();
    xml.AddElem( "income" );
    xml.IntoElem();
    xml.AddElem( "incomeId", newMoneyRecord.moneyRecordId );
    xml.AddElem( "userId", idOfTheLoggedUser );
    xml.AddElem( "date", newMoneyRecord.date );
    xml.AddElem( "source", newMoneyRecord.item );
    xml.AddElem( "amount", newMoneyRecord.amount );

    if (xml.FindElem() == false)
    {
        xml.AddElem("incomes");
    }

    string csXML = xml.GetDoc();

    file.open(fileName, ios::out);

    file << csXML << endl;

    file.close();
}

vector <MoneyRecord> XMLFileWithIncomes :: getAllMoneyRecords(string fileName)
{
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

    if (bSuccess==false)
    {
        cout << "There is no such file!" << endl;
        return {};
    }

    xml.FindElem();
    xml.IntoElem();

    vector <MoneyRecord> allMoneyRecords;

    while (xml.FindElem("income"))
    {
        MoneyRecord newMoneyRecord;

        xml.IntoElem();
        xml.FindElem( "incomeId" );
        int nMoneyRecordId = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "userId" );
        int nUserId = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "date" );
        int nDate = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "source" );
        string strSource = xml.GetData();
        xml.FindElem( "amount" );
        float fAmount = stof( xml.GetData() );
        xml.OutOfElem();

        newMoneyRecord.moneyRecordId = nMoneyRecordId;
        newMoneyRecord.userId = nUserId;
        newMoneyRecord.date = nDate;
        newMoneyRecord.item = strSource;
        newMoneyRecord.amount = fAmount;

        allMoneyRecords.push_back(newMoneyRecord);
    }

    return allMoneyRecords;
}

void XMLFileWithIncomes :: readMoneyRecordsFromXMLFile(MoneyRecord newMoneyRecord) //only incomes
{
    fstream file;
//    int moneyRecordId;
//    int userId;
//    int date;
    string source;
//    float amount;

    vector <MoneyRecord> allMoneyRecords;
    CMarkup xml;

    file.open( AuxiliaryMethods::getIncomesFileName(), ios::in);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            cout << "This file is empty" << endl;
        }
        else
        {
            allMoneyRecords = getAllMoneyRecords(AuxiliaryMethods::getIncomesFileName());
            cout << "The number of incomes: " << allMoneyRecords.size() << endl;
            cout << endl;
        }
    }
    else
        cout << "Could not open the file " << AuxiliaryMethods::getIncomesFileName() << endl;

    file.close();

    for (unsigned int i=0; i<allMoneyRecords.size(); i++)
    {
        cout << allMoneyRecords[i].moneyRecordId << endl;
        cout << allMoneyRecords[i].userId << endl;
        cout << allMoneyRecords[i].date << endl;
        cout << allMoneyRecords[i].item << endl;
        cout << allMoneyRecords[i].amount << endl;
        cout << endl;
    }
}

void XMLFileWithIncomes :: saveAllMoneyRecordsToXMLFile(vector<MoneyRecord> allMoneyRecords)
{
    fstream file;

//    int moneyRecordId=0;
//    int userId=0;
//    int date=0;
    string source="";
//    float amount=0;

    file.open(AuxiliaryMethods::getIncomesFileName(), ios::out);

    CMarkup xml;

    xml.AddElem("incomes");
    xml.IntoElem();

    for (unsigned int i=0; i<allMoneyRecords.size(); i++)
    {
        xml.AddElem( "income" );
        xml.IntoElem();
        xml.AddElem( "moneyRecordId", allMoneyRecords[i].moneyRecordId );
        xml.AddElem( "userId", allMoneyRecords[i].userId );
        xml.AddElem( "date", allMoneyRecords[i].date );
        xml.AddElem( "source", allMoneyRecords[i].item );
        xml.AddElem( "amount", allMoneyRecords[i].amount );
        xml.OutOfElem();
    }

    string csXML = xml.GetDoc();

    file << csXML << endl;

    file.close();
}
