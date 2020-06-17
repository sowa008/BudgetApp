#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <vector>

using namespace std;

class Income
{

public:

    int incomeId;
    int userId;
    int date;
    string item;
    float amount;

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();

};

#endif
