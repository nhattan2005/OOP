#include "Thoigian.h"
#include <iostream>
using namespace std;

ThoiGian::ThoiGian() : gio(0), phut(0), giay(0) {}

ThoiGian::~ThoiGian() {
    gio = phut = giay = 0; // Reset state
}

ThoiGian::ThoiGian(int a, int b, int c) {
    if (a >= 24 || a < 0 || b >= 60 || b < 0 || c >= 60 || c < 0) {
        cout << "Khong Hop Le" << endl;
        gio = phut = giay = 0; // Reset state
    } else {
        gio = a;
        phut = b;
        giay = c;
    }
}

void ThoiGian::operator--() {
    int all_the_time_combine = gio * 3600 + phut * 60 + giay;
    if (all_the_time_combine <= 0) {
        cout << "Khong Hop Le" << endl;
        gio = phut = giay = 0; // Reset state
    } else {
        all_the_time_combine--;
        gio = all_the_time_combine / 3600;
        phut = (all_the_time_combine % 3600) / 60;
        giay = all_the_time_combine % 60;
    }
}

ostream& operator<<(ostream& os, ThoiGian& t) {
    os << t.gio << " gio, " << t.phut << " phut, " << t.giay << " giay";
    return os;
}

istream& operator>>(istream& is, ThoiGian& t) {
    is >> t.gio >> t.phut >> t.giay;
    if (t.gio >= 24 || t.gio < 0 || t.phut >= 60 || t.phut < 0 || t.giay >= 60 || t.giay < 0) {
        cout << "Khong Hop Le" << endl;
        t.gio = t.phut = t.giay = 0; // Reset state
    }
    return is;
}
