#include "DonThuc.h"

int main() {
    DonThuc d1(3.5, 2), d2(2.5, 2), d3(1.0, 3);

    // Add monomials with the same exponent
    DonThuc sum = d1 + d2;
    // cout << "Sum of d1 and d2: " << sum.HeSo << "x^" << sum.SoMu << endl;
    sum.Xuat();

    // Try adding monomials with different exponents
    DonThuc invalidSum = d1 + d2;
    invalidSum.Xuat();
    cout << invalidSum.Tinh(10) << endl; 

    return 0;
}
