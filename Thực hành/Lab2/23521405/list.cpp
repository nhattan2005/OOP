#include "list.h"
#include <iostream>
using namespace std;

// Constructor khởi tạo list rỗng
List::List() {
    arr = nullptr;    // Con trỏ rỗng
    size = 0;         // Kích thước ban đầu bằng 0
}

// Destructor giải phóng bộ nhớ
List::~List() {
    delete[] arr;     // Giải phóng vùng nhớ đã cấp phát cho mảng
}

// Thêm phần tử vào cuối list
void List::Add(double x) {
    double* newArr = new double[size + 1];  // Tạo mảng mới với kích thước lớn hơn
    for (unsigned int i = 0; i < size; ++i) {
        newArr[i] = arr[i];  // Sao chép phần tử từ mảng cũ sang mảng mới
    }
    newArr[size] = x;  // Thêm phần tử mới vào cuối mảng
    delete[] arr;      // Giải phóng mảng cũ
    arr = newArr;      // Trỏ arr tới mảng mới
    size++;            // Tăng kích thước mảng
}

// Xóa phần tử đầu tiên có giá trị x
void List::RemoveFirst(double x) {
    for (unsigned int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            double* newArr = new double[size - 1];  // Tạo mảng mới với kích thước nhỏ hơn
            for (unsigned int j = 0, k = 0; j < size; ++j) {
                if (j != i) {
                    newArr[k++] = arr[j];  // Sao chép các phần tử trừ phần tử có giá trị x
                }
            }
            delete[] arr;  // Giải phóng mảng cũ
            arr = newArr;  // Trỏ arr tới mảng mới
            size--;        // Giảm kích thước mảng
            break;         // Dừng sau khi xóa phần tử đầu tiên
        }
    }
}

// Xóa tất cả các phần tử có giá trị x
void List::RemoveAll(double x) {
    int count = 0;
    for (unsigned int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            count++;
        }
    }
    if (count > 0) {
        double* newArr = new double[size - count];  // Tạo mảng mới với kích thước nhỏ hơn
        for (unsigned int i = 0, j = 0; i < size; ++i) {
            if (arr[i] != x) {
                newArr[j++] = arr[i];  // Sao chép các phần tử không có giá trị x
            }
        }
        delete[] arr;  // Giải phóng mảng cũ
        arr = newArr;  // Trỏ arr tới mảng mới
        size -= count; // Cập nhật kích thước mảng
    }
}

// Thay đổi phần tử thứ pos bằng giá trị y
void List::Replace(unsigned int pos, double y) {
    if (pos < size) {  // Kiểm tra tính hợp lệ của vị trí
        arr[pos] = y;  // Thay đổi giá trị tại vị trí pos
    }
}

// Xuất mảng theo định dạng [a,b,c,...]
void List::Print() const {
    cout << "[";
    for (unsigned int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

