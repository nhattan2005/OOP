#include <bits/stdc++.h>
using namespace std;

class NguoiChoi {
protected:
    int ID, Type;
public:
    NguoiChoi(int id, int t);
    virtual int getID() const = 0;
    virtual int getType() const = 0;
    virtual double getSoDu() const { return 0; }
    virtual void setSoDu(double x) {}
    virtual double getHoaHong() const { return 0; }
    virtual void setHoaHong(double x) {}
    virtual int getIDTrader() const { return -1; }
    virtual ~NguoiChoi() {}
};

class NhaCai: public NguoiChoi{
protected:
    double SoDu;
public:
    NhaCai(int id, double du);
    int getID() const override;
    int getType() const override;
    double getSoDu() const override;
    void setSoDu(double x) override;
};

class CoMoi: public NguoiChoi{
protected:
    double HoaHong = 0;
    int IDTrader;
public:
    CoMoi(int id, int idtrd);
    int getID() const override;
    int getType() const override;
    double getHoaHong() const;
    int getIDTrader() const override;
    void setHoaHong(double x);
};

class Trader: public NguoiChoi{
protected:
    double SoDu;
public:
    Trader(int id, double du);
    int getID() const override;
    int getType() const override;
    double getSoDu() const override;
    void setSoDu(double x) override;
};
