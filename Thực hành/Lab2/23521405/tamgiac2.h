class TamGiac2 {
private:
    float x1, y1, x2, y2, x3, y3;  // Tọa độ ba điểm của tam giác

public:
    // Phương thức nhập tọa độ 3 điểm
    void Nhap();

    // Phương thức xuất tọa độ sau khi tịnh tiến
    void Xuat() const;

    // Phương thức tịnh tiến theo hướng góc và độ dài
    void TinhTien(float goc, float doDai);
};
