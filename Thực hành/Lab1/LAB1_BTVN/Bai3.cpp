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

    void set_(int a,int b ){
            this->tu=a;
            this->mau=b;
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
     bool operator ==(phan_so b){
            return this->tu*b.mau==this->mau*b.tu;
     }

     bool operator <(phan_so b){
            return this->min_(b)==false;
     }

     void nhan(phan_so b){
        phan_so c;
        c.tu = (this->tu*b.tu);
        c.mau = (this->mau*b.mau);
        c.rut_gon();
        this->tu=c.tu;
        this->mau=c.mau;
    }
};


phan_so A[25];
phan_so max_array, min_array;
phan_so target;
vector<phan_so> ans;
int size_array;
bool pick[25];
void check(){
        phan_so tich;
        tich.set_(1,1);
        int dem=0;
       for(int i=1; i<=size_array; i++){
                if(pick[i]) {dem++; tich.nhan(A[i]);}
       }
       if(tich==target){
            if(ans.empty() || ans.size()>dem){
                  ans.clear();
                  for(int i=1; i<=size_array; i++){
                        if(pick[i]) ans.push_back(A[i]);
                  }
            }
       }
}
void ql(int idx){
    if( idx>size_array){
        check();
        return;
    }

    for(int i=0; i<=1; i++) {pick[idx]=i; ql(idx+1);}

}

int main(){
    cin>>size_array;
    for(int i=1; i<=size_array; i++){
        A[i].init();
    }
    sort(A+1,A+size_array+1);
    target.init();
    ql(1);
    for(auto v: ans) v.xuat();
}
