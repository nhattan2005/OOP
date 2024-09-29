#include <bits/stdc++.h>
using namespace std;

// Struct PhanSo để biểu diễn một phân số
struct PhanSo {
    int tu;   // Tử số
    int mau;  // Mẫu số

    // Hàm in ra phân số dưới dạng "tử/mẫu", xử lý các trường hợp đặc biệt
    void print() const {
        if (mau == 0) { // Kiểm tra mẫu số có bằng 0 không
            cout << "Error: Denominator cannot be zero" << endl;
        } else if (mau == 1) { // Nếu mẫu số bằng 1, chỉ in tử số
            cout << tu << endl;
        } else if (tu == 0) { // Nếu tử số bằng 0, in 0
            cout << 0 << endl;
        } else { // In phân số bình thường dạng "tử/mẫu"
            cout << tu << "/" << mau << endl;
        }
    }

    // Hàm rút gọn phân số bằng cách chia tử và mẫu cho ƯCLN
    void rutGon() {
        if (mau == 0) return; // Nếu mẫu số bằng 0, không làm gì cả
        int ucln = __gcd(tu, mau); // Tính Ước chung lớn nhất (ƯCLN) của tử và mẫu
        tu /= ucln; // Chia tử cho ƯCLN
        mau /= ucln; // Chia mẫu cho ƯCLN
    }

    // Toán tử so sánh ">" giữa hai phân số
    bool operator>(const PhanSo& ps) const {
        // So sánh hai phân số bằng cách nhân chéo để tránh việc tính toán với số thực
        return tu * ps.mau > ps.tu * mau;
    }
};

// Hàm nhập phân số từ người dùng, kiểm tra mẫu số không được bằng 0 và rút gọn phân số
PhanSo nhapPhanSo() {
    PhanSo ps;
    cout << "Enter numerator and denominator: ";
    cin >> ps.tu >> ps.mau;

    // Nếu mẫu số bằng 0, yêu cầu người dùng nhập lại
    while (ps.mau == 0) {
        cout << "Error: Denominator cannot be zero. Please enter again: ";
        cin >> ps.tu >> ps.mau;
    }

    // Rút gọn phân số ngay sau khi nhập
    ps.rutGon();
    return ps;
}

int main() {
    // Nhập phân số thứ nhất
    cout << "Enter the first fraction:\n";
    PhanSo phanSo1 = nhapPhanSo();

    // Nhập phân số thứ hai
    cout << "Enter the second fraction:\n";
    PhanSo phanSo2 = nhapPhanSo();

    // So sánh hai phân số và in ra phân số lớn hơn
    if (phanSo1 > phanSo2) {
        cout << "The largest fraction is: ";
        phanSo1.print(); // In phân số thứ nhất nếu lớn hơn
    } else {
        cout << "The largest fraction is: ";
        phanSo2.print(); // In phân số thứ hai nếu lớn hơn hoặc bằng
    }

    return 0;
}
