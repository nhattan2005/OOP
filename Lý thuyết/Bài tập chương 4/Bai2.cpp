#include <iostream>
#include <vector>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <algorithm> // for sort

using namespace std;

// Lớp Phân số
class PhanSo {
public:
    int tu, mau;

    // Hàm nhập phân số
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
        } while (mau == 0);
    }

    // Hàm xuất phân số
    void xuat() const {
        cout << tu << "/" << mau << " ";
    }

    // Tính giá trị thực của phân số
    double giaTri() const {
        return (double)tu / mau;
    }

    // Rút gọn phân số
    void rutGon() {
        int ucln = gcd(abs(tu), abs(mau));
        tu /= ucln;
        mau /= ucln;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Kiểm tra tử số có phải là số nguyên tố
    bool tuNguyenTo() const {
        return isPrime(tu);
    }

private:
    // Hàm tính ước chung lớn nhất (gcd)
    int gcd(int a, int b) const {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    // Hàm kiểm tra số nguyên tố
    bool isPrime(int n) const {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};

// Lớp arrPhanSo cho mảng các phân số
class arrPhanSo {
private:
    vector<PhanSo> arr; // Mảng lưu các phân số

public:
    // 1. Nhập các phân số
    void nhapMangPhanSo(int n) {
        PhanSo ps;
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan so thu " << i + 1 << ": " << endl;
            ps.nhap();
            ps.rutGon();
            arr.push_back(ps);
        }
    }

    // 2. Xuất danh sách các phân số
    void xuatMangPhanSo() const {
        for (const auto &ps : arr) {
            ps.xuat();
        }
        cout << endl;
    }

    // 3. Tạo n phân số ngẫu nhiên
    void taoPhanSoNgauNhien(int n) {
        srand(time(0)); // Khởi tạo seed cho hàm rand()
        arr.clear();     // Xóa mảng hiện tại
        for (int i = 0; i < n; i++) {
            PhanSo ps;
            ps.tu = rand() % 21 - 10;   // Tử số ngẫu nhiên từ -10 đến 10
            do {
                ps.mau = rand() % 21 - 10; // Mẫu số ngẫu nhiên từ -10 đến 10, không được bằng 0
            } while (ps.mau == 0);
            ps.rutGon();
            arr.push_back(ps);
        }
        cout << "Da tao danh sach phan so ngau nhien." << endl;
    }

    // 4. Tìm phân số có giá trị lớn nhất
    PhanSo timMax() const {
        PhanSo maxPhanSo = arr[0];
        for (const auto &ps : arr) {
            if (ps.giaTri() > maxPhanSo.giaTri()) {
                maxPhanSo = ps;
            }
        }
        return maxPhanSo;
    }

    // 5. Đếm phân số có tử là số nguyên tố
    int demTuNguyenTo() const {
        int count = 0;
        for (const auto &ps : arr) {
            if (ps.tuNguyenTo()) {
                count++;
            }
        }
        return count;
    }

    // 6. Sắp xếp các phân số trong mảng theo thứ tự tăng dần
    void sapXepTangDan() {
        sort(arr.begin(), arr.end(), [](const PhanSo &a, const PhanSo &b) {
            return a.giaTri() < b.giaTri();
        });
        cout << "Mang da duoc sap xep tang dan." << endl;
    }
};

int main() {
    arrPhanSo arr;
    int n;

    // 1. Nhập mảng phân số
    cout << "Nhap so luong phan so: ";
    cin >> n;
    arr.nhapMangPhanSo(n);

    // 2. Xuất mảng phân số
    cout << "Danh sach phan so vua nhap: ";
    arr.xuatMangPhanSo();

    // 3. Tạo phân số ngẫu nhiên
    arr.taoPhanSoNgauNhien(n);
    arr.xuatMangPhanSo();

    // 4. Tìm phân số có giá trị lớn nhất
    PhanSo maxPhanSo = arr.timMax();
    cout << "Phan so co gia tri lon nhat: ";
    maxPhanSo.xuat();
    cout << endl;

    // 5. Đếm phân số có tử là số nguyên tố
    cout << "So phan so co tu la so nguyen to: " << arr.demTuNguyenTo() << endl;

    // 6. Sắp xếp phân số theo thứ tự tăng dần
    arr.sapXepTangDan();
    arr.xuatMangPhanSo();

    return 0;
}
