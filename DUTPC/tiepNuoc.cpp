#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        // int f[n + 1][k + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // memset(f, k + 1, sizeof(f));
        sort(a, a + n);
        int i = n - 1;
        int count = 0;
        while (k > 0 && i >= 0)
        {
            k = k - a[i];
            count++;
            i--;
        }
        count = k > 0 ? -1 : count;
        cout << count << endl;
        /* for (int i = 1; i <= n; i++)
        {
            f[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (a[i] <= j)
                {
                    f[i][j] = min(f[i - 1][j], f[i - 1][j - a[i]] + 1);
                }
            }
        }
        int res = f[n][k] <= k + 1 ? f[n][k] : -1;
        cout << res << endl; */
    }

    return 0;
}