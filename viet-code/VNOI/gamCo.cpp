#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/vmunch */
const int MN = 111;

char a[MN][MN];
int visited[MN][MN];

int bfs(int startU, int startV)
{
    queue<pair<int, int>> qu;
    qu.push({startU, startV});

    memset(visited, -1, sizeof visited);
    visited[startU][startV] = 0;

    while (!qu.empty())
    {
        auto x = qu.front();
        int u = x.first;
        int v = x.second;
        qu.pop();
        if (a[u][v] == 'B')
        {
            return visited[u][v];
        }

        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (di * di + dj * dj == 1)
                {
                    int uu = u + di, vv = v + dj;
                    if (a[uu][vv] == '*')
                        continue;
                    if (visited[uu][vv] >= 0)
                        continue;

                    visited[uu][vv] = visited[u][v] + 1;
                    qu.push({uu, vv});
                }
            }
        }
    }
    assert(false);
}

int main()
{
    ios::sync_with_stdio(0);
    int nRow, nCol;
    while (cin >> nRow >> nCol)
    {
        memset(a, '*', sizeof a);

        for (int i = 1; i <= nRow; i++)
        {
            for (int j = 1; j <= nCol; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= nRow; i++)
        {
            for (int j = 1; j <= nCol; j++)
            {
                if (a[i][j] == 'C')
                {
                    cout << bfs(i, j) << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}