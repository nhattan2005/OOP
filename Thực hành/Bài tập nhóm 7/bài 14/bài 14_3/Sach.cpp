#include "Sach.h"

void Sach::Nhap() {
    std::cin >> MaSach >> TenSach >> NhaXuatBan >> soluong >> dongia;
}

void Sach::Xuat() const {
    std::cout << MaSach << " " << TenSach << " " << NhaXuatBan << " "
              << soluong << " " << dongia << " " << thanhtien << std::endl;
}

bool Sach::operator<(const Sach& b) const {
    return thanhtien < b.thanhtien;
}

bool Sach::operator>(const Sach& b) const {
    return thanhtien > b.thanhtien;
}

void SachGiaoKhoa::Nhap() {
    Sach::Nhap();
    std::cin >> TinhTrang;
    thanhtien = soluong * dongia * (TinhTrang + 1) / 2.0;
}

void SachThamKhao::Nhap() {
    Sach::Nhap();
    std::cin >> TienThue;
    thanhtien = soluong * dongia + TienThue;
}
