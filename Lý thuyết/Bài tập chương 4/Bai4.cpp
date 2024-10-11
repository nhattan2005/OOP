#include <iostream>
#include <vector>
#include <cmath>  // for pow()

using namespace std;

// Lớp Đa thức
class DaThuc {
private:
    int bac;                // Bậc của đa thức
    vector<double> heSo;    // Mảng chứa các hệ số của đa thức

public:
    // a.1. Khởi tạo một đa thức có bậc bằng 0 hoặc bậc n
    DaThuc(int n = 0) : bac(n), heSo(n + 1, 0) {}

    // a.3. Nhập đa thức
    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        heSo.resize(bac + 1);  // Điều chỉnh kích thước mảng hệ số

        // Nhập các hệ số
        for (int i = bac; i >= 0; i--) {
            cout << "Nhap he so cua x^" << i << ": ";
            cin >> heSo[i];
        }
    }

    // a.4. Xuất đa thức
    void xuat() const {
        for (int i = bac; i >= 0; i--) {
            if (heSo[i] != 0) {
                cout << heSo[i];
                if (i > 0) {
                    cout << "x^" << i;
                }
                if (i > 0 && heSo[i - 1] > 0) {
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }

    // a.2. Tính giá trị của đa thức khi biết giá trị của x
    double tinhGiaTri(double x) const {
        double ketQua = 0;
        for (int i = bac; i >= 0; i--) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }

    // a.5. Cộng hai đa thức
    DaThuc congDaThuc(const DaThuc &dt) const {
        int maxBac = max(bac, dt.bac);
        DaThuc tong(maxBac);

        // Cộng các hệ số tương ứng
        for (int i = 0; i <= maxBac; i++) {
            double heSo1 = (i <= bac) ? heSo[i] : 0;
            double heSo2 = (i <= dt.bac) ? dt.heSo[i] : 0;
            tong.heSo[i] = heSo1 + heSo2;
        }

        return tong;
    }

    // a.6. Trừ hai đa thức
    DaThuc truDaThuc(const DaThuc &dt) const {
        int maxBac = max(bac, dt.bac);
        DaThuc hieu(maxBac);

        // Trừ các hệ số tương ứng
        for (int i = 0; i <= maxBac; i++) {
            double heSo1 = (i <= bac) ? heSo[i] : 0;
            double heSo2 = (i <= dt.bac) ? dt.heSo[i] : 0;
            hieu.heSo[i] = heSo1 - heSo2;
        }

        return hieu;
    }
};

int main() {
    // Nhập hai đa thức
    DaThuc dt1, dt2;

    cout << "Nhap da thuc thu nhat: " << endl;
    dt1.nhap();

    cout << "\nNhap da thuc thu hai: " << endl;
    dt2.nhap();

    // Xuất hai đa thức
    cout << "\nDa thuc thu nhat: ";
    dt1.xuat();

    cout << "Da thuc thu hai: ";
    dt2.xuat();

    // Tính tổng hai đa thức
    DaThuc tong = dt1.congDaThuc(dt2);
    cout << "\nTong hai da thuc: ";
    tong.xuat();

    // Tính hiệu hai đa thức
    DaThuc hieu = dt1.truDaThuc(dt2);
    cout << "Hieu hai da thuc: ";
    hieu.xuat();

    // Tính giá trị của đa thức thứ nhất tại một giá trị x
    double x;
    cout << "\nNhap gia tri cua x: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;

    return 0;
}
