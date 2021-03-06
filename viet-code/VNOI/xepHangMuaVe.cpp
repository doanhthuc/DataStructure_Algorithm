#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/nktick */
const int MN = 60111;

int one[MN], two[MN];
int f[MN];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> one[i];
        for (int i = 1; i < n; i++)
            cin >> two[i];

        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1] + one[i];
            if (i >= 2)
            {
                f[i] = min(f[i], f[i - 2] + two[i - 1]);
            }
        }
        cout << f[n] << endl;
    }
    return 0;
}