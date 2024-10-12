#include<bits/stdc++.h>
using namespace std;
struct phan_so{
    int tu,mau;



    void init(){
        cin>>this->tu;
        cin>>this->mau;
        while(this->mau==0){
                cout<<"Nhap lai mau";
                cin>>this->mau;
        }
    }

    void rut_gon(){
        int g=__gcd(this->tu,this->mau);
        this->tu/=g;
        this->mau/=g;
    }

    void xuat(){
        cout<<this->tu<<' '<<this->mau<<'\n';
    }

    bool max_(phan_so b){
        if(this->tu==-1e9) return true;
        bool flag=((this->mau<0) ^ (b.mau<0));
        if(flag) return this->tu * b.mau>this->mau * b.tu;
        else return this->tu*b.mau<this->mau*b.tu;
     }
     bool min_(phan_so b){
        if(this->tu==1e9) return true;
        bool flag=((this->mau<0) ^ (b.mau<0));
        if(flag) return this->tu * b.mau<this->mau * b.tu;
        else return this->tu*b.mau>this->mau*b.tu;
     }


};


phan_so A[1001];
phan_so max_array, min_array;
int main(){
    int size_array;
    cin>>size_array;
    max_array.tu=-1e9;
    min_array.tu=1e9;
    for(int i=1; i<=size_array; i++){
        A[i].init();
        if(max_array.max_(A[i])) max_array=A[i];
        if(min_array.min_(A[i])) min_array=A[i];

    }
    cout<<"Phan so lon nhat: ";
    max_array.xuat();
    cout<<"Phan so be nhat: ";
    min_array.xuat();
}
