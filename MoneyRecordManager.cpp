#include "MoneyRecordManager.h"

int MoneyRecordManager :: getIdOfNewMoneyRecord()
{
    if (moneyRecords.empty() == true)
        return 1;
    else
        return moneyRecords.back().getMoneyRecordId() + 1;
}

int MoneyRecordManager :: getIdOfTheLoggedUser()
{
    if (moneyRecords.empty() == true)
        return 1;
    else
        return moneyRecords.back().getUserId() + 1;
}

MoneyRecord MoneyRecordManager :: askDataOfNewMoneyRecord()
{
    MoneyRecord newMoneyRecord;

    newMoneyRecord.setMoneyRecordId(getIdOfNewMoneyRecord());
    newMoneyRecord.setUserId(getIdOfTheLoggedUser());

    int date;
    string item;
    float amount;

    cin.sync();

        string answer;
        cout << "Is it record from today? Y/N" << endl;
        cin >> answer;

        if (answer == "Y" || answer == "y")
        {
            DateManager :: showTodayDate();
            date = DateManager :: turnTodayDateToInt();
        }
        else
        {
            date = DateManager :: validateDate();
        }

        newMoneyRecord.setDate(date);

    cout << "What is the amount? : ";
    cin >> amount;
    newMoneyRecord.setAmount(amount);

    cout << "Enter comment to this record (source/item): ";
    //cin >> item; //lepiej getlinem, ale nie dziala
    cin.ignore();
    item = AuxiliaryMethods :: getLine();
    newMoneyRecord.setItem(item);

    return newMoneyRecord;
}

void MoneyRecordManager :: addIncome(string fileName)
{
    xmlFileWithMoneyRecordsIncome.addMoneyRecordToXMLFile(fileName);
    cout << "You have added an income" << endl;
    system("pause");
}

void MoneyRecordManager :: addExpanse(string fileName)
{
    xmlFileWithMoneyRecordsExpanse.addMoneyRecordToXMLFile(fileName);
    cout << "You have added an expanse" << endl;
    system("pause");
}

