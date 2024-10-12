#include <iostream>
#include "thisinh.h"
using namespace std;

// Phương thức nhập thông tin thí sinh
void ThiSinh::Nhap() {
    cout << "Nhap ten thi sinh: ";
    getline(cin, Ten);

    cout << "Nhap MSSV: ";
    cin >> MSSV;

    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> iNgay >> iThang >> iNam;

    cout << "Nhap diem mon Toan: ";
    cin >> fToan;

    cout << "Nhap diem mon Van: ";
    cin >> fVan;

    cout << "Nhap diem mon Anh: ";
    cin >> fAnh;
}

// Phương thức xuất thông tin thí sinh
void ThiSinh::Xuat() const {
    cout << "Ten thi sinh: " << Ten << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
    cout << "Diem Toan: " << fToan << endl;
    cout << "Diem Van: " << fVan << endl;
    cout << "Diem Anh: " << fAnh << endl;
    cout << "Tong diem: " << Tong() << endl;
}

// Phương thức tính tổng điểm
float ThiSinh::Tong() const {
    return fToan + fVan + fAnh;
}

