 #include "MoneyRecord.h"

void MoneyRecord :: setMoneyRecordId(int newMoneyRecordId)
{
    if (newMoneyRecordId >= 0)
        moneyRecordId=newMoneyRecordId;
}

void MoneyRecord :: setUserId(int newUserId)
{
    userId=newUserId;
}

void MoneyRecord :: setDate(int newDate)
{
    date=newDate;
}

void MoneyRecord :: setItem(string newItem)
{
    item=newItem;
}

void MoneyRecord :: setAmount(float newAmount)
{
    amount=newAmount;
}

int MoneyRecord :: getMoneyRecordId()
{
    return moneyRecordId;
}

int MoneyRecord :: getUserId()
{
    return userId;
}

int MoneyRecord :: getDate()
{
    return date;
}

string MoneyRecord :: getItem()
{
    return item;
}

float MoneyRecord :: getAmount()
{
    return amount;
}
