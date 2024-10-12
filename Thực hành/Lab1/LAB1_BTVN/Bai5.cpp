#include<bits/stdc++.h>
using namespace std;

int n,m;
struct matrix{
    int A[2002][2002];
    void init(){
            for(int i=1; i<=n; i++){
                    for(int j=1; j<=m; j++){
                            cin>>this->A[i][j];
                    }
            }
    }

    void build(){
        for(int i=1; i<=n+1; i++){
            for(int j=1; j<=m+1; j++){
                    this->A[i][j]+=this->A[i-1][j]+this->A[i][j-1]-this->A[i-1][j-1];
            }
        }
    }

    int get_sum(int a,int b,int c,int d){
         return this->A[c][d]-(a-1<=0?0:this->A[a-1][d])-(b-1<=0?0:this->A[c][b-1])+(a-1<=0 || b-1<=0?0:this->A[a-1][b-1]);

    }



};

matrix A;
int dem;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n;
     A.init();
     A.build();
     for(int x=1; x<=n; x++){
        for(int y=1; y<=m; y++){
               for(int px=x+1; px<=n; px++){
                    for(int  py=y+1; py<=m; py++){
                            if(A.get_sum(x-1,y-1,px+1,py+1)==(px-x+1)*(py-y+1) && A.get_sum(x,y,px,py)==(px-x+1)*(py-y+1))    {
                                    cout<<"["<<y-1<<","<<x-1<<","<<(py-1)-(y-1)+1<<","<<(px-1)-(x-1)+1<<"]"<<'\n';
                            }
                    }
               }
        }
     }
}

/*
10 10
0 0 1 0 0 0 0 0 0 1
0 0 1 0 1 0 0 1 1 0
0 0 0 0 0 0 0 1 1 0
1 1 1 0 0 0 0 0 1 0
1 1 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 1 1 0 0 0
*/
