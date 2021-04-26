#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/vsteps */
const int MOD = 14062008;

bool bad[100111];
int f[100111];

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        memset(bad, false, sizeof(bad));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < k; i++)
        {
            int u;
            cin >> u;
            bad[u] = true;
        }
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (bad[i])
                continue;
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }
        cout << f[n] << endl;
    }
    return 0;
}