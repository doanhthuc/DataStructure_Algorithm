#include "bits/stdc++.h"
using namespace std;

#define long long long
const int MAX = 1011;
const long MOD = (long)10e9 + 7;
char a[MAX][MAX];

long countDP(int n, int m)
{
    long res[n + 1][m + 1];
    memset(res, 0, sizeof(res));
    res[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (a[i][j] == '#')
                continue;
            if (a[i][j] == '.')
            {
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
    }

    return res[n][m] % MOD;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int res = countDP(n, m);
    cout << res << endl;

    return 0;
}