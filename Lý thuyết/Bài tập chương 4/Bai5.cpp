#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp cBook biểu diễn đối tượng sách
class cBook {
private:
    string maSach;
    string tenSach;
    int namXuatBan;
    int tongSoTrang;

public:
    // Thiết lập thông tin sách (Constructor)
    cBook(string ma = "", string ten = "", int nam = 0, int soTrang = 0)
        : maSach(ma), tenSach(ten), namXuatBan(nam), tongSoTrang(soTrang) {}

    // Nhập thông tin cho đối tượng sách từ bàn phím
    void nhap() {
        cout << "Nhap ma sach: ";
        cin >> maSach;
        cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập mã sách
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap tong so trang: ";
        cin >> tongSoTrang;
    }

    // Xuất thông tin đối tượng sách ra màn hình
    void xuat() const {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
        cout << "Tong so trang: " << tongSoTrang << endl;
    }

    // Truy vấn thông tin sách
    int getNamXuatBan() const {
        return namXuatBan;
    }

    // Cập nhật thông tin sách
    void capNhatThongTin(const string &ma, const string &ten, int nam, int soTrang) {
        maSach = ma;
        tenSach = ten;
        namXuatBan = nam;
        tongSoTrang = soTrang;
    }
};

// Lớp cListBook để quản lý danh sách các đối tượng sách
class cListBook {
private:
    vector<cBook> danhSachSach; // Mảng chứa danh sách các sách

public:
    // Nhập danh sách các đối tượng sách
    void nhapDanhSach() {
        int n;
        cout << "Nhap so luong sach: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin cho sach thu " << i + 1 << ":" << endl;
            cBook sach;
            sach.nhap();
            danhSachSach.push_back(sach);
        }
    }

    // Xuất danh sách các đối tượng sách
    void xuatDanhSach() const {
        for (int i = 0; i < danhSachSach.size(); i++) {
            cout << "\nThong tin sach thu " << i + 1 << ":" << endl;
            danhSachSach[i].xuat();
        }
    }

    // Cho biết thông tin sách xuất bản gần đây nhất
    void sachMoiNhat() const {
        if (danhSachSach.empty()) {
            cout << "Khong co sach nao trong danh sach." << endl;
            return;
        }

        int indexMoiNhat = 0;
        for (int i = 1; i < danhSachSach.size(); i++) {
            if (danhSachSach[i].getNamXuatBan() > danhSachSach[indexMoiNhat].getNamXuatBan()) {
                indexMoiNhat = i;
            }
        }

        cout << "\nSach duoc xuat ban gan day nhat la:" << endl;
        danhSachSach[indexMoiNhat].xuat();
    }
};

int main() {
    cListBook thuVien;

    // Nhập danh sách sách
    thuVien.nhapDanhSach();

    // Xuất danh sách sách
    cout << "\nDanh sach cac sach trong thu vien:" << endl;
    thuVien.xuatDanhSach();

    // Hiển thị sách được xuất bản gần đây nhất
    thuVien.sachMoiNhat();

    return 0;
}
