#include "DateManager.h"
#include "IncomeManager.h"
#include "XMLFileWithExpanses.h"

#include <cstdlib>

void IncomeManager :: addIncome()
{
    XMLFileWithIncomes xmlFileWithIncomes(idOfTheLoggedUser, fileName);
    xmlFileWithIncomes.addIncomeToXMLFile();
    cout << "You have added an income" << endl;
    system("pause");
}

MoneyRecord IncomeManager :: askDataOfNewIncome()
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

    string amountString, amountProperString;

    cin.ignore();
    amountString = AuxiliaryMethods :: getLine();
    amountProperString = AuxiliaryMethods :: changeComaToDot(amountString);
    amount = stof(amountProperString);
    newMoneyRecord.setAmount(amount);

    cout << "What is the source of this income? : ";
    source = AuxiliaryMethods :: getLine();
    newMoneyRecord.setItem(source);

    return newMoneyRecord;
}

int IncomeManager :: getIdOfTheLastIncome()
{
    fstream file;
    int lastIncomeId = 0;
    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);
    XMLFileWithIncomes xmlFileWithIncomes(idOfTheLoggedUser, fileName);

    file.open(fileName.c_str(), ios::out | ios::app);
    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            lastIncomeId=0;
        }
        else
        {
            vector <MoneyRecord> allIncomes = xmlFileWithIncomes.getAllIncomes();
            lastIncomeId=allIncomes.back().moneyRecordId;
        }
    }
    else
        cout << "Could not open the file " << fileName << " and save the data." << endl;
    file.close();

    return lastIncomeId;
}

vector <MoneyRecord> IncomeManager :: showTheIncomesOfTheCurrentMonth()
{
    XMLFileWithIncomes xmlFileWithIncomes(idOfTheLoggedUser, fileName);
    vector <MoneyRecord> vectorWithIncomesOfCurrentMonth;
    incomesOfTheLoggedUser = xmlFileWithIncomes.getIncomesOfTheLoggedUser();
    incomesOfTheLoggedUser = sortVectorAccordingToDates(incomesOfTheLoggedUser);

    int currentMonth = DateManager :: getTheCurrentMonth();
    int currentYear = DateManager :: getTheCurrentYear();
    int monthOfIncome, yearOfIncome;

    for (unsigned int i=0; i<incomesOfTheLoggedUser.size(); i++)
    {
        monthOfIncome = DateManager :: whatIsTheMonthOfThisDate(incomesOfTheLoggedUser[i].date);
        yearOfIncome = DateManager :: whatIsTheYearOfThisDate(incomesOfTheLoggedUser[i].date);

        if ((monthOfIncome==currentMonth) && (yearOfIncome==currentYear))
        {
            vectorWithIncomesOfCurrentMonth.push_back(incomesOfTheLoggedUser[i]);
        }
    }
    return vectorWithIncomesOfCurrentMonth;
}

vector <MoneyRecord> IncomeManager :: showTheIncomesOfThePreviousMonth()
{
    XMLFileWithIncomes xmlFileWithIncomes(idOfTheLoggedUser, fileName);
    vector <MoneyRecord> vectorWithIncomesOfPreviousMonth;
    incomesOfTheLoggedUser = xmlFileWithIncomes.getIncomesOfTheLoggedUser();
    incomesOfTheLoggedUser = sortVectorAccordingToDates(incomesOfTheLoggedUser);

    int currentMonth = DateManager :: getTheCurrentMonth();
    int currentYear = DateManager :: getTheCurrentYear();
    int monthOfIncome, yearOfIncome;

    for (unsigned int i=0; i<incomesOfTheLoggedUser.size(); i++)
    {
        monthOfIncome = DateManager :: whatIsTheMonthOfThisDate(incomesOfTheLoggedUser[i].date);
        yearOfIncome = DateManager :: whatIsTheYearOfThisDate(incomesOfTheLoggedUser[i].date);

        if( ((monthOfIncome==currentMonth-1) && (yearOfIncome==currentYear)) || ((monthOfIncome==12) && (currentMonth==1) && (yearOfIncome==currentYear-1)) )
        {
            vectorWithIncomesOfPreviousMonth.push_back(incomesOfTheLoggedUser[i]);
        }
    }

    return vectorWithIncomesOfPreviousMonth;
}

vector <MoneyRecord> IncomeManager :: showTheIncomesOfTheSelectedPeriod(int dateBegin, int dateEnd)
{
    XMLFileWithIncomes xmlFileWithIncomes(idOfTheLoggedUser, fileName);
    vector <MoneyRecord> vectorWithIncomesOfTheSelectedPeriod;
    incomesOfTheLoggedUser = xmlFileWithIncomes.getIncomesOfTheLoggedUser();
    incomesOfTheLoggedUser = sortVectorAccordingToDates(incomesOfTheLoggedUser);

    for (unsigned int i=0; i<incomesOfTheLoggedUser.size(); i++)
    {
        if( (incomesOfTheLoggedUser[i].date>=dateBegin) && (incomesOfTheLoggedUser[i].date<=dateEnd) )
        {
            vectorWithIncomesOfTheSelectedPeriod.push_back(incomesOfTheLoggedUser[i]);
        }
    }

    return vectorWithIncomesOfTheSelectedPeriod;
}
