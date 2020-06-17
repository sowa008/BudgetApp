#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "User.h"

using namespace std;

class AuxiliaryMethods
{

public:

        static bool isThisFileEmpty(fstream &file);
        static int convertStringToInt(string text);
        static string convertIntToString(int number);
        static char getCharacter();
        static string getLine();
        static string getUsersFileName();
        static string getIncomesFileName();
        static string getExpansesFileName();
        static string changeFirstLetterToCapitalAndOtherToSmall(string text);

};

#endif
