#include <bits/stdc++.h>
#include "NguoiChoi.h"
using namespace std;

NguoiChoi::NguoiChoi(int id, int t)
    : ID(id), Type(t) {}

NhaCai::NhaCai(int id, double du)
    : NguoiChoi(id, 1), SoDu(du) {}

int NhaCai::getID() const
{
    return this->ID;
}

int NhaCai::getType() const
{
    return this->Type;
}

double NhaCai::getSoDu() const
{
    return this->SoDu;
}

void NhaCai::setSoDu(double x)
{
    this->SoDu = x;
}

CoMoi::CoMoi(int id, int idtrd)
    : NguoiChoi(id, 2), IDTrader(idtrd) {}

int CoMoi::getID() const
{
    return this->ID;
}

int CoMoi::getType() const
{
    return this->Type;
}

double CoMoi::getHoaHong() const
{
    return this->HoaHong;
}

int CoMoi::getIDTrader() const
{
    return this->IDTrader;
}

void CoMoi::setHoaHong(double x)
{
    this->HoaHong = x;
}

Trader::Trader(int id, double du)
    : NguoiChoi(id, 3), SoDu(du) {}

int Trader::getID() const
{
    return this->ID;
}

int Trader::getType() const
{
    return this->Type;
}

double Trader::getSoDu() const
{
    return this->SoDu;
}

void Trader::setSoDu(double x)
{
    this->SoDu = x;
}
