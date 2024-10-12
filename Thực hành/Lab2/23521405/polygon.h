class Polygon {
private:
    int n;            // Số đỉnh của đa giác
    float *x, *y;     // Mảng tọa độ x và y của các đỉnh

public:
    // Constructor và Destructor
    Polygon();
    ~Polygon();

    // Phương thức nhập số đỉnh và tọa độ các đỉnh
    void Nhap();

    // Phương thức tính và xuất diện tích
    float TinhDienTich() const;

    // Phương thức xuất diện tích
    void XuatDienTich() const;
};
