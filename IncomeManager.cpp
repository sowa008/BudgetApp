#include "IncomeManager.h"
#include "AuxiliaryMethods.h"

float IncomeManager :: askAboutIncome()
{
    float income;
    cout << "Add income: " << endl;
    cin >> income;
    return income;
}
