#include "GiaSuc.h"

GiaSuc::GiaSuc(const string &tenLoai, int soLuong)
    : tenLoai(tenLoai), soLuong(soLuong) {}

string GiaSuc::getTenLoai() const {
    return tenLoai;
}

int GiaSuc::getSoLuong() const {
    return soLuong;
}

void GiaSuc::tangSoLuong(int them) {
    soLuong += them;
}

Bo::Bo(int soLuong) : GiaSuc("Bo", soLuong) {}

string Bo::TiengKeu() const {
    return "Booooo";
}

int Bo::SinhCon() const {
    return rand() % (soLuong + 1);
}

int Bo::ChoSua() const {
    return soLuong * (rand() % 21);
}

Cuu::Cuu(int soLuong) : GiaSuc("Cuu", soLuong) {}

string Cuu::TiengKeu() const {
    return "Beee Beee";
}

int Cuu::SinhCon() const {
    return rand() % (soLuong + 1);
}

int Cuu::ChoSua() const {
    return soLuong * (rand() % 6);
}

De::De(int soLuong) : GiaSuc("De", soLuong) {}

string De::TiengKeu() const {
    return "Ehhhh";
}

int De::SinhCon() const {
    return rand() % (soLuong + 1);
}

int De::ChoSua() const {
    return soLuong * (rand() % 11);
}
