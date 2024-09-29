#include <bits/stdc++.h>

using namespace std;

// Hàm tính giá trị của sin(x) bằng chuỗi Taylor
double calculateSin(double x) {
    // Khởi tạo giá trị của số hạng đầu tiên là x
    double term = x;
    // Khởi tạo tổng là giá trị của số hạng đầu tiên
    double sum = term;
    // Biến đếm số lượng số hạng, bắt đầu từ n = 1
    int n = 1;

    // Vòng lặp tính các số hạng tiếp theo cho đến khi số hạng nhỏ hơn 0.00001
    while (fabs(term) >= 0.00001) {
        // Cập nhật giá trị của số hạng tiếp theo dựa vào công thức của chuỗi Taylor
        term *= -1 * x * x / (2 * n * (2 * n + 1));
        // Cộng số hạng mới vào tổng
        sum += term;
        // Tăng giá trị n để tính số hạng tiếp theo
        n++;
    }

    // Trả về tổng sau khi tính xong
    return sum;
}

int main() {
    double x;
    // Nhập giá trị của x (đơn vị radian)
    cout << "Enter the value of x (in radians): ";
    cin >> x;

    // Gọi hàm calculateSin để tính sin(x) và in kết quả ra màn hình
    cout << "sin(" << x << ") = " << calculateSin(x) << endl;

    return 0;
}
