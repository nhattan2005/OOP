#include "Phong.h"

Phong::Phong(const string &loai, int soDem, double phiDichVu, double phiPhucVu)
    : loaiPhong(loai), soDem(soDem), phiDichVu(phiDichVu), phiPhucVu(phiPhucVu) {}

string Phong::getLoaiPhong() const {
    return loaiPhong;
}

Deluxe::Deluxe(int soDem, double phiDichVu, double phiPhucVu)
    : Phong("Deluxe", soDem, phiDichVu, phiPhucVu) {}

double Deluxe::TinhDoanhThu() const {
    return soDem * 750000 + phiDichVu + phiPhucVu;
}

Premium::Premium(int soDem, double phiDichVu)
    : Phong("Premium", soDem, phiDichVu) {}

double Premium::TinhDoanhThu() const {
    return soDem * 500000 + phiDichVu;
}

Business::Business(int soDem)
    : Phong("Business", soDem, 0) {}

double Business::TinhDoanhThu() const {
    return soDem * 300000;
}
