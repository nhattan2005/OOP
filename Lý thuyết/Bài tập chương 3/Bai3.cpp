#include<bits/stdc++.h>
using namespace std;

 class point{
    private:
            float x,y;
    public:
        void init(){
            cout<<"toa do diem: ";
            cin>>this->x>>this->y;
        }
        double dis(const point& B){
                double a= (this->x  - B.x);
                double b= (this->y  - B.y);
                return sqrt(a*a + b*b);
        }
 } point1,point2;

 int main(){
    point1.init();
    point2.init();
    cout<<"Khoang cach giua hai diem la: ";
    cout<<fixed<<setprecision(5)<<point1.dis(point2);
 }

