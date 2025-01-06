#include <bits/stdc++.h>
using namespace std;

class ConTrung
{
protected:
    int loai;
    vector<int> thongtin;
public:
    virtual vector<int> Nhap() = 0;
    virtual int checkQuyLuat() = 0;
};

class Muoi : public ConTrung
{
public:
    vector<int> Nhap() override
    {
        loai = 1;
        for (int i = 0; i < 4; i++)
        {
            int x;
            cin >> x;
            thongtin.push_back(x);
        }
        return thongtin;
    }
    int checkQuyLuat() override
    {
        if (thongtin[0] < 1 || thongtin[0] > 3) return 0;
        if (thongtin[1] < 4 || thongtin[1] > 10) return 0;
        if (thongtin[2] < 2 || thongtin[2] > 3) return 0;
        if (thongtin[3] < 5 || thongtin[3] > 8) return 0;
        return 1;
    }
};

class Ech : public ConTrung
{
public:
    vector<int> Nhap() override
    {
        loai = 2;
        for (int i = 0; i < 5; i++)
        {
            int x;
            cin >> x;
            thongtin.push_back(x);
        }
        return thongtin;
    }
    int checkQuyLuat() override
    {
        if (thongtin[0] < 1 || thongtin[0] > 3) return 0;
        if (thongtin[1] != 4) return 0;
        if (thongtin[2] < 6 || thongtin[2] > 9) return 0;
        if (thongtin[3] < 1 || thongtin[3] > 4) return 0;
        if (thongtin[4] < 2 || thongtin[4] > 4) return 0;
        return 1;
    }
};

class Buom : public ConTrung
{
public:
    vector<int> Nhap() override
    {
        loai = 3;
        for (int i = 0; i < 4; i++)
        {
            int x;
            cin >> x;
            thongtin.push_back(x);
        }
        return thongtin;
    }
    int checkQuyLuat() override
    {
        if (thongtin[0] < 3 || thongtin[0] > 8) return 0;
        if (thongtin[1] < 15 || thongtin[1] > 16) return 0;
        if (thongtin[2] != 10) return 0;
        if (thongtin[3] < 2 || thongtin[3] > 3) return 0;
        return 1;
    }
};

class HeSinhThai
{
private:
    int n, check[4] = {0};
    vector<ConTrung*> danhsach;
public:
    void NhapHST()
    {
        cout << "Nhap so luong con trung: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap loai: ";
            int type;
            cin >> type;
            check[type]++;
            if (type == 1)
            {
                Muoi* a = new Muoi();
                danhsach.push_back(a);
                a->Nhap();
            }
            else if (type == 2)
            {
                Ech* a = new Ech();
                danhsach.push_back(a);
                a->Nhap();
            }
            else
            {
                Buom* a = new Buom();
                danhsach.push_back(a);
                a->Nhap();
            }
        }
    }
    int checkDaDang()
    {
        for (int i = 1; i <= 3; i++)
            if (check[i] == 0)
                return 0;
        return 1;
    }
    void IrregularInsects()
    {
        for (int i = 0; i < n; i++)
        {
            if (!danhsach[i]->checkQuyLuat())
            {
                cout << "Con trung khong theo quy luat: " << i + 1 << endl;
            }
        }
    }
};

int main()
{
    HeSinhThai hst;
    hst.NhapHST();
    if (hst.checkDaDang())
    {
        cout << "He sinh thai da dang." << endl;
    }
    else
    {
        cout << "He sinh thai khong da dang." << endl;
    }
    hst.IrregularInsects();
    return 0;
}
