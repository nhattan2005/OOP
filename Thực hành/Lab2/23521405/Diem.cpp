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

// Phương thức nhân đôi hoành độ và tung độ
void Diem::NhanDoi() {
    iHoanh *= 2;
    iTung *= 2;
}

// Phương thức gán điểm về gốc tọa độ
void Diem::GanVeGoc() {
    iHoanh = 0;
    iTung = 0;
}

// Phương thức tịnh tiến điểm theo trục x hoặc trục y
void Diem::TinhTien2(int k, float d) {
    if (k == 0) {  // Tịnh tiến theo trục x
        iHoanh += d;
    } else {       // Tịnh tiến theo trục y
        iTung += d;
    }
}
