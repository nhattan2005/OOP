#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;

struct HocSinh {
    string hoTen;
    float diemToan;
    float diemVan;
    float diemAnh;
    float diemTrungBinh;
    string xepLoai;

    // Hàm tính điểm trung bình
    void tinhDiemTrungBinh() {
        diemTrungBinh = (2 * diemToan + diemVan + diemAnh) / 4.0;
    }

    // Hàm phân loại học sinh dựa trên điểm trung bình
    void phanLoai() {
        if (diemTrungBinh >= 9) {
            xepLoai = "Xuat sac";
        } else if (diemTrungBinh >= 8) {
            xepLoai = "Gioi";
        } else if (diemTrungBinh >= 6.5) {
            xepLoai = "Kha";
        } else if (diemTrungBinh >= 5) {
            xepLoai = "Trung binh";
        } else {
            xepLoai = "Yeu";
        }
    }
};

// Hàm kiểm tra tên hợp lệ (không chứa ký tự số)
bool kiemTraTen(const string &ten) {
    for (char c : ten) {
        if (isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Hàm nhập điểm (trong khoảng từ 0 đến 10)
float nhapDiem(const string &monHoc) {
    float diem;
    do {
        cout << "Nhap diem " << monHoc << " (0 - 10): ";
        cin >> diem;
        if (diem < 0 || diem > 10) {
            cout << "Diem khong hop le, vui long nhap lai.\n";
        }
    } while (diem < 0 || diem > 10);
    return diem;
}

// Hàm chuyển đổi chuỗi sang chữ thường
string toLower(const string &s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Hàm tìm kiếm theo tên
void timKiemTheoTen(const vector<HocSinh> &danhSach, const string &ten) {
    string tenTimKiem = toLower(ten);
    bool timThay = false;
    for (const auto &hs : danhSach) {
        if (toLower(hs.hoTen).find(tenTimKiem) != string::npos) {
            cout << "Ho ten: " << hs.hoTen << ", Diem trung binh: " << hs.diemTrungBinh << ", Xep loai: " << hs.xepLoai << endl;
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay hoc sinh voi ten: " << ten << endl;
    }
}

// Hàm xuất danh sách học sinh có điểm toán thấp nhất
void xuatHocSinhDiemToanThapNhat(const vector<HocSinh> &danhSach) {
    float minDiemToan = 10;
    for (const auto &hs : danhSach) {
        if (hs.diemToan < minDiemToan) {
            minDiemToan = hs.diemToan;
        }
    }
    cout << "Hoc sinh co diem toan thap nhat:\n";
    for (const auto &hs : danhSach) {
        if (hs.diemToan == minDiemToan) {
            cout << "Ho ten: " << hs.hoTen << ", Diem toan: " << hs.diemToan << endl;
        }
    }
}

int main() {
    vector<HocSinh> danhSachHocSinh;
    int soLuongHocSinh;

    cout << "Nhap so luong hoc sinh: ";
    cin >> soLuongHocSinh;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa tất cả ký tự thừa trong bộ đệm

    // Nhập thông tin học sinh
    for (int i = 0; i < soLuongHocSinh; ++i) {
        HocSinh hs;
        cout << "\nNhap thong tin hoc sinh thu " << i + 1 << ":\n";

        // Nhập họ tên và kiểm tra tính hợp lệ
        do {
            cout << "Nhap ho ten: ";
            getline(cin, hs.hoTen);
            if (!kiemTraTen(hs.hoTen)) {
                cout << "Ho ten khong hop le, vui long nhap lai.\n";
            }
        } while (!kiemTraTen(hs.hoTen));

        // Nhập điểm Toán, Văn, Anh
        hs.diemToan = nhapDiem("Toan");
        hs.diemVan = nhapDiem("Van");
        hs.diemAnh = nhapDiem("Anh");

        // Tính điểm trung bình và phân loại
        hs.tinhDiemTrungBinh();
        hs.phanLoai();

        danhSachHocSinh.push_back(hs);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa ký tự thừa sau mỗi lần nhập điểm
    }

    // Xuất thông tin học sinh
    cout << "\nDanh sach hoc sinh:\n";
    for (const auto &hs : danhSachHocSinh) {
        cout << "Ho ten: " << hs.hoTen
             << ", Diem Toan: " << hs.diemToan
             << ", Diem Van: " << hs.diemVan
             << ", Diem Anh: " << hs.diemAnh
             << ", Diem trung binh: " << fixed << setprecision(2) << hs.diemTrungBinh
             << ", Xep loai: " << hs.xepLoai << endl;
    }

    // Tìm học sinh có điểm trung bình cao nhất
    HocSinh hsDiemCaoNhat = *max_element(danhSachHocSinh.begin(), danhSachHocSinh.end(), [](const HocSinh &a, const HocSinh &b) {
        return a.diemTrungBinh < b.diemTrungBinh;
    });
    cout << "\nHoc sinh co diem trung binh cao nhat: " << hsDiemCaoNhat.hoTen << ", Diem trung binh: " << hsDiemCaoNhat.diemTrungBinh << endl;

    // Tìm kiếm học sinh theo tên
    string tenTimKiem;
    cout << "\nNhap ten hoc sinh can tim: ";
    getline(cin, tenTimKiem);
    timKiemTheoTen(danhSachHocSinh, tenTimKiem);

    // Xuất danh sách học sinh có điểm toán thấp nhất
    xuatHocSinhDiemToanThapNhat(danhSachHocSinh);

    return 0;
}
