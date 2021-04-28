#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

const int N = 2005;
const int OO = 1e9 + 7;

typedef pair<int, int> ii;
typedef vector<ii> Vii;

int n, m;
Vii g[N];
int d[N];

void dijkstra(int st)
{
    priority_queue<ii, Vii, greater<ii>> q;
    memset(d, OO, sizeof(d));
    d[st] = 0;
    q.push({st, 0});
    while (!q.empty())
    {
        int u = q.top().X;
        int du = q.top().Y;
        q.pop();
        if (d[u] != du)
        {
            continue;
        }
        for (auto x : g[u])
        {
            int v = x.X;
            int dv = x.Y;
            if (d[v] > dv + d[u])
            {
                d[v] = dv + d[u];
                q.push({v, d[v]});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijkstra(1);

    return 0;
}
