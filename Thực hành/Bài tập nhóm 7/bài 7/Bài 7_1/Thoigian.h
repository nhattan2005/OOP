#include <iostream>
using namespace std;

class ThoiGian {
protected:
    int gio;
    int phut;
    int giay;
public:
    ThoiGian();
    ThoiGian(int a, int b, int c);
    ~ThoiGian();

    void operator--();

    friend ostream& operator<<(ostream& os, ThoiGian& t);
    friend istream& operator>>(istream& is, ThoiGian& t);
};
