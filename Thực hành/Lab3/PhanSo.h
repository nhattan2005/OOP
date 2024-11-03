#include <bits/stdc++.h>
using namespace std;

class PhanSo{
private:
    int iTu, iMau;
public:
    PhanSo();
    PhanSo(int Tu, int Mau);

    PhanSo operator+ (const PhanSo& b) const;
    PhanSo operator- (const PhanSo& b) const;
    PhanSo operator* (const PhanSo& b) const;
    PhanSo operator/ (const PhanSo& b) const;
    bool operator== (const PhanSo& b) const;
    bool operator!= (const PhanSo& b) const;
    bool operator< (const PhanSo& b) const;
    bool operator> (const PhanSo& b) const;
    bool operator<= (const PhanSo& b) const;
    bool operator>= (const PhanSo& b) const;
    friend istream& operator >> (istream &is, PhanSo &b);
    friend ostream& operator << (ostream &os, PhanSo b);
};
