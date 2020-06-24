#include "DateManager.h"

void DateManager :: showTodayDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout << "Today is: " << st.wYear << "-" << st.wMonth << "-" << st.wDay << endl;
}

int DateManager :: turnTodayDateToInt()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    int month = st.wMonth;
    int day = st.wDay;
    int date = turnDateToInt(year,month,day);
    return date;
}

int DateManager :: turnDateToInt(int year, int month, int day)
{
    int date = year*10000 + month*100 + day;
    return date;
}

string DateManager :: askDate()
{
    string date;
    cout << endl;
    cout << "Give your date here (rrrr-mm-dd): ";
    cin >> date;
    cout << endl;
    return date;
}

string DateManager :: checkFormat(string date)
{
    while (true)
    {
        date = askDate();

        if ((date.size()==10) && (date[4]=='-') && (date[7]=='-'))
        {
            break;
        }
        else
        {
            cout << "Format is not correct! Try again.";
            cout << endl;
            continue;
        }
    }
    return date;
}

int DateManager :: returnDay(string date)
{
    string day="";

    for (int i=8; i<=9; i++)
    {
        day=day+date[i];
    }

    int dayInt = AuxiliaryMethods :: convertStringToInt(day);
    return dayInt;
}

int DateManager :: returnMonth(string date)
{
    string month="";

    for (int i=5; i<=6; i++)
    {
        month=month+date[i];
    }

    int monthInt = AuxiliaryMethods :: convertStringToInt(month);
    return monthInt;
}

int DateManager :: returnYear(string date)
{
    string year="";

    for (int i=0; i<=3; i++)
    {
        year=year+date[i];
    }

    int yearInt = AuxiliaryMethods :: convertStringToInt(year);
    return yearInt;
}

bool DateManager :: validateYear(int year, int month, int day)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    if ((year<st.wYear) && (year>=2000))
    {
        return true;
    }
    else if (year==st.wYear)
    {
        if (month<st.wMonth)
        {
            return true;
        }
        else if (month=st.wMonth)
        {
            if (day<st.wDay)
            {
                return true;
            }
            else if (day==st.wDay)
            {
                cout << "This is today :)" << endl;
                exit(0);
            }
        }
    }
    else
        return false;
}

bool DateManager :: validateMonth(int month)
{
    if (!((month >= 1) && (month <=12)))
    {
        return false;
    }
    else
        return true;
}

bool DateManager :: validateDay(int day, int month, int year)
{
    if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && ((day >= 1) && (day <=31)))
    {
        return true;
    }
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && ((day >= 1) && (day <=30)))
    {
        return true;
    }
    else if (month == 2)
    {
        if ((year%4==0) && ((day >= 1) && (day <=29)))
        {
            return true;
        }
        else if ((year%4!=0) && ((day >= 1) && (day <=28)))
        {
            return true;
        }
    }
    return false;
}

int DateManager :: validateDate()
{
    string date;
    int day, month, year;

    while (true)
    {
        date=checkFormat(date);
        day=returnDay(date);
        month=returnMonth(date);
        year=returnYear(date);

        bool goodYear=validateYear(year,month,day);
        bool goodMonth=validateMonth(month);
        bool goodDay=validateDay(day,month,year);

        if ((goodYear == false) || (goodMonth == false) || (goodDay == false))
        {
            cout << "This is not a correct date! Try again." << endl;
            continue;
        }
        else
            break;
    }

    cout << "The date is correct." << endl;

    cout << endl;

    int intdate = turnDateToInt(year,month,day);

    return intdate;
}

string DateManager :: turnDateToStringWithHyphens(int date)
{
    string stringDate = AuxiliaryMethods :: convertIntToString(date);
    string stringYear="", stringMonth="", stringDay="";

    for (int i=0; i<=3; i++)
    {
        stringYear=stringYear+stringDate[i];
    }

    for (int i=4; i<=5; i++)
    {
        stringMonth=stringMonth+stringDate[i];
    }

    for (int i=6; i<=7; i++)
    {
        stringDay=stringDay+stringDate[i];
    }

    string stringDateWithHyphens = stringYear + "-" + stringMonth + "-" + stringDay;

    return stringDateWithHyphens;
}

int DateManager :: convertDateFromStringFormatRRRRMMDDWithHyphensToIntFormatRRRRMMDD(string date)
{
    int year, month, day;
    day = returnDay(date);
    month = returnMonth(date);
    year = returnYear(date);

    int dateRRRRMMDD = turnDateToInt(year, month, day);
    return dateRRRRMMDD;
}
