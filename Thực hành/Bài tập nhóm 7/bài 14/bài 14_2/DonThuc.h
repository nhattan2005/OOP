#include <bits/stdc++.h>
using namespace std;

class DonThuc {
    protected:
        double HeSo;
        int SoMu;
    public:
        DonThuc(double a, int b);
        DonThuc();
        ~DonThuc();
        double Tinh(double x);
        void Xuat();
        DonThuc operator+(const DonThuc b);
};