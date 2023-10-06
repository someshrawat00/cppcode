#include <iostream>
using namespace std;

class Date
{
    int year;
    int month;
    int day;
    int currYear;
    int currMonth;
    int currDay;

public:
    Date(int currDay, int currMonth, int currYear)
    {
        this->currYear = currYear;
        this->currMonth = currMonth;
        this->currDay = currDay;
    }

    void calcAge(int day, int month, int year)
    {
        this->year = currYear - year;

        if (currMonth > month)
        {
            this->month = currMonth - month;
        }
        else
        {
            this->year--;
            this->month = (currMonth - month)  + 12;
        }

        if (currDay >= day - 1)
        {
            this->day = currDay - day + 1;
        }
        else
        {
            this->month--;
            this->day = (currDay - day)  + 28;
        }

        
    }

    void displayAge()
    {
        cout << year << " years " << month << " months " << day << " days" << endl;
    }
};

int main()
{
    Date d1( 1, 2, 2023);
    d1.calcAge(3,3,2003);
    d1.displayAge();
    return 0;
}