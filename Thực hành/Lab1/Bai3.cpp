#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
    void rutGon() {
        if (mau == 0) return;
        int ucln = __gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

public:
    PhanSo(int t = 0, int m = 1) : tu(t), mau(m) {
        if (mau == 0) {
            throw invalid_argument("The denominator cannot be 0");
        }
        rutGon();
    }

    void print() const {
        if (mau == 1) {
            cout << tu;
        } else if (tu == 0) {
            cout << 0;
        } else {
            cout << tu << "/" << mau;
        }
    }

    PhanSo operator+(const PhanSo& ps) const {
        return PhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau);
    }

    PhanSo operator-(const PhanSo& ps) const {
        return PhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau);
    }

    PhanSo operator*(const PhanSo& ps) const {
        return PhanSo(tu * ps.tu, mau * ps.mau);
    }

    PhanSo operator/(const PhanSo& ps) const {
        if (ps.tu == 0) {
            throw invalid_argument("Error: Cannot divide by a fraction with a numerator of 0");
        }
        return PhanSo(tu * ps.mau, mau * ps.tu);
    }
};

PhanSo nhapPhanSo() {
    int tu, mau;
    cout << "Enter numerator and denominator: ";
    cin >> tu >> mau;
    return PhanSo(tu, mau);
}

int main() {
    cout << "Enter the first fraction:\n";
    PhanSo phanSo1 = nhapPhanSo();

    cout << "Enter the second fraction:\n";
    PhanSo phanSo2 = nhapPhanSo();

    cout << "Sum: ";
    (phanSo1 + phanSo2).print();
    cout << endl;

    cout << "Difference: ";
    (phanSo1 - phanSo2).print();
    cout << endl;

    cout << "Product: ";
    (phanSo1 * phanSo2).print();
    cout << endl;

    cout << "Quotient: ";
    try {
        (phanSo1 / phanSo2).print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    return 0;
}
