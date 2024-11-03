#include "ThoiGian.h"

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    iPhut = (Giay % 3600) / 60;
    iGiay = Giay % 60;
}

ThoiGian ThoiGian::operator+(int Giay) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + Giay);
    return result;
}

ThoiGian ThoiGian::operator-(int Giay) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - Giay);
    return result;
}

ThoiGian ThoiGian::operator+(const ThoiGian& a) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + a.TinhGiay());
    return result;
}

ThoiGian ThoiGian::operator-(const ThoiGian& a) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - a.TinhGiay());
    return result;
}

ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    *this = *this + 1;
    return temp;
}

ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    *this = *this - 1;
    return temp;
}

bool ThoiGian::operator==(const ThoiGian& a) const {
    return this->TinhGiay() == a.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& a) const {
    return !(*this == a);
}

bool ThoiGian::operator>=(const ThoiGian& a) const {
    return this->TinhGiay() >= a.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& a) const {
    return this->TinhGiay() <= a.TinhGiay();
}

bool ThoiGian::operator>(const ThoiGian& a) const {
    return this->TinhGiay() > a.TinhGiay();
}

bool ThoiGian::operator<(const ThoiGian& a) const {
    return this->TinhGiay() < a.TinhGiay();
}

istream& operator>>(istream& is, ThoiGian& tg) {
    cout << "Nhap gio: "; is >> tg.iGio;
    cout << "Nhap phut: "; is >> tg.iPhut;
    cout << "Nhap giay: "; is >> tg.iGiay;
    return is;
}

ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << " gio " << tg.iPhut << " phut " << tg.iGiay << " giay";
    return os;
}

