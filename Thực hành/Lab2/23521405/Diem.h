#ifndef DIEM_H
#define DIEM_H

class Diem {
private:
    int iHoanh, iTung;

public:
    Diem();

    Diem(int Hoanh, int Tung);

    Diem(const Diem &x);

    void Xuat() const;

    int GetTungDo() const;

    int GetHoanhDo() const;

    void SetTungDo(int Tung);

    void SetHoanhDo(int Hoanh);

    void TinhTien(int dx, int dy);

    // Phương thức nhân đôi hoành độ và tung độ
    void NhanDoi();

    // Phương thức gán điểm về gốc tọa độ
    void GanVeGoc();

    // Phương thức tịnh tiến điểm theo trục x hoặc trục y
    void TinhTien2(int k, float d);
};

#endif
