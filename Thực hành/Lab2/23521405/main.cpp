#include <iostream>
#include "diem.h"
#include "tamgiac.h"
#include "dagiac.h"
using namespace std;

void testBai1()
{
    Diem A(3, 4);  // Khởi tạo điểm A với hoành độ 3 và tung độ 4
    A.Xuat();

    A.TinhTien(2, -1);  // Tịnh tiến điểm A theo vector (2, -1)
    A.Xuat();

    Diem B(A);  // Khởi tạo điểm B sao chép từ điểm A
    B.Xuat();

    cout << "Tung do cua A: " << A.GetTungDo() << endl;
    cout << "Hoanh do cua A: " << A.GetHoanhDo() << endl;
    cout << "Thiet lap hoanh do A: " ;
    int x,y;
    cin >> x;
    A.SetHoanhDo(x);
    A.Xuat();

    cout << "Tinh tien:" << endl;
    cout << "dx = ";
    cin >> x;
    cout << "dy = ";
    cin >> y;
    A.TinhTien(x,y);
    A.Xuat();
}

void testBai2()
{
    TamGiac tg;
    tg.Nhap();  // Nhập tọa độ các đỉnh tam giác
    tg.Xuat();  // Xuất tọa độ tam giác

    tg.TinhTien(2, 3);  // Tịnh tiến tam giác theo vector (2, 3)
    cout << "Sau khi tinh tien:" << endl;
    tg.Xuat();

    tg.PhongTo(2);  // Phóng to tam giác gấp đôi
    cout << "Sau khi phong to:" << endl;
    tg.Xuat();

    tg.ThuNho(2);  // Thu nhỏ tam giác về kích thước ban đầu
    cout << "Sau khi thu nho:" << endl;
    tg.Xuat();

    tg.Quay(90);  // Quay tam giác 90 độ quanh gốc tọa độ
    cout << "Sau khi quay 90 do:" << endl;
    tg.Xuat();
}

void testBai3()
{
    int soDinh;
    cout << "Nhap so dinh cua da giac: ";
    cin >> soDinh;

    DaGiac daGiac(soDinh);
    daGiac.Nhap();  // Nhập tọa độ các đỉnh
    daGiac.Xuat();  // Xuất tọa độ các đỉnh

    daGiac.TinhTien(2, 3);  // Tịnh tiến đa giác theo vector (2, 3)
    cout << "Sau khi tinh tien:" << endl;
    daGiac.Xuat();

    daGiac.PhongTo(2);  // Phóng to đa giác gấp đôi
    cout << "Sau khi phong to:" << endl;
    daGiac.Xuat();

    daGiac.ThuNho(2);  // Thu nhỏ đa giác về kích thước ban đầu
    cout << "Sau khi thu nho:" << endl;
    daGiac.Xuat();

    daGiac.Quay(90);  // Quay đa giác 90 độ quanh gốc tọa độ
    cout << "Sau khi quay 90 do:" << endl;
    daGiac.Xuat();
}

int main() {
    testBai3();
    return 0;
}
