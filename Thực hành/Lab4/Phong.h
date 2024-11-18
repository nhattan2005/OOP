#ifndef PHONG_H
#define PHONG_H

#include <iostream>
#include <string>
using namespace std;

class Phong {
protected:
    string loaiPhong;
    int soDem;
    double phiDichVu;
    double phiPhucVu;

public:
    Phong(const string &loai, int soDem, double phiDichVu, double phiPhucVu = 0);
    virtual ~Phong() = default;

    virtual double TinhDoanhThu() const = 0;
    string getLoaiPhong() const;
};

class Deluxe : public Phong {
public:
    Deluxe(int soDem, double phiDichVu, double phiPhucVu);
    double TinhDoanhThu() const override;
};

class Premium : public Phong {
public:
    Premium(int soDem, double phiDichVu);
    double TinhDoanhThu() const override;
};

class Business : public Phong {
public:
    Business(int soDem);
    double TinhDoanhThu() const override;
};

#endif
