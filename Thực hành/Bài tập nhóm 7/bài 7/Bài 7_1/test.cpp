#include "Thoigian.h"
#include <iostream>
using namespace std;

int main() {
    // Test default constructor
    ThoiGian tg1;
    cout << "Default constructor: " << tg1 << endl;

    // Test parameterized constructor with valid values
    ThoiGian tg2(12, 30, 45);
    cout << "Parameterized constructor with valid input: " << tg2 << endl;

    // Test parameterized constructor with invalid values
    ThoiGian tg3(25, 70, -5);
    cout << "Parameterized constructor with invalid input: " << tg3 << endl;

    // Test input operator (valid input)
    ThoiGian tg4;
    cout << "Enter a valid time (hh mm ss): ";
    cin >> tg4;
    cout << "After input (valid): " << tg4 << endl;

    // Test input operator (invalid input)
    ThoiGian tg5;
    cout << "Enter an invalid time (hh mm ss): ";
    cin >> tg5;
    cout << "After input (invalid): " << tg5 << endl;

    // Test decrement operator
    ThoiGian tg6(0, 0, 1);
    cout << "Initial time: " << tg6 << endl;
    --tg6;
    cout << "After decrement: " << tg6 << endl;

    // Test decrement operator on time that results in invalid state
    ThoiGian tg7(0, 0, 0);
    cout << "Initial time (at zero): " << tg7 << endl;
    --tg7;
    cout << "After decrement (invalid): " << tg7 << endl;

    return 0;
}
