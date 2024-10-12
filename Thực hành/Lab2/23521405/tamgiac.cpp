#include <iostream>
#include <cmath>  // Để sử dụng sin và cos
#include "tamgiac.h"
using namespace std;

// Phương thức nhập tọa độ các đỉnh tam giác
void TamGiac::Nhap() {
    cout << "Nhap toa do dinh A: ";
    int xA, yA;
    cin >> xA >> yA;
    A.SetHoanhDo(xA);
    A.SetTungDo(yA);

    cout << "Nhap toa do dinh B: ";
    int xB, yB;
    cin >> xB >> yB;
    B.SetHoanhDo(xB);
    B.SetTungDo(yB);

    cout << "Nhap toa do dinh C: ";
    int xC, yC;
    cin >> xC >> yC;
    C.SetHoanhDo(xC);
    C.SetTungDo(yC);
}

// Phương thức xuất tọa độ các đỉnh tam giác
void TamGiac::Xuat() const {
    cout << "Dinh A: "; A.Xuat();
    cout << "Dinh B: "; B.Xuat();
    cout << "Dinh C: "; C.Xuat();
}

// Phương thức tịnh tiến tam giác
void TamGiac::TinhTien(int dx, int dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

// Phương thức phóng to tam giác theo tỉ lệ
void TamGiac::PhongTo(float tiLe) {
    A.SetHoanhDo(A.GetHoanhDo() * tiLe);
    A.SetTungDo(A.GetTungDo() * tiLe);
    B.SetHoanhDo(B.GetHoanhDo() * tiLe);
    B.SetTungDo(B.GetTungDo() * tiLe);
    C.SetHoanhDo(C.GetHoanhDo() * tiLe);
    C.SetTungDo(C.GetTungDo() * tiLe);
}

// Phương thức thu nhỏ tam giác theo tỉ lệ
void TamGiac::ThuNho(float tiLe) {
    PhongTo(1 / tiLe);  // Thu nhỏ bằng cách phóng to với tỉ lệ nghịch
}

// Phương thức quay tam giác quanh gốc tọa độ
void TamGiac::Quay(float goc) {
    float rad = goc * M_PI / 180.0;  // Chuyển đổi góc từ độ sang radian

    int xA = A.GetHoanhDo(), yA = A.GetTungDo();
    A.SetHoanhDo(xA * cos(rad) - yA * sin(rad));
    A.SetTungDo(xA * sin(rad) + yA * cos(rad));

    int xB = B.GetHoanhDo(), yB = B.GetTungDo();
    B.SetHoanhDo(xB * cos(rad) - yB * sin(rad));
    B.SetTungDo(xB * sin(rad) + yB * cos(rad));

    int xC = C.GetHoanhDo(), yC = C.GetTungDo();
    C.SetHoanhDo(xC * cos(rad) - yC * sin(rad));
    C.SetTungDo(xC * sin(rad) + yC * cos(rad));
}

