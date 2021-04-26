#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/nktick */
const int MN = 25011;

int a[MN], f[MN];

int main()
{
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
        }

        // f[i] = min cost connect 1...i
        f[2] = a[2];
        for (int i = 3; i <= n; i++)
        {
            if (i == 3)
            {
                f[i] = f[i - 1] + a[i];
            }
            else
            {
                f[i] = min(f[i - 1] + a[i], f[i - 2] + a[i]);
            }
        }
        cout << f[n];
    }

    return 0;
}