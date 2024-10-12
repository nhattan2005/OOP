#include <iostream>
#include <cmath>  // Để sử dụng sin và cos
#include "dagiac.h"
using namespace std;

// Constructor: khởi tạo đa giác với số đỉnh n
DaGiac::DaGiac(int soDinh) : n(soDinh) {
    Dinh = new Diem[n];  // Cấp phát động mảng Dinh
}

// Destructor: giải phóng bộ nhớ
DaGiac::~DaGiac() {
    delete[] Dinh;
}

// Phương thức nhập tọa độ các đỉnh đa giác
void DaGiac::Nhap() {
    for (int i = 0; i < n; i++) {
        int x, y;
        cout << "Nhap toa do dinh " << i + 1 << ": ";
        cin >> x >> y;
        Dinh[i].SetHoanhDo(x);
        Dinh[i].SetTungDo(y);
    }
}

// Phương thức xuất tọa độ các đỉnh đa giác
void DaGiac::Xuat() const {
    for (int i = 0; i < n; i++) {
        cout << "Dinh " << i + 1 << ": ";
        Dinh[i].Xuat();
    }
}

// Phương thức tịnh tiến đa giác
void DaGiac::TinhTien(int dx, int dy) {
    for (int i = 0; i < n; i++) {
        Dinh[i].TinhTien(dx, dy);
    }
}

// Phương thức phóng to đa giác theo tỉ lệ
void DaGiac::PhongTo(float tiLe) {
    for (int i = 0; i < n; i++) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * tiLe);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * tiLe);
    }
}

// Phương thức thu nhỏ đa giác theo tỉ lệ
void DaGiac::ThuNho(float tiLe) {
    PhongTo(1 / tiLe);  // Thu nhỏ bằng cách phóng to với tỉ lệ nghịch
}

// Phương thức quay đa giác quanh gốc tọa độ
void DaGiac::Quay(float goc) {
    float rad = goc * M_PI / 180.0;  // Chuyển đổi góc từ độ sang radian
    for (int i = 0; i < n; i++) {
        int x = Dinh[i].GetHoanhDo();
        int y = Dinh[i].GetTungDo();
        Dinh[i].SetHoanhDo(x * cos(rad) - y * sin(rad));
        Dinh[i].SetTungDo(x * sin(rad) + y * cos(rad));
    }
}

