#include "Database.h"

Database::~Database() {
    for (Sach* s : data)
        delete s;
}

void Database::Nhap() {
    int n;
    std::cout << "Nhap so luong sach: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap loai sach (0: Sach Tham Khao, 1: Sach Giao Khoa): ";
        int t;
        std::cin >> t;

        if (t == 0) {
            SachThamKhao* stk = new SachThamKhao();
            stk->Nhap();
            stk->loai = 0;
            data.push_back(stk);
        } else {
            SachGiaoKhoa* sgk = new SachGiaoKhoa();
            sgk->Nhap();
            sgk->loai = 1;
            data.push_back(sgk);
        }
    }
}

void Database::Xuat() const {
    for (const Sach* s : data)
        s->Xuat();
}

void Database::TinhTong() const {
    double sumSGK = 0, sumSTK = 0;

    for (const Sach* s : data) {
        const SachGiaoKhoa* sgk = dynamic_cast<const SachGiaoKhoa*>(s);
        const SachThamKhao* stk = dynamic_cast<const SachThamKhao*>(s);

        if (sgk)
            sumSGK += sgk->thanhtien;
        else if (stk)
            sumSTK += stk->thanhtien;
    }

    std::cout << "Tong tien SGK: " << sumSGK << std::endl;
    std::cout << "Tong tien STK: " << sumSTK << std::endl;
}

void Database::TienItNhat() const {
    if (data.empty()) {
        std::cout << "Database trong" << std::endl;
        return;
    }

    const Sach* minSach = *std::min_element(data.begin(), data.end(), 
                                            [](const Sach* a, const Sach* b) { return *a < *b; });
    std::cout << "Sach co thanh tien thap nhat: " << std::endl;
    minSach->Xuat();
}

void Database::TimThongTin() const {
    std::string tenNXB;
    std::cout << "Nhap ten Nha Xuat Ban: ";
    std::cin.ignore();
    std::getline(std::cin, tenNXB);

    for (const Sach* s : data) {
        if (s->NhaXuatBan == tenNXB and s->loai == 1)
            s->Xuat();
    }
}
