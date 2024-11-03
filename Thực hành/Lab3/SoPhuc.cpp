#include "SoPhuc.h"

SoPhuc::SoPhuc(): dThuc(0), dAo(0) {}

SoPhuc::SoPhuc(int dThuc, int dAo): dThuc(dThuc), dAo(dAo) {}

SoPhuc SoPhuc::operator+ (const SoPhuc& b) const
{
    return SoPhuc(dThuc+b.dThuc, dAo+b.dAo);
}

SoPhuc SoPhuc::operator- (const SoPhuc& b) const
{
    return SoPhuc(dThuc-b.dThuc, dAo-b.dAo);
}

SoPhuc SoPhuc::operator* (const SoPhuc& b) const
{
    return SoPhuc(dThuc*b.dThuc - dAo*b.dAo, dThuc*b.dAo + dAo*b.dThuc);
}

SoPhuc SoPhuc::operator/ (const SoPhuc& b) const
{
    double denominator = b.dThuc * b.dThuc + b.dAo * b.dAo;
    double r = (dThuc * b.dThuc + dAo * b.dAo) / denominator;
    double i = (dAo * b.dThuc - dThuc * b.dAo) / denominator;
    return SoPhuc(r, i);
}

bool SoPhuc::operator== (const SoPhuc& b) const
{
    if(dThuc==b.dThuc && dAo==b.dAo)
        return true;
    else return false;
}

bool SoPhuc::operator!= (const SoPhuc& b) const
{
    if(dThuc!=b.dThuc || dAo!=b.dAo)
        return true;
    else return false;
}

ostream& operator << (ostream &os, SoPhuc b)
{
    os << b.dThuc << "+" << b.dAo << "i";
}

istream& operator >> (istream &is, SoPhuc &b)
{
    cout << "Nhap phan Thuc: ";
    is >> b.dThuc;
    cout << "Nhap phan Ao: ";
    is >> b.dAo;
}
