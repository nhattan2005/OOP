#include<bits/stdc++.h>
using namespace std;

int n;
struct matrix{
    int A[2001][2001];
    void init(){
            for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                            cin>>this->A[i][j];
                    }
            }
    }

    void new_state(matrix & trung_gian){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    trung_gian.A[i][j]=this->A[(2*i+j)%n][(i+j)%n];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    this->A[i][j]=trung_gian.A[i][j];
            }
        }
    }


    bool eq(matrix& B){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    if(this->A[i][j]!=B.A[i][j]) return false;
            }
        }
        return true;
    }


};

matrix C,ban_dau,hien_tai;
int k;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    ban_dau.init();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
               hien_tai.A[i][j]=ban_dau.A[i][j];
        }
    }
    hien_tai.new_state(C);
    k=1;
    while(ban_dau.eq(hien_tai)==false){
        k++;
        hien_tai.new_state(C);
    }
    cout<<k;
}

