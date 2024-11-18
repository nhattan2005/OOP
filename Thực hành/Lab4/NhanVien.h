#include <bits/stdc++.h>
using namespace std;
class NhanVien {
protected:
    std::string HoTen, MaSo;
    double LuongCoBan;
public:
    NhanVien(const std::string &ht, const std::string &ms, double luong);
    virtual ~NhanVien() = default;
    void Xuat() const;
};

class QuanLy : public NhanVien {
    double TyLeThuong;
public:
    QuanLy(const std::string &ht, const std::string &ms, double luong, double thuong);
    double TienThuong() const;
    void Xuat() const;
};

class KySu : public NhanVien {
    double SoGioLamThem;
public:
    KySu(const std::string &ht, const std::string &ms, double luong, double overtime);
    double TienThuong() const;
    void Xuat() const;
};
