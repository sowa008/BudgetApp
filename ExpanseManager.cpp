#include "ExpanseManager.h"
#include "AuxiliaryMethods.h"

int ExpanseManager :: getIdOfNewExpanse()
{
    if (expanses.empty() == true)
        return 1;
    else
        return expanses.back().getMoneyRecordId() + 1;
}

MoneyRecord ExpanseManager :: askDataOfNewExpanse()
{
    MoneyRecord newExpanse;

    newExpanse.setMoneyRecordId(getIdOfNewExpanse());

    newExpanse.setUserId(getIdOfTheLoggedUser());

    int date;
    string item;
    float amount;

    cin.sync();

        string answer;
        cout << "Is it expanse from today? Y/N" << endl;
        cin >> answer;

        if (answer == "Y" || answer == "y")
        {
            DateManager :: showTodayDate();
            date = DateManager :: turnDateToInt();
        }
        else
        {
            date = DateManager :: validateDate();
        }

        newExpanse.setDate(date);

    cout << "What did you spend money for: ";
    cin >> item; //lepiej getlinem, ale nie dziala
    newExpanse.setItem(item);

    cout << "What amount did you spend? : ";
    cin >> amount;
    newExpanse.setAmount(amount);

    return newExpanse;
}

void ExpanseManager :: addExpanseToXMLFile(string fileName)
{
    fstream file;
    int lastExpanseId = 0;
    int expanseId=0;
    int userId=0;
    int date=0;
    string item="";
    float amount=0;

    MoneyRecordManager moneyRecordManager(idOfTheLoggedUser);

    MoneyRecord newExpanse = moneyRecordManager.askDataOfNewExpanse();

    file.open(fileName.c_str(), ios::out | ios::app);

    if (file.good() == true)
    {
        if (AuxiliaryMethods::isThisFileEmpty(file) == true)
        {
            lastMoneyRecordId=0;;
        }
        else
        {
            vector <MoneyRecord> allMoneyRecords = getAllMoneyRecords(fileName);
            lastMoneyRecordId=allMoneyRecords.back().moneyRecordId;
        }
    }
    else
        cout << "Could not open the file " << fileName << " and save the data." << endl;
    file.close();

    cout << "Id ostatniego wydatku przed dodaniem nowego: " << lastExpanseId << endl;

    newExpanse.moneyRecordId = lastExpanseId+1;

    CMarkup xml;

    xml.Load(fileName);

    if (xml.FindElem() == false)
    {
        xml.AddElem("expanses");
    }

    //int moneyRecordId=0;
    //int userId=0;
    //int date=0;
    //string item="";
    //float amount=0;

    xml.IntoElem();
    xml.AddElem( "expanse" );
    xml.IntoElem();
    xml.AddElem( "expanseId", newExpanse.moneyRecordId );
    xml.AddElem( "userId", idOfTheLoggedUser );
    xml.AddElem( "date", newExpanse.date );
    xml.AddElem( "item", newExpanse.item );
    xml.AddElem( "amount", newExpanse.amount );

    if (xml.FindElem() == false)
    {
        xml.AddElem("expanses");
    }

    string csXML = xml.GetDoc();

    file.open(fileName, ios::out);

    file << csXML << endl;

    file.close();
}
