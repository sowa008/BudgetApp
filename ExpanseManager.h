#ifndef EXPANSEMANAGER_H
#define EXPANSEMANAGER_H
#include "MoneyRecordManager.h"
#include <iostream>

using namespace std;

class ExpanseManager : public MoneyRecordManager
{

public:
    int getIdOfNewExpanse();
    MoneyRecord askDataOfNewExpanse();

};

#endif
