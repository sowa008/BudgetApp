#include "MoneyRecordManager.h"
#include "MoneyRecord.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

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

    newMoneyRecord.setMoneyRecordId(getIdOfNewMoneyRecord()); //nie ma tej funkcji

    newMoneyRecord.setUserId(getIdOfTheLoggedUser()); //I have to work on it later

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
            date = DateManager :: turnDateToInt();
        }
        else
        {
            date = DateManager :: validateDate();
        }

        newMoneyRecord.setDate(date);

    cout << "From where you have this income (enter item): ";
    cin >> item; //lepiej getlinem, ale nie dziala
    newMoneyRecord.setItem(item);

    cout << "What is the amount? : ";
    cin >> amount;
    newMoneyRecord.setAmount(amount);

    return newMoneyRecord;
}

void MoneyRecordManager :: addMoneyRecord(float moneyRecord)
{

    string answer;

    while (1)
    {
    cout << "Is it record from today? Y/N" << endl;
    cin >> answer;

    answer =  AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToSmall(answer);

    if (answer == "Y")
    {
        cout << "Today is June :)" << endl;
        break;
    }

    else if (answer == "N")
    {
        cout << "This is record from the past!" << endl;
        break;
    }

    else cout << "Wrong answer!" << endl;
    }

    cout << "You have one record: " << moneyRecord << endl;
    system("pause");
}
