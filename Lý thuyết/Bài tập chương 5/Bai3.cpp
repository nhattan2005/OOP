#include <iostream>
#include <vector>
#include <cmath> // để sử dụng hàm pow tính lũy thừa
using namespace std;

class DaThuc {
private:
    int bac;                  // Bậc của đa thức
    vector<double> hesos;     // Vector chứa các hệ số của đa thức

public:
    // Khởi tạo đa thức bậc 0 (đa thức hằng)
    DaThuc() {
        bac = 0;
        hesos.push_back(0); // hệ số của bậc 0
    }

    // Khởi tạo đa thức bậc n với các hệ số
    DaThuc(int n) {
        bac = n;
        hesos.resize(n + 1); // Đa thức bậc n có (n+1) hệ số
    }

    // Nhập đa thức
    friend istream& operator>>(istream& in, DaThuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        in >> dt.bac;
        dt.hesos.resize(dt.bac + 1);

        for (int i = dt.bac; i >= 0; --i) {
            cout << "Nhap he so bac " << i << ": ";
            in >> dt.hesos[i];
        }
        return in;
    }

    // Xuất đa thức
    friend ostream& operator<<(ostream& out, const DaThuc& dt) {
        for (int i = dt.bac; i >= 0; --i) {
            if (dt.hesos[i] != 0) {
                out << dt.hesos[i];
                if (i > 0) out << "x^" << i;
                if (i > 0 && dt.hesos[i - 1] >= 0) out << " + ";
            }
        }
        out << endl;
        return out;
    }

    // Tính giá trị đa thức tại x
    double TinhGiaTri(double x) const {
        double result = 0;
        for (int i = 0; i <= bac; ++i) {
            result += hesos[i] * pow(x, i);
        }
        return result;
    }

    // Toán tử cộng hai đa thức
    DaThuc operator+(const DaThuc& dt) {
        int max_bac = max(bac, dt.bac);
        DaThuc sum(max_bac);
        for (int i = 0; i <= max_bac; ++i) {
            double heso1 = (i <= bac) ? hesos[i] : 0;
            double heso2 = (i <= dt.bac) ? dt.hesos[i] : 0;
            sum.hesos[i] = heso1 + heso2;
        }
        return sum;
    }

    // Toán tử trừ hai đa thức
    DaThuc operator-(const DaThuc& dt) {
        int max_bac = max(bac, dt.bac);
        DaThuc hieu(max_bac);
        for (int i = 0; i <= max_bac; ++i) {
            double heso1 = (i <= bac) ? hesos[i] : 0;
            double heso2 = (i <= dt.bac) ? dt.hesos[i] : 0;
            hieu.hesos[i] = heso1 - heso2;
        }
        return hieu;
    }
};

int main() {
    DaThuc dt1, dt2;

    // Nhập đa thức thứ nhất
    cout << "Nhap da thuc thu nhat:" << endl;
    cin >> dt1;

    // Nhập đa thức thứ hai
    cout << "Nhap da thuc thu hai:" << endl;
    cin >> dt2;

    // Xuất các đa thức đã nhập
    cout << "Da thuc thu nhat: " << dt1;
    cout << "Da thuc thu hai: " << dt2;

    // Cộng hai đa thức
    DaThuc tong = dt1 + dt2;
    cout << "Tong hai da thuc: " << tong;

    // Trừ hai đa thức
    DaThuc hieu = dt1 - dt2;
    cout << "Hieu hai da thuc: " << hieu;

    // Tính giá trị của đa thức thứ nhất tại x = 2
    double x = 2.0;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << dt1.TinhGiaTri(x) << endl;

    return 0;
}
