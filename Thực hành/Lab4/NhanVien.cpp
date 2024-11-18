#include <bits/stdc++.h>
#include "NhanVien.h"
using namespace std;
NhanVien::NhanVien(const std::string &ht, const std::string &ms, double luong)
    : HoTen(ht), MaSo(ms), LuongCoBan(luong) {}

void NhanVien::Xuat() const {
    cout << "Ho va ten: " << HoTen << endl;
    cout << "Ma so nhan vien: " << MaSo << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
}

QuanLy::QuanLy(const std::string &ht, const std::string &ms, double luong, double thuong)
    : NhanVien(ht, ms, luong), TyLeThuong(thuong) {}

double QuanLy::TienThuong() const {
    return LuongCoBan * TyLeThuong * 0.01;
}

void QuanLy::Xuat() const {
    cout << "Ho va ten: " << HoTen << endl;
    cout << "Ma so nhan vien: " << MaSo << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "Tien thuong: " << TienThuong() << endl;
}

KySu::KySu(const std::string &ht, const std::string &ms, double luong, double overtime)
    : NhanVien(ht, ms, luong), SoGioLamThem(overtime) {}

double KySu::TienThuong() const {
    return SoGioLamThem * 100000;
}

void KySu::Xuat() const {
    cout << "Ho va ten: " << HoTen << endl;
    cout << "Ma so nhan vien: " << MaSo << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "Tien thuong: " << TienThuong() << endl;
}
