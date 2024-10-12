#include <iostream>
#include "diem.h"
using namespace std;

// Phương thức khởi tạo không tham số
Diem::Diem() : iHoanh(0), iTung(0) {}

// Phương thức khởi tạo với tham số
Diem::Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

// Phương thức sao chép
Diem::Diem(const Diem &x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

// Phương thức xuất tọa độ
void Diem::Xuat() const {
    cout << "Toa do: (" << iHoanh << ", " << iTung << ")" << endl;
}

// Phương thức lấy tung độ
int Diem::GetTungDo() const {
    return iTung;
}

// Phương thức lấy hoành độ
int Diem::GetHoanhDo() const {
    return iHoanh;
}

// Phương thức thiết lập tung độ
void Diem::SetTungDo(int Tung) {
    iTung = Tung;
}

// Phương thức thiết lập hoành độ
void Diem::SetHoanhDo(int Hoanh) {
    iHoanh = Hoanh;
}

// Phương thức tịnh tiến điểm
void Diem::TinhTien(int dx, int dy) {
    iHoanh += dx;
    iTung += dy;
}
