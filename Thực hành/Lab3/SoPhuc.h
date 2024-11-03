#include <bits/stdc++.h>
using namespace std;
class SoPhuc{
private:
    int dThuc, dAo;
public:
    SoPhuc();
    SoPhuc(int thuc, int ao);


    SoPhuc operator+ (const SoPhuc& b) const;
    SoPhuc operator- (const SoPhuc& b) const;
    SoPhuc operator* (const SoPhuc& b) const;
    SoPhuc operator/ (const SoPhuc& b) const;
    bool operator== (const SoPhuc& b) const;
    bool operator!= (const SoPhuc& b) const;
    friend istream& operator >> (istream &is, SoPhuc &b);
    friend ostream& operator << (ostream &os, SoPhuc b);
    operator int() const { return dThuc; }
};

