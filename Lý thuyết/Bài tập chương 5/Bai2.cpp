#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tuso;
    int mauso;

public:
    PhanSo(int t = 0, int m = 1) : tuso(t), mauso(m) {}

    int LayTu() const { return tuso; }
    int LayMau() const { return mauso; }
    void GanTu(int t) { tuso = t; }
    void GanMau(int m) { mauso = m; }

    // Toán tử so sánh >
    bool operator>(const PhanSo& ps) {
        return (tuso * ps.mauso) > (ps.tuso * mauso);
    }

    // Toán tử cộng +
    PhanSo operator+(const PhanSo& ps) {
        int tu = tuso * ps.mauso + ps.tuso * mauso;
        int mau = mauso * ps.mauso;
        return PhanSo(tu, mau);
    }

    // Nhập phân số
    void Nhap() {
        cout << "Nhap tu so: "; cin >> tuso;
        cout << "Nhap mau so: "; cin >> mauso;
        if (mauso == 0) {
            cout << "Mau so phai khac 0. Nhap lai." << endl;
            Nhap();
        }
    }

    // Xuất phân số
    void Xuat() const {
        cout << tuso << "/" << mauso << endl;
    }
};


class DSPHANSo {
private:
    PhanSo* arr; // Mảng phân số
    int n;       // Số lượng phần tử trong mảng

public:
    // Constructor
    DSPHANSo(int size) : n(size) {
        arr = new PhanSo[n];
    }

    // Destructor
    ~DSPHANSo() {
        delete[] arr;
    }

    // Nhập giá trị cho các phân số trong mảng
    void NhapDS() {
        for (int i = 0; i < n; ++i) {
            cout << "Nhap phan so thu " << i + 1 << ":" << endl;
            arr[i].Nhap();
        }
    }

    // Tìm phân số có giá trị lớn nhất
    PhanSo TimPhanSoLonNhat() {
        PhanSo max = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Tính tổng các phân số trong mảng
    PhanSo TinhTong() {
        PhanSo tong(0, 1); // Tổng bắt đầu từ 0
        for (int i = 0; i < n; ++i) {
            tong = tong + arr[i];
        }
        return tong;
    }

    // Xuất mảng phân số
    void XuatDS() {
        for (int i = 0; i < n; ++i) {
            arr[i].Xuat();
        }
    }
};

int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    DSPHANSo ds(n);

    // Nhập các phân số
    ds.NhapDS();

    // Xuất các phân số
    cout << "Danh sach phan so:" << endl;
    ds.XuatDS();

    // Tìm phân số lớn nhất
    PhanSo max = ds.TimPhanSoLonNhat();
    cout << "Phan so lon nhat: ";
    max.Xuat();

    // Tính tổng các phân số
    PhanSo tong = ds.TinhTong();
    cout << "Tong cac phan so: ";
    tong.Xuat();
    return 0;
}
