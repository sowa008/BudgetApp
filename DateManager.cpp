#include "DateManager.h"

void DateManager :: showTodayDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout << "Today is: " << st.wYear << "-" << st.wMonth << "-" << st.wDay << endl;

    //return date;
}

int DateManager :: turnDateToInt()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    int month = st.wMonth;
    int day = st.wDay;
    int date = year*10000 + month*100 + day;
    return date;
}

string DateManager :: askTheDateAndCheckTheFormat()
{
    string date;
    while (1)
    {
        cout << endl;
        cout << "Give your date here (rrrr-mm-dd): ";
        cin >> date;
        cout << endl;

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

    int dayInt = atoi(day.c_str());

    return dayInt;
}

int DateManager :: returnMonth(string date)
{
    string month="";

    for (int i=5; i<=6; i++)
    {
        month=month+date[i];
    }

    int monthInt = atoi(month.c_str());

    return monthInt;
}

int DateManager :: returnYear(string date)
{
    string year="";

    for (int i=0; i<=3; i++)
    {
        year=year+date[i];
    }

    int yearInt = atoi(year.c_str());

    return yearInt;
}

bool DateManager :: validateYear(int year, int month, int day)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    if (year<st.wYear)
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

    while (1)
    {
        date=askTheDateAndCheckTheFormat();
        day=returnDay(date);
        month=returnMonth(date);
        year=returnYear(date);

        bool goodYear=validateYear(year,month,day);
        if (goodYear == false)
        {
            cout << "This is a future date. You cannot submit neither your income nor your expanse with this date. Try again." << endl;
            continue;
        }

        bool goodMonth=validateMonth(month);
        if (goodMonth == false)
        {
            cout << "This is not a correct date! Try again." << endl;
            continue;
        }

        bool goodDay=validateDay(day,month,year);
        if (goodDay == false)
        {
            cout << "This is not a correct date! Try again." << endl;
            continue;
        }
        else
            break;
    }

    cout << "The date you gave, " << year << "-" << month << "-" << day << ", is correct." << endl;

    cout << endl;

    int intdate = year*10000 + month*100 + day;

    return intdate;
}
