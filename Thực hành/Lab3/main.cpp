#include <bits/stdc++.h>
#include "SoPhuc.h"
#include "PhanSo.h"
#include "ThoiGian.h"
#include "NgayThangNam.h"
using namespace std;


void testBai1()
{
    PhanSo a(1, 2);
    PhanSo b(3, 4);
    PhanSo c;

    cout << "Nhap mot phan so (tu va mau cach nhau): ";
    cin >> c;
    cout << "Phan so vua nhap: " << c << endl;

    PhanSo sum = a + b;
    cout << "Tong cua " << a << " + " << b << " = " << sum << endl;

    PhanSo diff = a - b;
    cout << "Hieu cua " << a << " - " << b << " = " << diff << endl;

    PhanSo prod = a * b;
    cout << "Tich cua " << a << " * " << b << " = " << prod << endl;

    PhanSo quot = a / b;
    cout << "Thuong cua " << a << " / " << b << " = " << quot << endl;

    cout << "So sanh " << a << " va " << b << ":\n";
    cout << (a == b ? "Bang nhau\n" : "Khong bang nhau\n");
    cout << (a != b ? "Khac nhau\n" : "Khong khac nhau\n");
    cout << (a < b ? "Be hon\n" : "Khong be hon\n");
    cout << (a > b ? "Lon hon\n" : "Khong lon hon\n");
    cout << (a <= b ? "Be hon hoac bang\n" : "Khong be hon hoac bang\n");
    cout << (a >= b ? "Lon hon hoac bang\n" : "Khong lon hon hoac bang\n");
}

void testBai2()
{
    SoPhuc A(1,2), B(2,3);
    SoPhuc D;
    cin >> D;
    cout << D << endl;
    cout << A*B << endl;
    cout << (A==B);
}

void testThoiGian() {
    ThoiGian tg1(1, 30, 15);
    ThoiGian tg2(2, 45, 30);
    ThoiGian tg3;

    cout << "Initial values:" << endl;
    cout << "tg1 = " << tg1 << endl;
    cout << "tg2 = " << tg2 << endl;
    cout << "tg3 = " << tg3 << endl;

    cout << "\nTinhGiay:" << endl;
    cout << "tg1 in seconds: " << tg1.TinhGiay() << endl;
    cout << "tg2 in seconds: " << tg2.TinhGiay() << endl;

    cout << "\nTinhLaiGio:" << endl;
    tg3.TinhLaiGio(3661);
    cout << "tg3 after TinhLaiGio(3661): " << tg3 << endl;

    cout << "\nTesting operator+ (int Giay):" << endl;
    ThoiGian tg4 = tg1 + 120;
    cout << "tg1 + 120 seconds = " << tg4 << endl;

    cout << "\nTesting operator- (int Giay):" << endl;
    ThoiGian tg5 = tg2 - 90;
    cout << "tg2 - 90 seconds = " << tg5 << endl;

    cout << "\nTesting operator+ (ThoiGian):" << endl;
    ThoiGian tg6 = tg1 + tg2;
    cout << "tg1 + tg2 = " << tg6 << endl;

    cout << "\nTesting operator- (ThoiGian):" << endl;
    ThoiGian tg7 = tg2 - tg1;
    cout << "tg2 - tg1 = " << tg7 << endl;

    cout << "\nTesting increment and decrement operators:" << endl;
    cout << "Original tg1: " << tg1 << endl;
    cout << "++tg1 = " << ++tg1 << endl;
    cout << "tg1++ = " << tg1++ << " (after tg1++: " << tg1 << ")" << endl;
    cout << "--tg1 = " << --tg1 << endl;
    cout << "tg1-- = " << tg1-- << " (after tg1--: " << tg1 << ")" << endl;

    cout << "\nTesting comparison operators:" << endl;
    cout << "tg1 == tg2: " << (tg1 == tg2 ? "True" : "False") << endl;
    cout << "tg1 != tg2: " << (tg1 != tg2 ? "True" : "False") << endl;
    cout << "tg1 >= tg2: " << (tg1 >= tg2 ? "True" : "False") << endl;
    cout << "tg1 <= tg2: " << (tg1 <= tg2 ? "True" : "False") << endl;
    cout << "tg1 > tg2: " << (tg1 > tg2 ? "True" : "False") << endl;
    cout << "tg1 < tg2: " << (tg1 < tg2 ? "True" : "False") << endl;

    cout << "\nTesting input/output operators:" << endl;
    cout << "Enter time for tg3 (format: hours minutes seconds): ";
    cin >> tg3;
    cout << "You entered tg3 = " << tg3 << endl;
}

void testNgayThangNam() {
    NgayThangNam date1(2023, 11, 1);
    NgayThangNam date2(2024, 1, 1);

    cout << "Date 1: " << date1 << endl;
    cout << "Date 2: " << date2 << endl;

    NgayThangNam date3 = date1 + 30;
    cout << "Date 1 + 30 days: " << date3 << endl;

    NgayThangNam date4 = date2 - 10;
    cout << "Date 2 - 10 days: " << date4 << endl;

    NgayThangNam date5 = date2 - date1;
    cout << "Date 2 - Date 1: " << date5 << endl;

    cout << "Date 1 after increment: " << ++date1 << endl; // Prefix increment
    cout << "Date 1 after postfix increment: " << date1++ << " (now: " << date1 << ")" << endl; // Postfix increment
    cout << "Date 1 after decrement: " << --date1 << endl; // Prefix decrement
    cout << "Date 1 after postfix decrement: " << date1-- << " (now: " << date1 << ")" << endl; // Postfix decrement

    cout << "Date 1 == Date 2: " << (date1 == date2 ? "True" : "False") << endl;
    cout << "Date 1 != Date 2: " << (date1 != date2 ? "True" : "False") << endl;
    cout << "Date 1 < Date 2: " << (date1 < date2 ? "True" : "False") << endl;
}

int main()
{
    testNgayThangNam();
    return 0;
}
