#include <bits/stdc++.h>
#include "NhanVien.h"
#include "Phong.h"
#include "GiaSuc.h"
using namespace std;

void testBai1()
{
    std::string ht, ms;
    double luong, thuong, overtime;

    cout << "Nhap ho ten quan ly: ";
    getline(cin, ht);
    cout << "Ma so: ";
    getline(cin, ms);
    cout << "Luong co ban: ";
    cin >> luong;
    cout << "Ty le thuong: ";
    cin >> thuong;
    QuanLy ql(ht, ms, luong, thuong);

    cin.ignore();

    cout << "Nhap ho ten ky su: ";
    getline(cin, ht);
    cout << "Ma so: ";
    getline(cin, ms);
    cout << "Luong co ban: ";
    cin >> luong;
    cout << "So gio lam them: ";
    cin >> overtime;
    KySu ks(ht, ms, luong, overtime);

    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "Thong tin quan ly: " << endl;
    ql.Xuat();

    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "Thong tin Ky su: " << endl;
    ks.Xuat();
}

void testBai2()
{
    Deluxe a(10, 10000, 5000);
    Deluxe b(8, 8000, 4000);
    Premium c(15, 12000);
    Premium d(12, 9000);
    Business e(20);

    vector<Phong *> danhSachPhong = {&a, &b, &c, &d, &e};

    double doanhThuDeluxe = 0, doanhThuPremium = 0, doanhThuBusiness = 0;

    for (const auto &phong : danhSachPhong) {
        if (phong->getLoaiPhong() == "Deluxe")
            doanhThuDeluxe += phong->TinhDoanhThu();
        else if (phong->getLoaiPhong() == "Premium")
            doanhThuPremium += phong->TinhDoanhThu();
        else if (phong->getLoaiPhong() == "Business")
            doanhThuBusiness += phong->TinhDoanhThu();
    }

    double doanhThuMax = max({doanhThuDeluxe, doanhThuPremium, doanhThuBusiness});
    string loaiPhongMax;

    if (doanhThuMax == doanhThuDeluxe)
        loaiPhongMax = "Deluxe";
    else if (doanhThuMax == doanhThuPremium)
        loaiPhongMax = "Premium";
    else
        loaiPhongMax = "Business";

    cout << "Doanh thu theo loai phong:" << endl;
    cout << "Deluxe: " << doanhThuDeluxe << endl;
    cout << "Premium: " << doanhThuPremium << endl;
    cout << "Business: " << doanhThuBusiness << endl;
    cout << "Loai phong co doanh thu cao nhat: " << loaiPhongMax << endl;
}

void testBai3()
{
    srand(static_cast<unsigned>(time(0)));

    Bo bo(5);
    Cuu cuu(7);
    De de(10);

    vector<GiaSuc *> danhSachGiaSuc = {&bo, &cuu, &de};

    cout << "Tieng keu khi gia suc doi:" << endl;
    for (const auto &giaSuc : danhSachGiaSuc) {
        cout << giaSuc->getTenLoai() << ": " << giaSuc->TiengKeu() << endl;
    }

    int tongSoLuong = 0, tongSoSua = 0;

    cout << "\nThong ke sau mot lua sinh va cho sua:" << endl;
    for (auto &giaSuc : danhSachGiaSuc) {
        int soConSinh = giaSuc->SinhCon();
        int soLuongSua = giaSuc->ChoSua();
        giaSuc->tangSoLuong(soConSinh);

        tongSoLuong += giaSuc->getSoLuong();
        tongSoSua += soLuongSua;

        cout << giaSuc->getTenLoai() << " - So luong: " << giaSuc->getSoLuong()
             << ", So con sinh: " << soConSinh
             << ", So sua: " << soLuongSua << " lit" << endl;
    }

    cout << "\nTong so gia suc trong nong trai: " << tongSoLuong << endl;
    cout << "Tong so sua thu duoc: " << tongSoSua << " lit" << endl;
}

int main() {
    testBai3();
    return 0;
}
