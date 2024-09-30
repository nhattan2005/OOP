#include <iostream>
#include <string>

using namespace std;

class cHocSinh {
private:
    string ma, hoTen, gioiTinh;
    int namSinh;
    float diemTB;

public:
    // Constructor
    cHocSinh() : ma(""), hoTen(""), gioiTinh(""), namSinh(0), diemTB(0.0f) {}

    // Nhập thông tin học sinh
    void nhapThongTin() {
        cout << "Nhap ma hoc sinh: ";
        getline(cin, ma);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
        cin.ignore();  // Loại bỏ ký tự xuống dòng còn sót lại sau khi nhập điểm
    }

    // Xuất thông tin học sinh
    void xuatThongTin() const {
        cout << "Ma: " << ma << ", Ho ten: " << hoTen << ", Gioi tinh: " << gioiTinh
             << ", Nam sinh: " << namSinh << ", Diem trung binh: " << diemTB << endl;
    }

    // Lấy điểm trung bình
    float layDiemTB() const {
        return diemTB;
    }

    // Lấy tuổi (giả sử năm hiện tại là 2024)
    int layTuoi() const {
        return 2024 - namSinh;
    }
};

int main() {
    cHocSinh hs1, hs2;

    // Nhập thông tin 2 học sinh
    cout << "Nhap thong tin hoc sinh 1:\n";
    hs1.nhapThongTin();

    cout << "Nhap thong tin hoc sinh 2:\n";
    hs2.nhapThongTin();

    // So sánh điểm trung bình
    if (hs1.layDiemTB() > hs2.layDiemTB()) {
        cout << "Hoc sinh 1 co diem trung binh cao hon.\n";
    } else if (hs1.layDiemTB() < hs2.layDiemTB()) {
        cout << "Hoc sinh 2 co diem trung binh cao hon.\n";
    } else {
        cout << "Ca hai hoc sinh co diem trung binh bang nhau.\n";
    }

    // So sánh tuổi
    if (hs1.layTuoi() < hs2.layTuoi()) {
        cout << "Hoc sinh 1 tre hon.\n";
    } else if (hs1.layTuoi() > hs2.layTuoi()) {
        cout << "Hoc sinh 2 tre hon.\n";
    } else {
        cout << "Ca hai hoc sinh bang tuoi.\n";
    }

    return 0;
}
