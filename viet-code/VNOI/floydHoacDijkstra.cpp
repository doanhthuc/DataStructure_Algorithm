#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/floyd */
const int MN = 60111;

int main()
{
    int n, m, q;
    while (cin >> n >> m >> q)
    {
        vector<vector<pair<int, int>>> adj(n);

        while (m--)
        {
            int u, v, c;
            cin >> u >> v >> c;
            u--;
            v--;

            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        //dijkstra
        vector<vector<int>> f(n);
        vector<vector<int>> trace(n);
        for (int i = 0; i < n; i++)
        {
            f[i].resize(n);
            trace[i].resize(n);

            set<pair<int, int>> all;
            all.insert({0, i});
            f[i][i] = 0;
            trace[i][i] = -1;

            while (!all.empty())
            {
                auto [fu, u] = *all.begin();
                all.erase(all.begin());

                if (f[i][u] != fu)
                    continue;

                for (auto [v, c] : adj[u])
                {
                    if (f[i][v] > f[i][u] + c)
                    {
                        f[i][v] = f[i][u] + c;
                        all.insert({f[i][v], v});
                    }
                }
            }
        }
    }

    return 0;
}