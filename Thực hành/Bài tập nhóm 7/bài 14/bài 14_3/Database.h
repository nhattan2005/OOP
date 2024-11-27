#ifndef DATABASE_H
#define DATABASE_H

#include "Sach.h"

class Database {
friend class Sach;
friend class SachGiaoKhoa;
friend class SachThamKhao;
private:
    std::vector<Sach*> data;

public:
    ~Database();
    void Nhap();
    void Xuat() const;
    void TinhTong() const;
    void TienItNhat() const;
    void TimThongTin() const;
};

#endif // DATABASE_H

