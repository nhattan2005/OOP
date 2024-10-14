#include <bits/stdc++.h>
using namespace std;

class SoPhuc
{
    double thuc, ao;
public:
    // Constructor
    SoPhuc(double t=0, double a=0): thuc(t), ao(a) {}

    SoPhuc operator + (const SoPhuc& b) const;
    SoPhuc operator - (const SoPhuc& b) const;
    SoPhuc operator * (const SoPhuc& b) const;
    SoPhuc operator / (const SoPhuc& b) const;
    SoPhuc operator << (const SoPhuc& b) const;
    friend istream& operator >> (istream &is, SoPhuc &b);
    friend ostream& operator << (ostream &os, SoPhuc b);

};

SoPhuc SoPhuc::operator+ (const SoPhuc& b) const
{
    return SoPhuc(thuc+b.thuc, ao+b.ao);
}

SoPhuc SoPhuc::operator- (const SoPhuc& b) const
{
    return SoPhuc(thuc-b.thuc, ao-b.ao);
}

SoPhuc SoPhuc::operator* (const SoPhuc& b) const
{
    return SoPhuc(thuc*b.thuc - ao*b.ao, thuc*b.ao + ao*b.thuc);
}

SoPhuc SoPhuc::operator/ (const SoPhuc& b) const
{
    double denominator = b.thuc * b.thuc + b.ao * b.ao;
    double r = (thuc * b.thuc + ao * b.ao) / denominator;
    double i = (ao * b.thuc - thuc * b.ao) / denominator;
    return SoPhuc(r, i);
}

ostream& operator << (ostream &os, SoPhuc b)
{
    os << b.thuc << "+" << b.ao << "i";
}

istream& operator >> (istream &is, SoPhuc &b)
{
    cout << "Nhap phan thuc: ";
    is >> b.thuc;
    cout << "Nhap phan ao: ";
    is >> b.ao;
}

int main()
{

    SoPhuc A(1,2), B(2,3);
    SoPhuc C=A+3, D;
    cin >> D;
    cout << D << endl;
    cout << C << endl;
    cout << A/B;
    return 0;
}
