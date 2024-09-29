#include <bits/stdc++.h>
using namespace std;

// Lớp PhanSo biểu diễn một phân số và các phép toán với phân số
class PhanSo {
private:
    int tu;   // Tử số
    int mau;  // Mẫu số

    // Hàm rút gọn phân số bằng cách chia tử và mẫu cho ƯCLN
    void rutGon() {
        if (mau == 0) return; // Nếu mẫu bằng 0 thì không rút gọn
        int ucln = __gcd(tu, mau); // Tìm ước chung lớn nhất (ƯCLN) của tử và mẫu
        tu /= ucln; // Chia tử số cho ƯCLN
        mau /= ucln; // Chia mẫu số cho ƯCLN
    }

public:
    // Constructor khởi tạo phân số với giá trị tử và mẫu, mặc định là 0/1
    PhanSo(int t = 0, int m = 1) : tu(t), mau(m) {
        // Kiểm tra nếu mẫu số bằng 0 thì ném ra lỗi ngoại lệ
        if (mau == 0) {
            throw invalid_argument("The denominator cannot be 0");
        }
        // Rút gọn phân số sau khi khởi tạo
        rutGon();
    }

    // Hàm in phân số dưới dạng "tử/mẫu", xử lý các trường hợp đặc biệt
    void print() const {
        if (mau == 1) { // Nếu mẫu số bằng 1 thì chỉ in tử số
            cout << tu;
        } else if (tu == 0) { // Nếu tử số bằng 0 thì in 0
            cout << 0;
        } else { // In phân số dạng "tử/mẫu"
            cout << tu << "/" << mau;
        }
    }

    // Toán tử cộng hai phân số: (tu1/mau1 + tu2/mau2) = (tu1 * mau2 + tu2 * mau1) / (mau1 * mau2)
    PhanSo operator+(const PhanSo& ps) const {
        return PhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau);
    }

    // Toán tử trừ hai phân số: (tu1/mau1 - tu2/mau2) = (tu1 * mau2 - tu2 * mau1) / (mau1 * mau2)
    PhanSo operator-(const PhanSo& ps) const {
        return PhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau);
    }

    // Toán tử nhân hai phân số: (tu1/mau1 * tu2/mau2) = (tu1 * tu2) / (mau1 * mau2)
    PhanSo operator*(const PhanSo& ps) const {
        return PhanSo(tu * ps.tu, mau * ps.mau);
    }

    // Toán tử chia hai phân số: (tu1/mau1 / tu2/mau2) = (tu1 * mau2) / (mau1 * tu2)
    // Nếu phân số bị chia có tử số bằng 0, ném ra ngoại lệ vì không thể chia cho 0
    PhanSo operator/(const PhanSo& ps) const {
        if (ps.tu == 0) {
            throw invalid_argument("Error: Cannot divide by a fraction with a numerator of 0");
        }
        return PhanSo(tu * ps.mau, mau * ps.tu);
    }
};

// Hàm nhập một phân số từ người dùng
PhanSo nhapPhanSo() {
    int tu, mau;
    cout << "Enter numerator and denominator: ";
    cin >> tu >> mau; // Nhập tử số và mẫu số
    return PhanSo(tu, mau); // Khởi tạo và trả về đối tượng PhanSo
}

int main() {
    // Nhập phân số thứ nhất từ người dùng
    cout << "Enter the first fraction:\n";
    PhanSo phanSo1 = nhapPhanSo();

    // Nhập phân số thứ hai từ người dùng
    cout << "Enter the second fraction:\n";
    PhanSo phanSo2 = nhapPhanSo();

    // Tính tổng hai phân số và in kết quả
    cout << "Sum: ";
    (phanSo1 + phanSo2).print();
    cout << endl;

    // Tính hiệu hai phân số và in kết quả
    cout << "Difference: ";
    (phanSo1 - phanSo2).print();
    cout << endl;

    // Tính tích hai phân số và in kết quả
    cout << "Product: ";
    (phanSo1 * phanSo2).print();
    cout << endl;

    // Tính thương hai phân số và in kết quả, xử lý ngoại lệ nếu xảy ra
    cout << "Quotient: ";
    try {
        (phanSo1 / phanSo2).print(); // Nếu chia hợp lệ, in kết quả
    } catch (const invalid_argument& e) {
        // Nếu có lỗi, in ra thông báo lỗi
        cout << e.what() << endl;
    }
    cout << endl;

    return 0;
}
