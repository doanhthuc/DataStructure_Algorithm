#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 1011;
const int MAX_M = 300111;
const int INF = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> Vii;
vector<Vii> graph(MAX_N, Vii());
vector<int> dist(MAX_N);
vector<bool> visited(MAX_N);
vector<int> path(MAX_N);
int N, M;

struct options
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.second > b.second;
    }
};

void prims(int s)
{
    priority_queue<ii, Vii, options> pq;
    pq.push({s, 0});
    dist[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for (auto &neighbour : graph[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (!visited[v] && w < dist[v])
            {
                dist[v] = w;
                path[v] = u;
                pq.push({v, w});
            }
        }
    }
}

int main()
{
    int ntests = 0, p;
    cin >> ntests;
    while (ntests--)
    {
        cin >> p >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            dist[i] = INF;
            path[i] = -1;
            visited[i] = false;
            graph[i].clear();
        }
        int u, v, w;
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        prims(1);
        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            res += dist[i];
        }
        cout << res * p << endl;
    }
    return 0;
}