#include<bits/stdc++.h>
using namespace std;

class cArray {
public:
    int* arr;  
    int size; 

    cArray(int n) {
        size = n;
        arr = new int[size]; 
        srand(time(0));

        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100000 - 50000;
        }
    }

    ~cArray() {
        delete[] arr;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int findMaxNeg() {
        int maxNeg = INT_MIN; 
        for (int i = 0; i < size; i++) {
            if (arr[i] < 0 && arr[i] > maxNeg) {
                maxNeg = arr[i];
            }
        }
        return maxNeg;
    }

    int count(int x) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        return count;
    }

    bool isDescending() {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void sortAscending() {
        sort(arr, arr+size);
    }
};

int main() {
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;

    cArray arr(n);

    cout << "mang da duoc random la: ";
    arr.display();

    int maxNeg = arr.findMaxNeg();
    if (maxNeg == INT_MIN) {
        cout << "Mang khong co so am" << endl;
    } else {
        cout << "So am lon nhat trong mang: " << maxNeg << endl;
    }

    int x;
    cout << "Nhap so can dem so lan xuat hien: ";
    cin >> x;
    int count = arr.count(x);
    cout << "so " << x << " xuat hien " << count << " lan" << endl;

    if (arr.isDescending()) {
        cout << "Mang duoc sap xep giam dan." << endl;
    } else {
        cout << "Mang ko duoc sap xep giam dan." << endl;
    }

    arr.sortAscending();
    cout << "Mang sau khi duoc sap xep tang dan: ";
    arr.display();

    return 0;
}
