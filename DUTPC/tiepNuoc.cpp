#include "bits/stdc++.h"
using namespace std;

#define long long long

const int MN = 1011;
const int INF = 111000;

long a[MN];
long f[MN][100111];

int main()
{
    ios::sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        memset(f, 1000000111, sizeof(f));
        sort(a + 1, a + n + 1);
        for (long i = 1; i <= n; i++)
        {
            f[i][0] = 0;
        }

        for (long i = 1; i <= n; i++)
        {
            for (long j = 1; j <= k; j++)
            {
                if (a[i] <= j)
                {
                    f[i][j] = min(f[i - 1][j], f[i - 1][j - a[i]] + 1);
                }
            }
        }
        long res = f[n][k] <= 1000000111 ? f[n][k] : -1;
        cout << res << endl;
    }

    return 0;
}