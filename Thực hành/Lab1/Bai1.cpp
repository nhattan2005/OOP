#include <bits/stdc++.h>
using namespace std;

// Định nghĩa struct phanso để biểu diễn một phân số
struct phanso {
    int tu, mau; // tử số và mẫu số

    // Constructor để khởi tạo phân số với giá trị mặc định là 0/1
    phanso(int tu = 0, int mau = 1) {
        // Kiểm tra nếu mẫu số bằng 0, ném lỗi ngoại lệ vì phân số không hợp lệ
        if (mau == 0) {
            throw invalid_argument("Mau so khong duoc bang 0");
        }
        // Nếu mẫu số âm, chuyển dấu âm cho tử số để giữ mẫu số luôn dương
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
        this->tu = tu;
        this->mau = mau;
    }

    // Hàm in phân số dưới dạng "tu/mau" hoặc chỉ "tu" nếu mẫu số là 1
    void print() const {
        if (mau == 1) cout << tu; // Nếu mẫu số là 1 thì chỉ in tử số
        else if (tu == 0) cout << 0; // Nếu tử số bằng 0 thì in 0
        else cout << tu << "/" << mau; // In phân số dưới dạng "tu/mau"
    }

    // Hàm rút gọn phân số bằng cách chia cả tử số và mẫu số cho ƯCLN
    phanso rutgon() const {
        // Tìm ước chung lớn nhất (ƯCLN) của tử số và mẫu số
        int ucln = __gcd(abs(tu), abs(mau));
        // Trả về phân số đã rút gọn bằng cách chia tử và mẫu cho ƯCLN
        return phanso(tu / ucln, mau / ucln);
    }
};

int main() {
    try {
        int tu, mau;
        // Nhập tử số
        cout << "Nhap tu so: ";
        cin >> tu;
        // Nhập mẫu số
        cout << "Nhap mau so: ";
        cin >> mau;

        // Tạo phân số từ tử và mẫu vừa nhập
        phanso ps(tu, mau);
        // Rút gọn phân số
        ps = ps.rutgon();
        // In ra phân số sau khi rút gọn
        cout << "Phan so rut gon: ";
        ps.print();
        cout << endl;

    } catch (const invalid_argument &e) {
        // Bắt ngoại lệ nếu có lỗi mẫu số bằng 0 và in ra thông báo lỗi
        cerr << "Loi: " << e.what() << endl;
    }

    return 0;
}
