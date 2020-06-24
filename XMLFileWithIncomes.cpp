#include "XMLFileWithIncomes.h"
#include "XMLFileWithExpanses.h"
#include "MoneyRecordManager.h"
#include "Markup.h"
#include "MoneyRecord.h"
#include "UserManager.h"
#include <iostream>
#include <vector>

void XMLFileWithIncomes :: addIncome()
{
    addIncomeToXMLFile();
    cout << "You have added an income" << endl;
    system("pause");
}

int XMLFileWithIncomes :: getIdOfTheLastIncome()
{
    fstream file;
    int lastIncomeId = 0;

    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);

    file.open(fileName.c_str(), ios::out | ios::app);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            lastIncomeId=0;
        }
        else
        {
            vector <MoneyRecord> allIncomes = getAllIncomes();
            lastIncomeId=allIncomes.back().moneyRecordId;
        }
    }
    else
        cout << "Could not open the file " << fileName << " and save the data." << endl;
    file.close();

    return lastIncomeId;
}

void XMLFileWithIncomes :: addIncomeToXMLFile()
{
    fstream file;
    string source="";

    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);
    MoneyRecord newMoneyRecord = moneyRecordManager.askDataOfNewIncome();

    int lastIncomeId = getIdOfTheLastIncome();

    newMoneyRecord.moneyRecordId = lastIncomeId+1;

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

    string date = DateManager :: turnDateToStringWithHyphens(newMoneyRecord.date);
    xml.AddElem( "date", date );

    xml.AddElem( "source", newMoneyRecord.item );

    string amountCovertedToString = AuxiliaryMethods :: convertFloatToString(newMoneyRecord.amount);

    xml.AddElem( "amount", amountCovertedToString );

    if (xml.FindElem() == false)
    {
        xml.AddElem("incomes");
    }

    string csXML = xml.GetDoc();

    file.open(fileName, ios::out);

    file << csXML << endl; //tu pewnie wykrzacza sie zapis amount - zmiennoprzecinkowa=float

    file.close();
}

vector <MoneyRecord> XMLFileWithIncomes :: getAllIncomes()
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

    while (xml.FindElem("income"))
    {
        MoneyRecord newMoneyRecord;

        xml.IntoElem();
        xml.FindElem( "incomeId" );
        int nMoneyRecordId = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "userId" );
        int nUserId = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "date" );
        string strDate = xml.GetData();
        int nDate = DateManager :: convertDateFromStringFormatRRRRMMDDWithHyphensToIntFormatRRRRMMDD(strDate);
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

        allIncomes.push_back(newMoneyRecord);
    }

    return allIncomes;
}

void XMLFileWithIncomes :: readAllIncomesFromXMLFile()
{
    fstream file;

    string source;

    CMarkup xml;

    file.open(fileName, ios::in);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            cout << "This file is empty" << endl;
        }
        else
        {
            allIncomes = getAllIncomes();
            cout << "The number of incomes: " << allIncomes.size() << endl;
            cout << endl;
        }
    }
    else
        cout << "Could not open the file " << fileName << endl;

    file.close();

    for (unsigned int i=0; i<allIncomes.size(); i++)
    {
        cout << allIncomes[i].moneyRecordId << endl;
        cout << allIncomes[i].userId << endl;
        cout << allIncomes[i].date << endl;
        cout << allIncomes[i].item << endl;
        cout << allIncomes[i].amount << endl;
        cout << endl;
    }
}

void XMLFileWithIncomes :: readIncomesOfTheLoggedUserFromXMLFile()
{
    fstream file;

    string source;

    CMarkup xml;

    file.open(fileName, ios::in);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            cout << "This file is empty" << endl;
        }
        else
        {
            allIncomes = getAllIncomes();

            cout << "The number of all the incomes in file: " << allIncomes.size() << endl;
            cout << endl;
        }
    }
    else
        cout << "Could not open the file " << fileName << endl;

    file.close();



    for (unsigned int i=0; i<allIncomes.size(); i++)
    {
        if (allIncomes[i].userId == idOfTheLoggedUser)
        {
        cout << allIncomes[i].moneyRecordId << endl;
        cout << allIncomes[i].userId << endl;
        cout << allIncomes[i].date << endl;
        cout << allIncomes[i].item << endl;
        cout << allIncomes[i].amount << endl;
        cout << endl;
        }
    }
}