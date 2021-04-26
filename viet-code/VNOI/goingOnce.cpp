#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/auction */
const int MN = 1011;

int a[MN];

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        int cost = 1;
        int tmp;
        int res = min(m, n);

        sort(a, a + m);
        for (int i = 0; i < m; i++)
        {
            // cost = a[i];
            tmp = max(res, a[i] * min(n, m - i));
            if (tmp > res)
            {
                res = tmp;
                cost = a[i];
            }
        }
        cout << cost << " " << res << endl;
    }

    return 0;
}