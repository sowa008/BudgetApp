#include "AuxiliaryMethods.h"

bool AuxiliaryMethods :: isThisFileEmpty(fstream &file)
{
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}

int AuxiliaryMethods :: convertStringToInt(string text)
{
    int numberInt;
    istringstream iss(text);
    iss >> numberInt;
    return numberInt;
}

string AuxiliaryMethods :: convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods :: convertFloatToString(float number)
{
    ostringstream out;
    out.precision(2);
    out << fixed << number;
    return out.str();
}

char AuxiliaryMethods :: getCharacter()
{
    string entry = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            character = entry[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
    }
    return character;
}

string AuxiliaryMethods :: getLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

string AuxiliaryMethods :: getUsersFileName()
{
    return "users.xml";
}

string AuxiliaryMethods :: getIncomesFileName()
{
    return "incomes.xml";
}

string AuxiliaryMethods :: getExpansesFileName()
{
    return "expanses.xml";
}

string AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
