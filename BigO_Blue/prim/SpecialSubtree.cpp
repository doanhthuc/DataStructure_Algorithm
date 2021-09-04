#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct node
{
    int vertex;
    int weight;

    node(int d, int w) : vertex(d), weight(w) {}
};

class comparator
{
public:
    bool operator()(const node &a, const node &b) const
    {
        return a.weight > b.weight;
    }
};

int n, m, s;
vector<vector<node>> graph;

int prim(int s)
{
    priority_queue<node, vector<node>, comparator> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[s] = 0;
    visited[s] = true;
    pq.push(node(s, 0));

    while (!pq.empty())
    {
        int u = pq.top().vertex;
        pq.pop();
        visited[u] = true;

        for (node neighbor : graph[u])
        {
            int v = neighbor.vertex;
            int w = neighbor.weight;

            if (!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                pq.push(node(v, w));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            ans += dist[i];
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m;

    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(node(v, w));
        graph[v].push_back(node(u, w));
    }

    cin >> s;

    int ans = prim(s);

    cout << ans << endl;
    return 0;
}