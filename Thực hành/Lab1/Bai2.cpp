#include <bits/stdc++.h>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
    void print() const {
        if (mau == 0) {
            cout << "Error: Denominator cannot be zero" << endl;
        } else if (mau == 1) {
            cout << tu << endl;
        } else if (tu == 0) {
            cout << 0 << endl;
        } else {
            cout << tu << "/" << mau << endl;
        }
    }

    void rutGon() {
        if (mau == 0) return;
        int ucln = __gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

    bool operator>(const PhanSo& ps) const {
        return tu * ps.mau > ps.tu * mau;
    }
};

PhanSo nhapPhanSo() {
    PhanSo ps;
    cout << "Enter numerator and denominator: ";
    cin >> ps.tu >> ps.mau;

    while (ps.mau == 0) {
        cout << "Error: Denominator cannot be zero. Please enter again: ";
        cin >> ps.tu >> ps.mau;
    }

    ps.rutGon();
    return ps;
}

int main() {
    cout << "Enter the first fraction:\n";
    PhanSo phanSo1 = nhapPhanSo();

    cout << "Enter the second fraction:\n";
    PhanSo phanSo2 = nhapPhanSo();

    if (phanSo1 > phanSo2) {
        cout << "The largest fraction is: ";
        phanSo1.print();
    } else {
        cout << "The largest fraction is: ";
        phanSo2.print();
    }

    return 0;
}
