#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
using namespace std;

class List {
private:
    double* arr;           // Con trỏ quản lý mảng
    unsigned int size;      // Kích thước của mảng

public:
    // Constructor khởi tạo list rỗng
    List();

    // Destructor để giải phóng bộ nhớ
    ~List();

    // Thêm phần tử vào cuối list
    void Add(double x);

    // Xóa phần tử đầu tiên có giá trị x
    void RemoveFirst(double x);

    // Xóa tất cả các phần tử có giá trị x
    void RemoveAll(double x);

    // Thay đổi phần tử thứ x bằng giá trị y
    void Replace(unsigned int pos, double y);

    // Xuất mảng theo định dạng [a,b,c,...]
    void Print() const;
};

#endif

