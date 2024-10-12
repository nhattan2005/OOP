#include <iostream>
#include <cmath>
#include "tamgiac2.h"
using namespace std;

#define PI 3.14  // Định nghĩa PI

// Phương thức nhập tọa độ tam giác
void TamGiac2::Nhap() {
    cout << "Nhap toa do ba diem tam giac (x1, y1, x2, y2, x3, y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
}

// Phương thức xuất tọa độ tam giác
void TamGiac2::Xuat() const {
    cout << "(" << x1 << "," << y1 << ")" << endl;
    cout << "(" << x2 << "," << y2 << ")" << endl;
    cout << "(" << x3 << "," << y3 << ")" << endl;
}

// Phương thức tịnh tiến tam giác
void TamGiac2::TinhTien(float goc, float doDai) {
    // Chuyển góc từ độ sang radian
    float radian = goc * PI / 180.0;

    // Tính các giá trị tịnh tiến theo trục x và y
    float dx = doDai * cos(radian);
    float dy = doDai * sin(radian);

    // Tịnh tiến các điểm
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}

