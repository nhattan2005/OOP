#include <bits/stdc++.h>
#include "NguoiChoi.h"
using namespace std;

struct LuotChoi
{
    int id, loailenh, lenhdanh;
    double tiendatcuoc;
};

vector<NguoiChoi*> Nhap(int n)
{
    vector<NguoiChoi*> danhsachNguoiChoi;
    for (int i = 0; i < n; i++)
    {
        int id, loai, x;
        cin >> id >> loai >> x;
        if (loai == 1)
            danhsachNguoiChoi.push_back(new NhaCai(id, x));
        else if (loai == 2)
            danhsachNguoiChoi.push_back(new CoMoi(id, x));
        else
            danhsachNguoiChoi.push_back(new Trader(id, x));
    }
    return danhsachNguoiChoi;
}

void XuLy()
{
    int n, m;
    cin >> n >> m;
    vector<NguoiChoi*> danhsachNguoiChoi = Nhap(n);

    vector<LuotChoi> danhsachLuotChoi;
    vector<LuotChoi> LuotChoiValid;
    map<int,int> LenhDanhTruoc;

    while (m--)
    {
        danhsachLuotChoi.clear();
        LuotChoiValid.clear();
        int id, loailenh, lenhdanh;
        double tiendatcuoc;
        while (1)
        {
            cin >> id;
            if (id == -1)
                break;
            cin >> loailenh >> lenhdanh >> tiendatcuoc;
            if (loailenh == 0)
                danhsachLuotChoi.push_back({id, loailenh, lenhdanh, tiendatcuoc});
            else
            {
                if (lenhdanh == 0)
                    danhsachLuotChoi.push_back({id, loailenh, LenhDanhTruoc[id], tiendatcuoc});
                else
                {
                    if (lenhdanh == -1)
                        danhsachLuotChoi.push_back({id, loailenh, 0, tiendatcuoc});
                    else
                        danhsachLuotChoi.push_back({id, loailenh, lenhdanh, tiendatcuoc});
                }
            }
        }

        double TongTienDatCuoc = 0;
        for (const auto& luot : danhsachLuotChoi)
        {
            for (const auto& trd : danhsachNguoiChoi)
            {
                if (trd->getID() == luot.id)
                {
                    if (trd->getSoDu() >= luot.tiendatcuoc)
                    {
                        LuotChoiValid.push_back(luot);
                        if (luot.lenhdanh == 1)
                            TongTienDatCuoc += luot.tiendatcuoc;
                        else
                            TongTienDatCuoc -= luot.tiendatcuoc;
                    }
                }
            }
        }

        int LenhNhaCai = (TongTienDatCuoc < 0) ? 1 : 0;

        double TienNhaCai = 0;
        map<int, double> TienDatCuocTruoc;
        for (const auto& luot : LuotChoiValid)
        {
            for (const auto& trd : danhsachNguoiChoi)
            {
                if (luot.id == trd->getID())
                {
                    double sodu = trd->getSoDu();
                    if (luot.loailenh == 0)
                    {
                        if (luot.lenhdanh == LenhNhaCai)
                        {
                            sodu += (luot.tiendatcuoc * 0.99);
                            TienNhaCai += (luot.tiendatcuoc * 0.01) - luot.tiendatcuoc;
                        }
                        else
                        {
                            sodu -= luot.tiendatcuoc;
                            TienNhaCai += luot.tiendatcuoc;
                        }
                    }
                    else
                    {
                        if (luot.lenhdanh == LenhNhaCai)
                        {
                            sodu += (luot.tiendatcuoc * 0.5 * 0.99);
                            TienNhaCai += (luot.tiendatcuoc * 0.5 * 0.99) - luot.tiendatcuoc * 0.5;
                        }
                        else
                        {
                            sodu -= luot.tiendatcuoc;
                            TienNhaCai += luot.tiendatcuoc;
                        }
                    }
                    trd->setSoDu(sodu);
                    TienDatCuocTruoc[luot.id] = luot.tiendatcuoc;
                }
            }
        }

        for (const auto& luot : LuotChoiValid)
        {
            for (const auto& participant : danhsachNguoiChoi)
            {
                if (participant->getType() == 2)
                {
                    if (luot.id == participant->getIDTrader())
                    {
                        double hoahong = participant->getHoaHong();
                        hoahong += TienDatCuocTruoc[luot.id] * 0.01;
                        TienNhaCai -= TienDatCuocTruoc[luot.id] * 0.01;
                        participant->setHoaHong(hoahong);
                    }
                }
            }
        }

        int checkTienNhaCaiValid = 1;
        for (const auto& participant : danhsachNguoiChoi)
            if (participant->getType() == 1)
            {
                participant->setSoDu(participant->getSoDu() + TienNhaCai);
                if (participant->getSoDu() < 0)
                    checkTienNhaCaiValid = 0;
            }

        /// Cout test
        for (const auto& participant : danhsachNguoiChoi)
        {
            cout << participant->getID() << " ";
            if (participant->getType() == 2)
                cout << participant->getHoaHong() << " ";
            cout << participant->getSoDu() << endl;
        }
        cout << TongTienDatCuoc << endl;
        cout << "------------------" << endl;

        if (checkTienNhaCaiValid != 1)
            break;
    }

    for (const auto& participant : danhsachNguoiChoi)
    {
        cout << participant->getID() << " ";
        if (participant->getType() == 2)
            cout << participant->getHoaHong() << " ";
        cout << participant->getSoDu() << endl;
    }
}

int main()
{
    XuLy();
    return 0;
}
