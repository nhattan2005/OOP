#include "NgayThangNam.h"

NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) {
    iNam = Nam;
    iThang = Thang;
    iNgay = Ngay;
}

int NgayThangNam::TinhNgay() const {
    return iNam * 365 + iThang * 30 + iNgay;
}

NgayThangNam NgayThangNam::operator+(int ngay) {
    NgayThangNam result = *this;
    result.iNgay += ngay;

    while (result.iNgay > 30) {
        result.iNgay -= 30;
        result.iThang++;
    }
    while (result.iThang > 12) {
        result.iThang -= 12;
        result.iNam++;
    }
    return result;
}

NgayThangNam NgayThangNam::operator-(int ngay) {
    NgayThangNam result = *this;
    result.iNgay -= ngay;

    while (result.iNgay <= 0) {
        result.iNgay += 30;
        result.iThang--;
    }
    while (result.iThang <= 0) {
        result.iThang += 12;
        result.iNam--;
    }
    return result;
}

NgayThangNam NgayThangNam::operator-(const NgayThangNam& a) {
    int totalDays1 = this->TinhNgay();
    int totalDays2 = a.TinhNgay();
    int diff = totalDays1 - totalDays2;

    return NgayThangNam(diff / 365, (diff % 365) / 30, (diff % 365) % 30);
}

NgayThangNam NgayThangNam::operator++() {
    return *this + 1;
}

NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp = *this;
    *this + 1;
    return temp;
}

NgayThangNam NgayThangNam::operator--() {
    return *this - 1;
}

NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    *this - 1;
    return temp;
}

bool NgayThangNam::operator==(const NgayThangNam& a) {
    return iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam;
}

bool NgayThangNam::operator!=(const NgayThangNam& a) {
    return !(*this == a);
}

bool NgayThangNam::operator>=(const NgayThangNam& a) {
    return TinhNgay() >= a.TinhNgay();
}

bool NgayThangNam::operator<=(const NgayThangNam& a) {
    return TinhNgay() <= a.TinhNgay();
}

bool NgayThangNam::operator>(const NgayThangNam& a) {
    return TinhNgay() > a.TinhNgay();
}

bool NgayThangNam::operator<(const NgayThangNam& a) {
    return TinhNgay() < a.TinhNgay();
}

ostream& operator<<(ostream& os, const NgayThangNam& dt) {
    os << dt.iNgay << "/" << dt.iThang << "/" << dt.iNam;
    return os;
}

istream& operator>>(istream& is, NgayThangNam& dt) {
    is >> dt.iNam >> dt.iThang >> dt.iNgay;
    return is;
}

