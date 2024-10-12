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
};

#endif
