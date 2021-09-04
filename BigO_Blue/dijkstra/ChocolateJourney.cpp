#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;

const int MAX = 1e5 + 5;
const int INF = 1e9;
vector<Vii> graph;

struct sortWay
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.second > b.second;
    }
};

vector<int> dijkstra(int s, int N)
{
    vector<int> dist(N + 1, INF);
    priority_queue<ii, Vii, sortWay> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w)
        {
            continue;
        }
        for (auto &v : graph[u])
        {
            if (w + v.second < dist[v.first])
            {
                dist[v.first] = v.second + w;
                pq.push(make_pair(v.first, dist[v.first]));
            }
        }
    }
    return dist;
}

int main()
{
    int N, M, k, x, A, B;
    cin >> N >> M >> k >> x;
    vector<int> cities(k);
    graph = vector<Vii>(N + 1, Vii());
    for (int i = 0; i < k; i++)
    {
        cin >> cities[i];
    }
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    cin >> A >> B;
    vector<int> distA = dijkstra(A, N);
    vector<int> distB = dijkstra(B, N);
    int res = INF;
    for (int &city : cities)
    {
        if (distB[city] <= x)
        {
            res = min(res, distA[city] + distB[city]);
        }
    }
    cout << (res < INF ? res : -1) << endl;
    return 0;
}