#include "XMLFileWithIncomes.h"
#include "MoneyRecordManager.h"
#include "IncomeManager.h"
#include "Markup.h"
#include "MoneyRecord.h"
#include "UserManager.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

void XMLFileWithIncomes :: addIncomeToXMLFile()
{
    fstream file;
    string source="";

    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);
    IncomeManager incomeManager(idOfTheLoggedUser);
    MoneyRecord newMoneyRecord = incomeManager.askDataOfNewIncome();

    int lastIncomeId = incomeManager.getIdOfTheLastIncome();

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

    file << csXML << endl;

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
        int nMoneyRecordId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "userId" );
        int nUserId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
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

vector <MoneyRecord> XMLFileWithIncomes :: getIncomesOfTheLoggedUser()
{
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);
    incomesOfTheLoggedUser.clear();

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
        int nMoneyRecordId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "userId" );
        int nUserId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
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

        if (newMoneyRecord.userId == idOfTheLoggedUser)
        {
            incomesOfTheLoggedUser.push_back(newMoneyRecord);
        }
    }

    return incomesOfTheLoggedUser;
}
