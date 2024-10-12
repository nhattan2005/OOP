#include "diem.h"

class DaGiac {
private:
    int n;        // Số đỉnh của đa giác
    Diem *Dinh;   // Mảng các đỉnh của đa giác

public:
    // Constructor và Destructor
    DaGiac(int soDinh = 3); // Mặc định là tam giác (3 đỉnh)
    ~DaGiac();

    // Phương thức nhập tọa độ các đỉnh
    void Nhap();

    // Phương thức xuất tọa độ các đỉnh
    void Xuat() const;

    // Phương thức tịnh tiến đa giác
    void TinhTien(int dx, int dy);

    // Phương thức phóng to đa giác theo tỉ lệ
    void PhongTo(float tiLe);

    // Phương thức thu nhỏ đa giác theo tỉ lệ
    void ThuNho(float tiLe);

    // Phương thức quay đa giác quanh gốc tọa độ một góc alpha (theo độ)
    void Quay(float goc);
};
