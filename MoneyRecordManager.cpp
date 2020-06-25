#include "MoneyRecordManager.h"

#include<iomanip>

int MoneyRecordManager :: getIdOfNewMoneyRecord()
{
    if (moneyRecords.empty() == true)
        return 1;
    else
        return moneyRecords.back().getMoneyRecordId() + 1;
}

float MoneyRecordManager :: sumTheMoneyRecordsOfTheLoggedUser(vector<MoneyRecord> newVector)
{
    float sum = 0.00;

    for (unsigned int i=0; i<newVector.size(); i++)
    {
        sum = sum + newVector[i].amount;
    }

    return sum;
}

bool compareDates( const MoneyRecord & L, const MoneyRecord & R )
{
    return (L.date > R.date);
}

vector <MoneyRecord> MoneyRecordManager :: sortVectorAccordingToDates(vector<MoneyRecord> newVector)
{
    sort(newVector.begin(), newVector.end(), compareDates);

    return newVector;
}

void MoneyRecordManager :: showVector(vector<MoneyRecord> newVector)
{
    if (newVector.size()!=0)
    {
    cout << "No.  IncomeId.    Date       Amount     Source of Income  " << endl;
    for (unsigned int i=0; i<newVector.size(); i++)
    {
        cout << " " << i+1 << "      ";
        cout << newVector[i].moneyRecordId << "      ";
        cout << DateManager :: turnDateToStringWithHyphens(newVector[i].date) << "    ";
        cout << setprecision(2) << fixed << newVector[i].amount << "     ";
        cout << newVector[i].item << endl;
    }
    }
    else cout << endl << "No data to display!" << endl << endl;
}
