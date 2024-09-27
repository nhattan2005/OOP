#include <bits/stdc++.h>
using namespace std;

struct phanso{
    int tu, mau;
    void print()
    {
        if(mau == 1) cout << tu;
        else if(tu == 0) cout << 0;
        else cout << tu << "/" << mau;
    }

};

int UCLN(int a, int b)
{
    return __gcd(a, b);
}

phanso rutgon(phanso ps)
{
    int ucln = UCLN(ps.tu, ps.mau);
    return {ps.tu/ucln, ps.mau/ucln};
}

phanso timMax(phanso ps1, phanso ps2)
{
    float phanso1 = (float)ps1.tu / (float)ps1.mau;
    float phanso2 = (float)ps2.tu / (float)ps2.mau;
    if(phanso1 > phanso2) return ps1;
    else return ps2;
}

int main()
{
    int tu, mau;
    cin >> tu >> mau;
    phanso phanso1 = {tu, mau};

    cin >> tu >> mau;
    phanso phanso2 = {tu, mau};
    phanso result = timMax(phanso1, phanso2);
    result.print();
    return 0;
}
