#include <bits/stdc++.h>

using namespace std;

double calculateSin(double x) {
    double term = x;
    double sum = term;
    int n = 1;

    while (fabs(term) >= 0.00001) {
        term *= -1 * x * x / (2 * n * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}

int main() {
    double x;
    cout << "Enter the value of x (in radians): ";
    cin >> x;

    cout << "sin(" << x << ") = " << calculateSin(x) << endl;

    return 0;
}
