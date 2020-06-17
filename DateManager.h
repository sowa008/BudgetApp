#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "MoneyRecord.h"
#include <string>
#include <windows.h>
#include <winbase.h>

using namespace std;

class DateManager
{

public:

    static void showTodayDate();
    static int turnDateToInt();
    static string askTheDateAndCheckTheFormat();
    static int returnDay(string date);
    static int returnMonth(string date);
    static int returnYear(string date);
    static bool validateDay(int day, int month, int year);
    static bool validateMonth(int month);
    static bool validateYear(int day, int month, int year);
    static int validateDate();

};

#endif
