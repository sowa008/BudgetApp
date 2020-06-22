#ifndef MONEYRECORD_H
#define MONEYRECORD_H

#include <iostream>
#include <vector>

using namespace std;

class MoneyRecord
{

public:

    int moneyRecordId;
    int userId;
    int date;
    string item;
    float amount;

    void setMoneyRecordId(int newMoneyRecordId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getMoneyRecordId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
