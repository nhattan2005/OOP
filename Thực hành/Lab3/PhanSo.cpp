#include "PhanSo.h"

PhanSo::PhanSo(): iTu(0), iMau(1) {}

PhanSo::PhanSo(int Tu, int Mau): iTu(Tu), iMau(Mau) {}

PhanSo PhanSo::operator+ (const PhanSo& b) const
{
    return PhanSo(iTu*b.iMau+b.iTu*iMau,iMau*b.iMau);
}

PhanSo PhanSo::operator- (const PhanSo& b) const
{
    return PhanSo(iTu*b.iMau-b.iTu*iMau,iMau*b.iMau);
}

PhanSo PhanSo::operator* (const PhanSo& b) const
{
    return PhanSo(iTu*b.iTu,iMau*b.iMau);
}

PhanSo PhanSo::operator/ (const PhanSo& b) const
{
    return PhanSo(iTu*b.iMau,iMau*b.iTu);
}

bool PhanSo::operator== (const PhanSo& b) const
{
    double A = (double)iTu/(double)iMau;
    double B = (double)b.iTu/(double)b.iMau;
    if(A==B)
        return 1;
    else return 0;
}

bool PhanSo::operator!= (const PhanSo& b) const
{
    double A = (double)iTu/(double)iMau;
    double B = (double)b.iTu/(double)b.iMau;
    if(A!=B)
        return 1;
    else return 0;
}

bool PhanSo::operator< (const PhanSo& b) const
{
    double A = (double)iTu/(double)iMau;
    double B = (double)b.iTu/(double)b.iMau;
    if(A<B)
        return 1;
    else return 0;
}

bool PhanSo::operator> (const PhanSo& b) const
{
    double A = (double)iTu/(double)iMau;
    double B = (double)b.iTu/(double)b.iMau;
    if(A>B)
        return 1;
    else return 0;
}

bool PhanSo::operator<= (const PhanSo& b) const
{
    double A = (double)iTu/(double)iMau;
    double B = (double)b.iTu/(double)b.iMau;
    if(A<=B)
        return 1;
    else return 0;
}

bool PhanSo::operator >= (const PhanSo& b) const
{
    double A = (double)iTu/(double)iMau;
    double B = (double)b.iTu/(double)b.iMau;
    if(A>=B)
        return 1;
    else return 0;
}

istream& operator >> (istream &is, PhanSo &b)
{
    cout << "Nhap tu so: ";
    cin >> b.iTu;
    cout << "Nhap mau so: ";
    while(1)
    {
        cin >> b.iMau;
        if(b.iMau == 0)
        {
            cout << "Mau phai khac 0!" << endl;
        }
        else break;
    }
}

ostream& operator << (ostream &os, PhanSo b)
{
    cout << b.iTu ;
    if(b.iMau!=0 && b.iMau!=1)
        cout << "/" << b.iMau;
}
