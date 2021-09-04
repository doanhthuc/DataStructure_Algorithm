#include "bits/stdc++.h"
using namespace std;

const int MAXN = 111;
char grid[MAXN][MAXN];

void dfs(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '.')
        return;
    grid[i][j] = '.';
    dfs(i - 1, j - 1, n, m);
    dfs(i - 1, j, n, m);
    dfs(i - 1, j + 1, n, m);
    dfs(i, j - 1, n, m);
    dfs(i, j + 1, n, m);
    dfs(i + 1, j - 1, n, m);
    dfs(i + 1, j, n, m);
    dfs(i + 1, j + 1, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    char mat[n + 1][m + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'W')
            {
                res++;
                dfs(i, j, n, m);
            }
        }
    }

    cout << res << endl;

    return 0;
}