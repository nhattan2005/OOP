#include <iostream>
using namespace std;

struct Date {
    int day, month, year;

    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) {
        switch (m) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(y) ? 29 : 28;
            default: return 31;
        }
    }

    Date nextDay() {
        int d = day, m = month, y = year;
        if (d < daysInMonth(m, y)) {
            d++;
        } else {
            d = 1;
            if (m < 12) {
                m++;
            } else {
                m = 1;
                y++;
            }
        }
        return {d, m, y};
    }

    Date previousDay() {
        int d = day, m = month, y = year;
        if (d > 1) {
            d--;
        } else {
            if (m > 1) {
                m--;
                d = daysInMonth(m, y);
            } else {
                m = 12;
                d = 31;
                y--;
            }
        }
        return {d, m, y};
    }

    int dayOfYear() {
        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year)) {
            daysInMonths[1] = 29;
        }
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonths[i];
        }
        dayOfYear += day;
        return dayOfYear;
    }

    void print() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    int day, month, year;
    cout << "Enter a date (dd mm yyyy): ";
    cin >> day >> month >> year;

    Date date = {day, month, year};

    cout << "The next day is: ";
    Date next = date.nextDay();
    next.print();

    cout << "The previous day was: ";
    Date previous = date.previousDay();
    previous.print();

    cout << "This day is day number " << date.dayOfYear() << " of the year." << endl;

    return 0;
}
