#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100011;
int f0[MAXN], label[MAXN];
vector<int> g[MAXN];

int main()
{
    int n, k, t, m;
    cin >> n >> k >> t;
    memset(label, -1, sizeof(label));
    for (int i = 1; i <= k; i++)
    {
        cin >> f0[i];
        label[f0[i]] = 0;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= k; i++)
    {
        q.push(f0[i]);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            if (label[v] == -1 && label[u] < t)
            {
                label[v] = label[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << label[i] << " ";
    }

    return 0;
}