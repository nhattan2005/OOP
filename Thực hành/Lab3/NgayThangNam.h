#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);

    int TinhNgay() const;

    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    NgayThangNam operator-(const NgayThangNam& a);
    NgayThangNam operator++();
    NgayThangNam operator++(int);
    NgayThangNam operator--();
    NgayThangNam operator--(int);

    bool operator==(const NgayThangNam& a);
    bool operator!=(const NgayThangNam& a);
    bool operator>=(const NgayThangNam& a);
    bool operator<=(const NgayThangNam& a);
    bool operator>(const NgayThangNam& a);
    bool operator<(const NgayThangNam& a);

    friend ostream& operator<<(ostream& os, const NgayThangNam& dt);
    friend istream& operator>>(istream& is, NgayThangNam& dt);
};

