#include "MoneyRecordManager.h"

int MoneyRecordManager :: getIdOfNewMoneyRecord()
{
    if (moneyRecords.empty() == true)
        return 1;
    else
        return moneyRecords.back().getMoneyRecordId() + 1;
}

MoneyRecord MoneyRecordManager :: askDataOfNewIncome()
{
    newMoneyRecord.setMoneyRecordId(getIdOfNewMoneyRecord());

    int date;
    string source;
    float amount;

        string answer;
        cout << "Is it income from today? Y/N" << endl;
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

    cout << "What is the source of this income? : ";

    cin.ignore();
    source = AuxiliaryMethods :: getLine();
    newMoneyRecord.setItem(source);

    return newMoneyRecord;
}

MoneyRecord MoneyRecordManager :: askDataOfNewExpanse()
{
    newMoneyRecord.setMoneyRecordId(getIdOfNewMoneyRecord());

    int date;
    string item;
    float amount;

        string answer;
        cout << "Is it expanse from today? Y/N" << endl;
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

    cout << "Where did you spend the money? : ";

    cin.ignore();
    item = AuxiliaryMethods :: getLine();
    newMoneyRecord.setItem(item);

    return newMoneyRecord;
}


void MoneyRecordManager :: addIncome(string fileName)
{
    xmlFileWithIncomes.addMoneyRecordToXMLFile(fileName);
    cout << "You have added an income" << endl;
    system("pause");
}

void MoneyRecordManager :: addExpanse(string fileName)
{
    xmlFileWithExpanses.addMoneyRecordToXMLFile(fileName);
    cout << "You have added an expanse" << endl;
    system("pause");
}

