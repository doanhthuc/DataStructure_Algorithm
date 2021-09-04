#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1001;
int c[MAXN][MAXN];
int f[MAXN][MAXN];

int dp(int n, int m)
{
    memset(f, 10005, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int x = 0; x <= i; x++)
            {
                f[i][j] = min(f[i - x][j - 1] + c[x][j], f[i][j]);
            }
        }
    }
    return f[n][m];
}

vector<int> trace(int n, int m)
{
    int i = n;
    int j = m;
    vector<int> res;
    while (j > 0)
    {
        for (int x = 0; x <= i; x++)
        {
            if (f[i][j] == f[i - x][j - 1] + c[x][j])
            {
                res.push_back(x);
                i -= x;
                j--;
                break;
            }
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    int m, n;
    cin >> n >> m;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    cout << dp(n, m) << endl;
    vector<int> res = trace(n, m);
    reverse(res.begin(), res.end());
    for (int i = 0; i < m; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}