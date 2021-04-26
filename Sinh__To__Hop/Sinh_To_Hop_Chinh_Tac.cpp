#include <iostream>
using namespace std;

int a[50], n, k;

void nhap() {
    cout << "\nNhap n: ";
    cin >> n;
    cout << "\nNhap k: ";
    cin >> k;
}

void sinh(int &ok) {
    int i = k;
    while (i > 0 && a[i] == n+i-k)
    {
        i--;
    }
    a[i]++;
    if (i > 0)
    {
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[i] + j - i;
        }
    }
    else ok = 0;
}

void xuat() {
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void next(int ok) {
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    while (ok)
    {
        xuat();
        sinh(ok);
    }
    
}

int main() {
    int ok = 1;
    nhap();
    next(ok);
    return 0;
}