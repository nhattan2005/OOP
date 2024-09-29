#include <bits/stdc++.h>
using namespace std;

struct hsinh
{
    /* thong tin hsinh */
    string name;
    float dt, dv, dtb;
};

void nhap(hsinh &hs)
{
    cin >> hs.name >> hs.dt >> hs.dv;
}

void cal_dtb(hsinh &hs)
{
    hs.dtb = (hs.dt + hs.dv) / 2;
}

void xeploai(hsinh &hs)
{
    if (hs.dtb >= 8 && hs.dtb < 9)
    {
        cout << "Xep loai: Gioi" << endl;
    }
    else if (hs.dtb >= 9)
    {
        cout << "Xep loai: Xuat Sac" << endl;
    }
    else if (hs.dtb >= 7 && hs.dtb < 8)
    {
        cout << "Xep loai: Kha" << endl;
    }
    else if (hs.dtb >= 6 && hs.dtb < 7)
    {
        cout << "Xep loai: Trung Binh" << endl;
    }
    else if (hs.dtb >= 5 && hs.dtb < 6)
    {
        cout << "Xep loai: Dat" << endl;
    }
    else if (hs.dtb < 5)
    {
        cout << "Xep loai: Kem" << endl;
    }
}

void xuat(hsinh &hs)
{
    cout << "Ten: " << hs.name << endl;
    cout << "Diem trung binh: " << hs.dtb << endl;
    xeploai(hs);
}

int main()
{
    hsinh hoc_sinh;
    nhap(hoc_sinh);
    cal_dtb(hoc_sinh);
    xuat(hoc_sinh);     
    return 0;
}
