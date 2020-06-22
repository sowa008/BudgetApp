#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include "AuxiliaryMethods.h"
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
    static int turnTodayDateToInt();
    static int turnDateToInt(int year, int month, int day);
    static string askDate();
    static string checkFormat(string date);
    static int returnDay(string date);
    static int returnMonth(string date);
    static int returnYear(string date);
    static bool validateYear(int day, int month, int year);
    static bool validateMonth(int month);
    static bool validateDay(int day, int month, int year);
    static int validateDate();
    static string turnDateToStringWithHyphens(int date);
};

#endif
