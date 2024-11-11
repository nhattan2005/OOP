#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
public:
    string maNhanVien;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    int luongCoBan;

    NhanVien(string ma, string ten, int t, string sdt, string em, int lc)
    {
        maNhanVien = ma;
        hoTen = ten;
        tuoi = t;
        soDienThoai = sdt;
        email = em;
        luongCoBan = lc;
    }

    virtual int tinhLuong() = 0; // Phương thức ảo thuần túy để tính lương
};

class LapTrinhVien : public NhanVien
{
public:
    int soGioOvertime;

    LapTrinhVien(string ma, string ten, int t, string sdt, string em, int lc, int overtime)
        : NhanVien(ma, ten, t, sdt, em, lc), soGioOvertime(overtime) {}

    int tinhLuong() override
    {
        return luongCoBan + soGioOvertime * 200000;
    }
};

class KiemChungVien : public NhanVien
{
public:
    int soLoiPhatHien;

    KiemChungVien(string ma, string ten, int t, string sdt, string em, int lc, int soLoi)
        : NhanVien(ma, ten, t, sdt, em, lc), soLoiPhatHien(soLoi) {}

    int tinhLuong() override
    {
        return luongCoBan + soLoiPhatHien * 50000;
    }
};


int main()
{
    vector<NhanVien*> danhSachNhanVien;

    int soLuongNhanVien;
    cout << "Nhap so luong nhan vien: ";
    cin >> soLuongNhanVien;

    for (int i = 0; i < soLuongNhanVien; ++i)
    {
        cout << "Nhap thong tin nhan vien thu " << i+1 << endl;
        string ma, hoTen, soDienThoai, email;
        int tuoi, luongCoBan, loaiNhanVien;

        cout << "Ma nhan vien: ";
        cin >> ma;
        cout << "Ho ten: ";
        cin.ignore(); // Bỏ qua ký tự xuống dòng
        getline(cin, hoTen);
        cout << "Tuoi: ";
        cin >> tuoi;
        cout << "So dien thoai: ";
        cin >> soDienThoai;
        cout << "Email: ";
        cin >> email;
        cout << "Luong co ban: ";
        cin >> luongCoBan;

        cout << "Loai nhan vien (1: Lap trinh vien, 2: Kiem chinh vien): ";
        cin >> loaiNhanVien;

        if (loaiNhanVien == 1)
        {
            int soGioOvertime;
            cout << "So gio overtime: ";
            cin >> soGioOvertime;
            danhSachNhanVien.push_back(new LapTrinhVien(ma, hoTen, tuoi, soDienThoai, email, luongCoBan, soGioOvertime));
        }
        else if (loaiNhanVien == 2)
        {
            int soLoiPhatHien;
            cout << "So loi phat hien: ";
            cin >> soLoiPhatHien;
            danhSachNhanVien.push_back(new KiemChungVien(ma, hoTen, tuoi, soDienThoai, email, luongCoBan, soLoiPhatHien));
        }
        else
        {
            cout << "Loai nhan vien khong hop le!" << endl;
        }
    }

    int tongLuong = 0;
    for (NhanVien* nv : danhSachNhanVien)
    {
        tongLuong += nv->tinhLuong();
    }
    double luongTrungBinh = (double)tongLuong / danhSachNhanVien.size();

    cout << "Danh sach nhan vien co luong thap hon muc trung binh:\n";
    for (NhanVien* nv : danhSachNhanVien)
    {
        if (nv->tinhLuong() < luongTrungBinh)
        {
            cout << nv->hoTen << " - Luong: " << nv->tinhLuong() << endl;
        }
    }

    return 0;
}
