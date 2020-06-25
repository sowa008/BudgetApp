#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

class AuxiliaryMethods
{

public:

        static bool isThisFileEmpty(fstream &file);
        static int convertStringToInt(string text);
        static string convertIntToString(int number);
        static string convertFloatToString(float number);
        static float convertStringToFloat(string text);
        static char getCharacter();
        static string getLine();
        static string getUsersFileName();
        static string getIncomesFileName();
        static string getExpansesFileName();
        static string changeFirstLetterToCapitalAndOtherToSmall(string text);

};

#endif
