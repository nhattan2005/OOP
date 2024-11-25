#include "Database.h"

int main() {
    Database db;
    db.Nhap();
    std::cout << "\nThong tin sach:\n";
    db.Xuat();

    std::cout << "\nTong tien cac loai sach:\n";
    db.TinhTong();

    std::cout << "\nSach co thanh tien thap nhat:\n";
    db.TienItNhat();

    std::cout << "\nTim sach theo nha xuat ban:\n";
    db.TimThongTin();

    return 0;
}
