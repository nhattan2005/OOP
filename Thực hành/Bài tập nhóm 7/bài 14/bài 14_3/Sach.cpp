#include "Sach.h"
#include <iostream>
using namespace std;

void Sach::Nhap() {
    cout << "Nhap ma sach: ";
    cin >> MaSach;
    cout << "Nhap ten sach: ";
    cin.ignore(); // Để tránh lỗi khi nhập chuỗi
    getline(cin, TenSach);
    cout << "Nhap nha xuat ban: ";
    getline(cin, NhaXuatBan);
    cout << "Nhap so luong: ";
    cin >> soluong;
    cout << "Nhap don gia: ";
    cin >> dongia;
}

void Sach::Xuat() const {
    cout << "Ma sach: " << MaSach << endl;
    cout << "Ten sach: " << TenSach << endl;
    cout << "Nha xuat ban: " << NhaXuatBan << endl;
    cout << "So luong: " << soluong << endl;
    cout << "Don gia: " << dongia << endl;
    cout << "Thanh tien: " << thanhtien << endl;
}

bool Sach::operator<(const Sach& b) const {
    return thanhtien < b.thanhtien;
}

bool Sach::operator>(const Sach& b) const {
    return thanhtien > b.thanhtien;
}

void SachGiaoKhoa::Nhap() {
    Sach::Nhap();
    cout << "Nhap tinh trang (0: Cu, 1: Moi): ";
    cin >> TinhTrang;
    thanhtien = soluong * dongia * (TinhTrang + 1) / 2.0;
}

void SachThamKhao::Nhap() {
    Sach::Nhap();
    cout << "Nhap tien thue: ";
    cin >> TienThue;
    thanhtien = soluong * dongia + TienThue;
}
