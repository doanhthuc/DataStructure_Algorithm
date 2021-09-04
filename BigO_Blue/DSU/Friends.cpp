#include "bits/stdc++.h"

using namespace std;

const int MAX = 30011;
vector<int> parent(MAX);
vector<int> ranks(MAX), cnt(MAX);

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
        cnt[i] = 1;
    }
}

int find(int u)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v)
{
    int up = find(u);
    int vp = find(v);
    if (up != vp)
    {
        if (ranks[up] > ranks[vp])
        {
            parent[vp] = up;
            cnt[up] += cnt[vp];
        }
        else if (ranks[up] < ranks[vp])
        {
            parent[up] = vp;
            cnt[vp] += cnt[up];
        }
        else
        {
            ranks[up]++;
            parent[vp] = up;
            cnt[up] += cnt[vp];
        }
    }
}

int main()
{
    int u, v, n, m, ntests;
    cin >> ntests;
    while (ntests--)
    {
        cin >> n >> m;
        makeSet(n);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            unionSet(u, v);
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = max(res, cnt[i]);
        }
        cout << res << endl;
    }
    return 0;
}