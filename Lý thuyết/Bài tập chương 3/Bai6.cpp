#include<bits/stdc++.h>

using namespace std;

struct cComplex {
    double real, img;
    cComplex () {}
    cComplex (double r, double i): real(r), img(i) {}

    void input () {
        cin >> real >> img;
    }

    void print () { cout << '(' << real << ", " << img << ')'; }

    cComplex operator + (const cComplex &A) const {
        cComplex res;
        res.real = this->real + A.real;
        res.img  = this->img  + A.img;
        return res;
    }

    cComplex operator - (const cComplex &A) const {
        cComplex res;
        res.real = this->real + A.real;
        res.img  = this->img  + A.img;
        return res;
    }

    cComplex operator * (const cComplex &A) const {
        cComplex res;
        res.real = this->real * A.real - img * A.img;
        res.img  = this->real * A.img + this->img * A.real;
        return res;
    }

    cComplex operator / (const cComplex &A) const {
        cComplex res;
        res.real = (this->real * A.real + this->img * A.img) / (A.real * A.real + A.img + A.img);
        res.img  = (A.real * this->img  - this->real * A.img) / (A.real * A.real + A.img + A.img);
        return res;
    }

    void change_real (double x) { real = x; }
    void change_img  (double x) { img  = x; }
    double get_real () { return real; }
    double get_img  () { return img; }
};

int main () {
    cComplex A, B, C;
    A.input();
    B.input();

    cout << "A: "; A.print(); cout << '\n';
    cout << "B: "; B.print(); cout << '\n';

    A.change_real(5);
    B.change_img(6);

    cout << "imag of A: " << A.get_img() << '\n';
    cout << "real of B: " << B.get_real() << '\n';

    C = A + B;
    cout << "A + B: "; C.print(); cout << '\n';

    C = A - B;
    cout << "A - B: "; C.print(); cout << '\n';

    C = A * B;
    cout << "A * B: "; C.print(); cout << '\n';

    C = A / B;
    cout << "A / B: "; C.print(); cout << '\n';
}
