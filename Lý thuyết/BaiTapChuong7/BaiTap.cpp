#include <iostream>
#include <string>
#include <vector>

// Lớp cơ sở cho tất cả nhân viên
class NhanVien {
protected:
    std::string hoTen;
    std::string ngaySinh;
    double luongCoBan;

public:
    NhanVien(std::string hoTen, std::string ngaySinh, double luongCoBan)
        : hoTen(hoTen), ngaySinh(ngaySinh), luongCoBan(luongCoBan) {}

    virtual double tinhLuong() = 0; // Hàm ảo, phải được triển khai trong lớp con
    virtual void xuatThongTin() {
        std::cout << "Ho Ten: " << hoTen << std::endl;
        std::cout << "Ngay Sinh: " << ngaySinh << std::endl;
    }

    std::string getHoTen() { return hoTen; }
};

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
    double troCap;

public:
    NhanVienVanPhong(std::string hoTen, std::string ngaySinh, double luongCoBan,
                      int soNgayLamViec, double troCap)
        : NhanVien(hoTen, ngaySinh, luongCoBan), soNgayLamViec(soNgayLamViec), troCap(troCap) {}

    double tinhLuong() override {
        return luongCoBan + soNgayLamViec * 200000 + troCap;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        std::cout << "So Ngay Lam Viec: " << soNgayLamViec << std::endl;
        std::cout << "Tro Cap: " << troCap << std::endl;
    }
};

class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NhanVienSanXuat(std::string hoTen, std::string ngaySinh, double luongCoBan, int soSanPham)
        : NhanVien(hoTen, ngaySinh, luongCoBan), soSanPham(soSanPham) {}

    double tinhLuong() override {
        return luongCoBan + soSanPham * 2000;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        std::cout << "So San Pham: " << soSanPham << std::endl;
    }
};

class NhanVienQuanLy : public NhanVien {
private:
    double heSoChucVu;
    double thuong;

public:
    NhanVienQuanLy(std::string hoTen, std::string ngaySinh, double luongCoBan,
                    double heSoChucVu, double thuong)
        : NhanVien(hoTen, ngaySinh, luongCoBan), heSoChucVu(heSoChucVu), thuong(thuong) {}

    double tinhLuong() override {
        return luongCoBan * heSoChucVu + thuong;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        std::cout << "He So Chuc Vu: " << heSoChucVu << std::endl;
        std::cout << "Thuong: " << thuong << std::endl;
    }
};

class QuanLyNhanVien {
private:
    std::vector<NhanVien*> dsNhanVien;

public:
    void themNhanVien(NhanVien* nv) {
        dsNhanVien.push_back(nv);
    }

    void xuatDanhSach() {
        std::cout << "Danh Sach Nhan Vien:" << std::endl;
        for (NhanVien* nv : dsNhanVien) {
            nv->xuatThongTin();
            std::cout << "Luong: " << nv->tinhLuong() << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    double tinhTongLuong() {
        double tongLuong = 0;
        for (NhanVien* nv : dsNhanVien) {
            tongLuong += nv->tinhLuong();
        }
        return tongLuong;
    }

    NhanVien* timNhanVien(std::string hoTen) {
        for (NhanVien* nv : dsNhanVien) {
            if (nv->getHoTen() == hoTen) {
                return nv;
            }
        }
        return nullptr;
    }
};

int main() {
    QuanLyNhanVien qlnv;

    qlnv.themNhanVien(new NhanVienVanPhong("Nguyen Van A", "01/01/1990", 5000000, 20, 100000));
    qlnv.themNhanVien(new NhanVienSanXuat("Tran Thi B", "05/05/1995", 4000000, 50));
    qlnv.themNhanVien(new NhanVienQuanLy("Le Van C", "10/10/1980", 6000000, 2.5, 500000));

    qlnv.xuatDanhSach();

    std::cout << "Tong Luong Cong Ty: " << qlnv.tinhTongLuong() << std::endl;

    std::string hoTenTim = "Nguyen Van A";
    NhanVien* nvTim = qlnv.timNhanVien(hoTenTim);
    if (nvTim) {
        std::cout << "Thong Tin Nhan Vien Tim Thay:" << std::endl;
        nvTim->xuatThongTin();
    } else {
        std::cout << "Khong Tim Thay Nhan Vien Co Ho Ten '" << hoTenTim << "'" << std::endl;
    }


    return 0;
}
