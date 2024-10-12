#include <bits/stdc++.h>
#include "polygon.h"
using namespace std;

// Constructor khởi tạo số đỉnh là 0 và mảng tọa độ trống
Polygon::Polygon() {
    n = 0;
    x = y = nullptr;
}

// Destructor giải phóng bộ nhớ
Polygon::~Polygon() {
    delete[] x;
    delete[] y;
}

// Phương thức nhập số đỉnh và tọa độ các đỉnh
void Polygon::Nhap() {
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;

    if (n < 3) {
        cout << "So dinh phai lon hon 2!" << endl;
        return;
    }

    // Cấp phát bộ nhớ cho các mảng tọa độ
    x = new float[n];
    y = new float[n];

    // Nhập tọa độ cho từng đỉnh
    for (int i = 0; i < n; ++i) {
        cout << "Nhap toa do diem thu " << i+1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
}

// Phương thức tính diện tích đa giác bằng công thức Shoelace
float Polygon::TinhDienTich() const {
    float area = 0;

    // Tính toán dựa theo công thức Shoelace
    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;  // Điểm tiếp theo (quay vòng)
        area += x[i] * y[next] - y[i] * x[next];
    }

    return fabs(area) / 2.0;  // Lấy giá trị tuyệt đối và chia đôi
}

// Phương thức xuất diện tích
void Polygon::XuatDienTich() const {
    float area = TinhDienTich();
    cout << "Dien tich cua da giac: " << area << endl;
}
