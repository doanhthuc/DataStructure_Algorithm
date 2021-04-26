#include "bits/stdc++.h"
using namespace std;

#define int long long
/* https://oj.vnoi.info/problem/linegame */
const int MN = 1000111;
const int INF = 1000111000111LL;

int a[MN];
int f[2][MN];

int32_t main()
{
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        f[0][0] = 0;
        f[1][0] = -INF;

        for (int i = 1; i <= n; i++)
        {
            f[0][i] = max(f[0][i - 1], f[1][i - 1] - a[i]);
            f[1][i] = max(f[1][i - 1], f[0][i - 1] + a[i]);
        }
        cout << max(f[0][n], f[1][n]);
    }
    return 0;
}