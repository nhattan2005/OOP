#include <iostream>
#include <cmath>  // for pow()

using namespace std;

// Lớp Đơn thức (P(x) = ax^b)
class DonThuc {
private:
    double a; // Hệ số
    int b;    // Số mũ (bậc của x)

public:
    // 1. Tạo lập đơn thức (Constructor)
    DonThuc(double heSo = 0, int soMu = 0) : a(heSo), b(soMu) {}

    // 2. Nhập thông tin cho đơn thức
    void nhap() {
        cout << "Nhap he so a: ";
        cin >> a;
        cout << "Nhap so mu b: ";
        cin >> b;
    }

    // 2. Thay đổi thông tin đơn thức
    void thayDoiThongTin(double heSo, int soMu) {
        a = heSo;
        b = soMu;
    }

    // 3. Xuất đơn thức ra màn hình
    void xuat() const {
        cout << a << "x^" << b << endl;
    }

    // 4. Tính giá trị của đơn thức khi biết x
    double tinhGiaTri(double x) const {
        return a * pow(x, b);
    }

    // 5. Tính đạo hàm của đơn thức
    DonThuc daoHam() const {
        if (b == 0) {
            return DonThuc(0, 0); // Đạo hàm của hằng số là 0
        }
        return DonThuc(a * b, b - 1);
    }

    // 6. Tính tổng hai đơn thức (phải cùng bậc)
    DonThuc congDonThuc(const DonThuc &dt) const {
        if (b != dt.b) {
            cout << "Hai don thuc khong cung bac, khong the cong." << endl;
            return DonThuc();
        }
        return DonThuc(a + dt.a, b);
    }

    // Getter cho số mũ
    int getBac() const {
        return b;
    }

    // Getter cho hệ số
    double getHeSo() const {
        return a;
    }
};

int main() {
    // Tạo hai đơn thức
    DonThuc dt1, dt2;

    // Nhập thông tin cho hai đơn thức
    cout << "Nhap don thuc thu nhat:" << endl;
    dt1.nhap();

    cout << "Nhap don thuc thu hai:" << endl;
    dt2.nhap();

    // Xuất hai đơn thức
    cout << "\nDon thuc thu nhat: ";
    dt1.xuat();

    cout << "Don thuc thu hai: ";
    dt2.xuat();

    // Tính tổng hai đơn thức (phải cùng bậc)
    DonThuc tong = dt1.congDonThuc(dt2);
    if (dt1.getBac() == dt2.getBac()) {
        cout << "\nTong hai don thuc: ";
        tong.xuat();
    }

    // Tính giá trị của đơn thức đầu tiên khi biết x
    double x;
    cout << "\nNhap gia tri cua x: ";
    cin >> x;
    cout << "Gia tri cua don thuc thu nhat tai x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;

    // Tính đạo hàm của đơn thức thứ hai
    DonThuc daoHamDt2 = dt2.daoHam();
    cout << "Dao ham cua don thuc thu hai: ";
    daoHamDt2.xuat();

    return 0;
}
