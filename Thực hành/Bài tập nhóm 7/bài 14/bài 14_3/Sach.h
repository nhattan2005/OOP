#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Sach {
friend class SachGiaoKhoa;
friend class SachThamKhao;
friend class Database;
protected:
    std::string MaSach;
    std::string TenSach;
    std::string NhaXuatBan;
    int soluong;
    int dongia;
    double thanhtien;
    int loai;

public:
    virtual void Nhap();
    virtual void Xuat() const;
    bool operator<(const Sach& b) const;
    bool operator>(const Sach& b) const;
};

class SachGiaoKhoa : public Sach {
friend class Sach;
friend class SachThamKhao;
friend class Database;
protected:
    int TinhTrang;

public:
    void Nhap() override;
};

class SachThamKhao : public Sach {

protected:
    double TienThue;

public:
    void Nhap() override;
};

#endif // SACH_H

