#include <iostream>
#include <vector>
#include <cstdlib> // để sử dụng hàm rand
#include <ctime>   // để sử dụng hàm time
using namespace std;

class MaTran {
private:
    int dong, cot;            // Số dòng và số cột của ma trận
    vector<vector<int>> data; // Mảng hai chiều lưu trữ ma trận

public:
    // Khởi tạo ma trận với số dòng và số cột tùy ý
    MaTran(int m = 0, int n = 0) : dong(m), cot(n) {
        data.resize(dong, vector<int>(cot, 0)); // Khởi tạo ma trận với các phần tử bằng 0
    }

    // Nhập ma trận từ người dùng
    void Nhap() {
        cout << "Nhap ma tran " << dong << " dong " << cot << " cot:" << endl;
        for (int i = 0; i < dong; ++i) {
            for (int j = 0; j < cot; ++j) {
                cout << "Nhap phan tu [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    // Tạo ma trận ngẫu nhiên với các phần tử trong khoảng [0, 100]
    void TaoNgauNhien() {
        srand(time(0)); // Khởi tạo seed cho hàm rand()
        for (int i = 0; i < dong; ++i) {
            for (int j = 0; j < cot; ++j) {
                data[i][j] = rand() % 101; // Phần tử ngẫu nhiên từ 0 đến 100
            }
        }
    }

    // Xuất ma trận
    void Xuat() const {
        for (int i = 0; i < dong; ++i) {
            for (int j = 0; j < cot; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Toán tử cộng hai ma trận
    MaTran operator+(const MaTran& mt) {
        if (dong != mt.dong || cot != mt.cot) {
            cout << "Khong the cong hai ma tran khac kich thuoc!" << endl;
            return MaTran();
        }
        MaTran result(dong, cot);
        for (int i = 0; i < dong; ++i) {
            for (int j = 0; j < cot; ++j) {
                result.data[i][j] = data[i][j] + mt.data[i][j];
            }
        }
        return result;
    }

    // Toán tử nhân hai ma trận
    MaTran operator*(const MaTran& mt) {
        if (cot != mt.dong) {
            cout << "Khong the nhan hai ma tran!" << endl;
            return MaTran();
        }
        MaTran result(dong, mt.cot);
        for (int i = 0; i < dong; ++i) {
            for (int j = 0; j < mt.cot; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cot; ++k) {
                    result.data[i][j] += data[i][k] * mt.data[k][j];
                }
            }
        }
        return result;
    }

    // Toán tử trừ hai ma trận
    MaTran operator-(const MaTran& mt) {
        if (dong != mt.dong || cot != mt.cot) {
            cout << "Khong the tru hai ma tran khac kich thuoc!" << endl;
            return MaTran();
        }
        MaTran result(dong, cot);
        for (int i = 0; i < dong; ++i) {
            for (int j = 0; j < cot; ++j) {
                result.data[i][j] = data[i][j] - mt.data[i][j];
            }
        }
        return result;
    }
};
int main() {
    int m, n;

    // Nhập kích thước cho ma trận thứ nhất
    cout << "Nhap so dong va so cot cho ma tran thu nhat: ";
    cin >> m >> n;
    MaTran mt1(m, n);

    // Nhập kích thước cho ma trận thứ hai
    cout << "Nhap so dong va so cot cho ma tran thu hai: ";
    cin >> m >> n;
    MaTran mt2(m, n);

    // Nhập ma trận
    cout << "Nhap ma tran thu nhat:" << endl;
    mt1.Nhap();
    cout << "Nhap ma tran thu hai:" << endl;
    mt2.Nhap();

    // Cộng hai ma trận
    MaTran tong = mt1 + mt2;
    cout << "Tong hai ma tran:" << endl;
    tong.Xuat();

    // Trừ hai ma trận
    MaTran hieu = mt1 - mt2;
    cout << "Hieu hai ma tran:" << endl;
    hieu.Xuat();

    // Nhập ma trận để nhân
    int p;
    cout << "Nhap so cot cho ma tran thu hai de thuc hien phep nhan: ";
    cin >> p;
    MaTran mt3(n, p); // Số cột của ma trận thứ nhất bằng số dòng của ma trận thứ hai
    cout << "Nhap ma tran thu ba (cho phep nhan):" << endl;
    mt3.Nhap();

    // Nhân hai ma trận
    MaTran tich = mt1 * mt3;
    cout << "Tich hai ma tran:" << endl;
    tich.Xuat();

    return 0;
}
