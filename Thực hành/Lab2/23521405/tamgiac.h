#include "diem.h"

class TamGiac {
private:
    Diem A, B, C;  // Đỉnh của tam giác

public:
    // Phương thức nhập tọa độ các đỉnh
    void Nhap();

    // Phương thức xuất tọa độ các đỉnh
    void Xuat() const;

    // Phương thức tịnh tiến tam giác
    void TinhTien(int dx, int dy);

    // Phương thức phóng to tam giác theo tỉ lệ
    void PhongTo(float tiLe);

    // Phương thức thu nhỏ tam giác theo tỉ lệ
    void ThuNho(float tiLe);

    // Phương thức quay tam giác quanh gốc tọa độ một góc alpha (theo độ)
    void Quay(float goc);
};
