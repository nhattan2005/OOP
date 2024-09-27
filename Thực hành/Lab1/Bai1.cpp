#include <bits/stdc++.h>
using namespace std;

struct phanso {
    int tu, mau;

    phanso(int tu = 0, int mau = 1) {
        if (mau == 0) {
            throw invalid_argument("Mau so khong duoc bang 0");
        }
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
        this->tu = tu;
        this->mau = mau;
    }

    void print() const {
        if (mau == 1) cout << tu;
        else if (tu == 0) cout << 0;
        else cout << tu << "/" << mau;
    }

    phanso rutgon() const {
        int ucln = __gcd(abs(tu), abs(mau));
        return phanso(tu / ucln, mau / ucln);
    }
};

int main() {
    try {
        int tu, mau;
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;

        phanso ps(tu, mau);
        ps = ps.rutgon();
        cout << "Phan so rut gon: ";
        ps.print();
        cout << endl;

    } catch (const invalid_argument &e) {
        cerr << "Loi: " << e.what() << endl;
    }

    return 0;
}
