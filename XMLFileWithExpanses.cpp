#include "XMLFileWithExpanses.h"
#include "MoneyRecordManager.h"
#include "ExpanseManager.h"
#include "Markup.h"
#include "MoneyRecord.h"
#include "UserManager.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void XMLFileWithExpanses :: addExpanseToXMLFile()
{
    fstream file;
    string item="";

    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);
    ExpanseManager expanseManager(idOfTheLoggedUser);
    MoneyRecord newMoneyRecord = expanseManager.askDataOfNewExpanse();

    int lastExpanseId = expanseManager.getIdOfTheLastExpanse();

    newMoneyRecord.moneyRecordId = lastExpanseId+1;

    CMarkup xml;

    xml.Load(fileName);

    if (xml.FindElem() == false)
    {
        xml.AddElem("expanses");
    }

    xml.IntoElem();
    xml.AddElem( "expanse" );
    xml.IntoElem();
    xml.AddElem( "expanseId", newMoneyRecord.moneyRecordId );
    xml.AddElem( "userId", idOfTheLoggedUser );

    string date = DateManager :: turnDateToStringWithHyphens(newMoneyRecord.date);
    xml.AddElem( "date", date );

    xml.AddElem( "item", newMoneyRecord.item );

    string amountCovertedToString = AuxiliaryMethods :: convertFloatToString(newMoneyRecord.amount);

    xml.AddElem( "amount", amountCovertedToString );

    if (xml.FindElem() == false)
    {
        xml.AddElem("expanses");
    }

    string csXML = xml.GetDoc();

    file.open(fileName, ios::out);

    file << csXML << endl;

    file.close();
}

vector <MoneyRecord> XMLFileWithExpanses :: getAllExpanses()
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

    while (xml.FindElem("expanse"))
    {
        MoneyRecord newMoneyRecord;

        xml.IntoElem();
        xml.FindElem( "expanseId" );
        int nMoneyRecordId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "userId" );
        int nUserId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "date" );
        string strDate = xml.GetData();
        int nDate = DateManager :: convertDateFromStringFormatRRRRMMDDWithHyphensToIntFormatRRRRMMDD(strDate);
        xml.FindElem( "item" );
        string strItem = xml.GetData();
        xml.FindElem( "amount" );
        float fAmount = AuxiliaryMethods :: convertStringToFloat( xml.GetData() );
        xml.OutOfElem();

        newMoneyRecord.moneyRecordId = nMoneyRecordId;
        newMoneyRecord.userId = nUserId;
        newMoneyRecord.date = nDate;
        newMoneyRecord.item = strItem;
        newMoneyRecord.amount = fAmount;

        allExpanses.push_back(newMoneyRecord);
    }

    return allExpanses;
}

vector <MoneyRecord> XMLFileWithExpanses :: getExpansesOfTheLoggedUser()
{
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);
    expansesOfTheLoggedUser.clear();

    if (bSuccess==false)
    {
        cout << "There is no such file!" << endl;
        return {};
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("expanse"))
    {
        MoneyRecord newMoneyRecord;

        xml.IntoElem();
        xml.FindElem( "expanseId" );
        int nMoneyRecordId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "userId" );
        int nUserId = AuxiliaryMethods :: convertStringToInt( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "date" );
        string strDate = xml.GetData();
        int nDate = DateManager :: convertDateFromStringFormatRRRRMMDDWithHyphensToIntFormatRRRRMMDD(strDate);
        xml.FindElem( "item" );
        string strItem = xml.GetData();
        xml.FindElem( "amount" );
        float fAmount = AuxiliaryMethods :: convertStringToFloat( xml.GetData() );
        xml.OutOfElem();

        newMoneyRecord.moneyRecordId = nMoneyRecordId;
        newMoneyRecord.userId = nUserId;
        newMoneyRecord.date = nDate;
        newMoneyRecord.item = strItem;
        newMoneyRecord.amount = fAmount;

        if (newMoneyRecord.userId == idOfTheLoggedUser)
        {
            expansesOfTheLoggedUser.push_back(newMoneyRecord);
        }
    }

    return expansesOfTheLoggedUser;
}
