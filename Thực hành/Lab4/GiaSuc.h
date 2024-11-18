
#ifndef GIASUC_H
#define GIASUC_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class GiaSuc {
protected:
    string tenLoai;
    int soLuong;

public:
    GiaSuc(const string &tenLoai, int soLuong);
    virtual ~GiaSuc() = default;

    virtual string TiengKeu() const = 0;
    virtual int SinhCon() const = 0;
    virtual int ChoSua() const = 0;

    string getTenLoai() const;
    int getSoLuong() const;
    void tangSoLuong(int them);
};

class Bo : public GiaSuc {
public:
    Bo(int soLuong);
    string TiengKeu() const override;
    int SinhCon() const override;
    int ChoSua() const override;
};

class Cuu : public GiaSuc {
public:
    Cuu(int soLuong);
    string TiengKeu() const override;
    int SinhCon() const override;
    int ChoSua() const override;
};

class De : public GiaSuc {
public:
    De(int soLuong);
    string TiengKeu() const override;
    int SinhCon() const override;
    int ChoSua() const override;
};

#endif
