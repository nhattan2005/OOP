#include "DonThuc.h"
#include <bits/stdc++.h>
using namespace std;

DonThuc::DonThuc(double a, int b) {
    HeSo = a;
    SoMu = b;
}

DonThuc::~DonThuc() {
    HeSo = -1;
    SoMu = -1;
}

DonThuc::DonThuc() {
    HeSo = 0;
    SoMu = 0;
}

// Define the + operator
DonThuc DonThuc::operator+(const DonThuc b) {
    if (SoMu != b.SoMu) {
        cout << "Error: Cannot add monomials with different exponents." << endl;
        return DonThuc();
    } else {
        return DonThuc(HeSo + b.HeSo, SoMu); // Use SoMu directly
    }
}

void DonThuc::Xuat() {
    cout << "He so | So Mu" << endl;
    cout << HeSo << endl;
    cout << SoMu << endl;
}

double DonThuc::Tinh(double x) {
    return HeSo*pow(x,SoMu);
}
