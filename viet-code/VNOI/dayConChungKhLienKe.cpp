#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/lnacs */
const int MN = 10111;

int a[MN], b[MN], la, lb;
int f[MN][MN];

int main()
{
    ios::sync_with_stdio(0);
    int la, lb;
    while (cin >> la >> lb)
    {
        for (int i = 1; i <= la; i++)
            cin >> a[i];
        for (int i = 1; i <= lb; i++)
            cin >> b[i];

        memset(f, 0, sizeof(f));
        for (int i = 1; i <= la; i++)
        {
            for (int j = 1; j <= lb; j++)
            {
                if (a[i] == b[j])
                {
                    if (i <= 1 || j <= 1)
                        f[i][j] = 1;
                    else
                    {
                        f[i][j] = f[i - 2][j - 2] + 1;
                    }
                }
                else
                {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        cout << f[la][lb] << endl;
    }
    return 0;
}