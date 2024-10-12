#include <iostream>
#include "diem.h"
#include "tamgiac.h"
#include "dagiac.h"
#include "thisinh.h"
#include "tamgiac2.h"
#include "polygon.h"
#include "list.h"
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
    daGiac.Nhap();
    daGiac.Xuat();

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

void testBai4()
{
    ThiSinh ts;

    cout << "Nhap thong tin thi sinh:" << endl;
    ts.Nhap();

    cout << "\nThong tin thi sinh vua nhap:" << endl;
    ts.Xuat();
}

void testBai5(){
    float hoanh, tung;
    cout << "Nhap hoanh do va tung do cua diem: ";
    cin >> hoanh >> tung;

    // Khởi tạo đối tượng điểm
    Diem d(hoanh, tung);

    // Nhập số lượng chỉ thị
    int n;
    cout << "Nhap so luong chi thi: ";
    cin >> n;

    // Xử lý các chỉ thị
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap chi thi x: ";
        cin >> x;

        if (x == 1) {
            d.NhanDoi();  // Nhân đôi hoành độ và tung độ
        } else if (x == 2) {
            d.GanVeGoc();  // Gán điểm về gốc tọa độ
        } else if (x == 3) {
            int k;
            float dTinhTien;
            cout << "Nhap huong tinh tien k (0 la x, khac 0 la y): ";
            cin >> k;
            cout << "Nhap do tinh tien d: ";
            cin >> dTinhTien;
            d.TinhTien2(k, dTinhTien);  // Tịnh tiến điểm
        }
    }

    // Xuất kết quả cuối cùng
    cout << "Toa do diem cuoi cung la: ";
    d.Xuat();
}

void testBai6(){
    TamGiac2 tg;

    // Nhập tọa độ tam giác
    tg.Nhap();

    // Nhập góc tịnh tiến và độ dài tịnh tiến
    float goc, doDai;
    cout << "Nhap huong tinh tien (goc) va do dai tinh tien: ";
    cin >> goc >> doDai;

    // Thực hiện tịnh tiến
    tg.TinhTien(goc, doDai);

    // Xuất tọa độ tam giác sau khi tịnh tiến
    tg.Xuat();
}

void testBai7(){
    // Khởi tạo đối tượng Polygon
    Polygon polygon;

    // Nhập tọa độ của các đỉnh đa giác
    polygon.Nhap();

    // Xuất diện tích của đa giác
    polygon.XuatDienTich();
}

void testBai8()
{
    List myList;
    int n;

    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        else if (n == 0) {
            double x;
            cin >> x;
            myList.Add(x);  // Thêm phần tử vào list
        }
        else if (n == 1) {
            double x;
            cin >> x;
            myList.RemoveFirst(x);  // Xóa phần tử đầu tiên có giá trị x
        }
        else if (n == 2) {
            double x;
            cin >> x;
            myList.RemoveAll(x);  // Xóa tất cả các phần tử có giá trị x
        }
        else if (n == 3) {
            unsigned int x;
            double y;
            cin >> x >> y;
            myList.Replace(x, y);  // Thay đổi phần tử thứ x bằng y
        }
    }

    myList.Print();  // In ra list hiện tại
}

int main() {
    testBai8();
    return 0;
}
