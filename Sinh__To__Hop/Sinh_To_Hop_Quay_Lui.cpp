#include <iostream>
using namespace std;

void nhap(int &n, int &k) {
    cout << "\nNhap n: ";
    cin >> n;
    cout << "\nNhap k: ";
    cin >> k;
}

void xuat(int a[], int k) {
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void next (int i, int a[], int n, int k) {
    for (int j = a[i-1] + 1; j <= n-k + i; j++)
    {
        a[i] = j;
        if( i == k) xuat(a, k);
        else next(i + 1, a, n, k);
    }
}

int main() {
    int a[100] = {}, n, k;
    nhap(n, k);
    next(1, a, n, k);
    return 0;
}