#include <bits/stdc++.h>
using namespace std;

class Circle {
private:
    double radius;
    double x, y;
public:
    Circle(double x_, double y_, double r)
    {
        x = x_;
        y = y_;
        radius = r;
    }

    double Area()
    {
        return M_PI * pow(radius, 2);
    }

    double circumference()
    {
        return 2 * M_PI * radius;
    }

    void displayInformation()
    {
        cout << "Chu vi: " << circumference() << '\n';
        cout << "Dien tich: " << Area();
    }
};

int main()
{
    double x, y, r;
    cout << "Nhap toa do duong tron (x,y): ";
    cin >> x >> y;
    cout << "Nhap ban kinh (r): ";
    cin >> r;
    Circle cir(x, y, r);
    cir.displayInformation();
    return 0;
}
