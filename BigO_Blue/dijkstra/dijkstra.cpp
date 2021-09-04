#include "bits/stdc++.h"

using namespace std;

const int MAX = 100;
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct options
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, options> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w)
        {
            continue;
        }
        for (auto v : graph[u])
        {
            if (w + v.second < dist[v.first])
            {
                dist[v.first] = w + v.second;
                pq.push(make_pair(v.first, dist[v.first]));
                path[v.first] = u;
            }
        }
    }
}

int main()
{
    int n, s, t;
    graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
    cin >> n;
    s = 0, t = 4;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d;
            if (d > 0)
            {
                graph[i].push_back(make_pair(j, d));
            }
        }
    }
    dijkstra(s);
    int ans = dist[t];
    cout << ans << endl;
    return 0;
}