#include <iostream>
using namespace std;

class ThoiGian {
private:
    int iGio, iPhut, iGiay;

public:
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);
    int TinhGiay() const;
    void TinhLaiGio(int Giay);

    ThoiGian operator+(int Giay) const;
    ThoiGian operator-(int Giay) const;
    ThoiGian operator+(const ThoiGian& a) const;
    ThoiGian operator-(const ThoiGian& a) const;
    ThoiGian& operator++();
    ThoiGian operator++(int);
    ThoiGian& operator--();
    ThoiGian operator--(int);
    bool operator==(const ThoiGian& a) const;
    bool operator!=(const ThoiGian& a) const;
    bool operator>=(const ThoiGian& a) const;
    bool operator<=(const ThoiGian& a) const;
    bool operator>(const ThoiGian& a) const;
    bool operator<(const ThoiGian& a) const;

    friend istream& operator>>(istream& in, ThoiGian& a);
    friend ostream& operator<<(ostream& out, const ThoiGian& a);
};
