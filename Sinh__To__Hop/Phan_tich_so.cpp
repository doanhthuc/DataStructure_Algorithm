#include <iostream>
using namespace std;

int a[100] = {0}, b[100], n, count;

void nhap() {
   cout << "\nNhap n: ";
   cin >> n;
}

bool ok() {
    int tg = 0;
    for (int i = 1; i <= n; i++)
    {
        tg += a[i] * (i-1);
    }
    if (tg == n) return true;
    return false;
}

bool khongLap() {
    int tg = 0;
    int mark = 1;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]) tg = tg*10 + (i-1);
    }
    for (int j = 0; j < count; j++)
    {
        if (b[j] == tg) {
            mark = 0;
            return false;
        }
    }
    if (mark) {
        b[count] = tg;
        count++;
        return true;
    }
}

void xuat() {
    if(ok()) {
        if (khongLap())
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] && i-1)
                {
                    cout << i - 1 << " ";
                }
            }
            cout << endl;
        }
    }
}

void sinh(int &ok) {
    int i = n;
    while (i > 0 && a[i])
    {
        a[i] = 0;
        i--;
    }
    if(i > 0) a[i] = 1;
    else ok = 0;
}

void next(int ok) {
    while (ok)  // Lap tới khi ok = 0
    {
        xuat();
        sinh(ok);
    }
}

int main () {
    count = 0;
    int ok = 1;
    nhap();
    next(ok);
    return 0;
}
