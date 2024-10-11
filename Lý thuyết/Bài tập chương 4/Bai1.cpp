#include <bits/stdc++.h>
using namespace std;

class cArray
{
private:
    vector<int> Array;
public:
    void input(int n)
    {
        int value;
        cout << "Nhap mang: ";
        for(int i=1; i<=n; i++)
        {
            cin >> value;
            Array.push_back(value);
        }
    }

    void output()
    {
        cout << "Mang hien tai: ";
        for(int i=0; i<Array.size(); i++)
            cout << Array[i] << " ";
        cout << endl;
    }

    void generateRandomArray(int n) {
        Array.clear();
        srand(time(0));
        for (int i = 0; i < n; i++) {
            Array.push_back(rand() % 100);
        }
        cout << "Da tao mang ngau nhien." << endl;
    }

    void Count_Occurence(int x)
    {
        int cnt=0;
        for(int i=0; i<Array.size(); i++)
        {
            if(x == Array[i])
                cnt++;
        }
        cout << "So lan xuat hien cua x = " << x << " la: " << cnt << '\n';
    }

    bool isAscening(){
        for(int i=0; i<Array.size()-1; i++)
            if (Array[i] > Array[i+1])
                return false;
        return true;
    }

    int findSmallestOdd(){
        int minOdd = 999999999;
        for(int i=0; i<Array.size(); i++){
            if(Array[i]%2==1)
                minOdd = min(minOdd, Array[i]);
        }
        return minOdd;
    }

    void sortArrayAscending()
    {
        sort(Array.begin(),Array.end());
    }

};

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cArray arr;
    arr.input(n);
    arr.output();
    arr.generateRandomArray(n);
    arr.output();
    arr.isAscening();
    arr.Count_Occurence(10);
    arr.findSmallestOdd();
    arr.sortArrayAscending();
    arr.output();
    return 0;
}
