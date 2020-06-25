#include "DateManager.h"
#include "ExpanseManager.h"
#include "XMLFileWithExpanses.h"

void ExpanseManager :: addExpanse()
{
    XMLFileWithExpanses xmlFileWithExpanses(idOfTheLoggedUser, fileName);
    xmlFileWithExpanses.addExpanseToXMLFile();
    cout << "You have added an expanse" << endl;
    system("pause");
}

MoneyRecord ExpanseManager :: askDataOfNewExpanse()
{
    newMoneyRecord.setMoneyRecordId(getIdOfNewMoneyRecord());

    int date;
    string source;
    float amount;

        string answer;
        cout << "Is it expanse done today? Y/N" << endl;
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
    source = AuxiliaryMethods :: getLine();
    newMoneyRecord.setItem(source);

    return newMoneyRecord;
}

int ExpanseManager :: getIdOfTheLastExpanse()
{
    fstream file;
    int lastExpanseId = 0;
    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);
    XMLFileWithExpanses xmlFileWithExpanses(idOfTheLoggedUser, fileName);

    file.open(fileName.c_str(), ios::out | ios::app);
    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            lastExpanseId=0;
        }
        else
        {
            vector <MoneyRecord> allExpanses = xmlFileWithExpanses.getAllExpanses();
            lastExpanseId=allExpanses.back().moneyRecordId;
        }
    }
    else
        cout << "Could not open the file " << fileName << " and save the data." << endl;
    file.close();

    return lastExpanseId;
}

vector <MoneyRecord> ExpanseManager :: showTheExpansesOfTheCurrentMonth()
{
    XMLFileWithExpanses xmlFileWithExpanses(idOfTheLoggedUser, fileName);
    vector <MoneyRecord> vectorWithExpansesOfCurrentMonth;
    expansesOfTheLoggedUser = xmlFileWithExpanses.getExpansesOfTheLoggedUser();
    expansesOfTheLoggedUser = sortVectorAccordingToDates(expansesOfTheLoggedUser);

    int currentMonth = DateManager :: getTheCurrentMonth();
    int currentYear = DateManager :: getTheCurrentYear();
    int monthOfExpanse, yearOfExpanse;

    for (unsigned int i=0; i<expansesOfTheLoggedUser.size(); i++)
    {
        monthOfExpanse = DateManager :: whatIsTheMonthOfThisDate(expansesOfTheLoggedUser[i].date);
        yearOfExpanse = DateManager :: whatIsTheYearOfThisDate(expansesOfTheLoggedUser[i].date);

        if ((monthOfExpanse==currentMonth) && (yearOfExpanse==currentYear))
        {
            vectorWithExpansesOfCurrentMonth.push_back(expansesOfTheLoggedUser[i]);
        }
    }
    return vectorWithExpansesOfCurrentMonth;
}

vector <MoneyRecord> ExpanseManager :: showTheExpansesOfThePreviousMonth()
{
    XMLFileWithExpanses xmlFileWithExpanses(idOfTheLoggedUser, fileName);
    vector <MoneyRecord> vectorWithExpansesOfPreviousMonth;
    expansesOfTheLoggedUser = xmlFileWithExpanses.getExpansesOfTheLoggedUser();
    expansesOfTheLoggedUser = sortVectorAccordingToDates(expansesOfTheLoggedUser);

    int currentMonth = DateManager :: getTheCurrentMonth();
    int currentYear = DateManager :: getTheCurrentYear();
    int monthOfExpanse, yearOfExpanse;

    for (unsigned int i=0; i<expansesOfTheLoggedUser.size(); i++)
    {
        monthOfExpanse = DateManager :: whatIsTheMonthOfThisDate(expansesOfTheLoggedUser[i].date);
        yearOfExpanse = DateManager :: whatIsTheYearOfThisDate(expansesOfTheLoggedUser[i].date);

        if( ((monthOfExpanse==currentMonth-1) && (yearOfExpanse==currentYear)) || ((monthOfExpanse==12) && (currentMonth==1) && (yearOfExpanse==currentYear-1)) )
        {
            vectorWithExpansesOfPreviousMonth.push_back(expansesOfTheLoggedUser[i]);
        }
    }

    return vectorWithExpansesOfPreviousMonth;
}

vector <MoneyRecord> ExpanseManager :: showTheExpansesOfTheSelectedPeriod(int dateBegin, int dateEnd)
{
    XMLFileWithExpanses xmlFileWithExpanses(idOfTheLoggedUser, fileName);
    vector <MoneyRecord> vectorWithExpansesOfTheSelectedPeriod;
    expansesOfTheLoggedUser = xmlFileWithExpanses.getExpansesOfTheLoggedUser();
    expansesOfTheLoggedUser = sortVectorAccordingToDates(expansesOfTheLoggedUser);

    for (unsigned int i=0; i<expansesOfTheLoggedUser.size(); i++)
    {
        if( (expansesOfTheLoggedUser[i].date>=dateBegin) && (expansesOfTheLoggedUser[i].date<=dateEnd) )
        {
            vectorWithExpansesOfTheSelectedPeriod.push_back(expansesOfTheLoggedUser[i]);
        }
    }

    return vectorWithExpansesOfTheSelectedPeriod;
}
