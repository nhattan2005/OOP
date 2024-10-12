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
     bool operator <(phan_so b){
            return this->min_(b)==false;
     }

};


phan_so A[1001];
phan_so max_array, min_array;
int k;
int main(){
    int size_array;
    cin>>size_array >> k;
    for(int i=1; i<=size_array; i++){
        A[i].init();
    }
    sort(A+1,A+size_array+1);
      for(int i=1; i<=size_array; i++){
        A[i].xuat();
    }
    if(k>size_array) return 0;
    cout<<"Phan so nho thu k: ";
    A[k].xuat();
    cout<<"Phan so lon thu k: ";
    A[size_array-k+1].xuat();
}
