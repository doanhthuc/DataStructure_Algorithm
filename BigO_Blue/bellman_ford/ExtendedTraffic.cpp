#include "bits/stdc++.h"

using namespace std;

const int MAX = 211 * 211;
const int INF = 1e9;
vector<int> weight(MAX);
vector<int> dist(MAX);
struct Edge;
vector<Edge> graph;
int n, m;

struct Edge
{
    int source;
    int target;
    int weight;

    Edge(int source, int target, int weight)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

void bellmanFord(int s)
{
    dist[s] = 0;
    int u, v, w;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = -INF;
            }
        }
    }
}

int main()
{
    int nTest, q, nCases = 1, f;
    cin >> nTest;
    while (nTest--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i];
            dist[i] = INF;
        }

        cin >> m;
        int u, v;
        graph.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph.push_back(
                Edge(u, v, int(pow((weight[v] - weight[u]), 3))));
        }

        bellmanFord(1);
        cin >> q;
        cout << "Case " << nCases++ << ":" << endl;
        for (int i = 0; i < q; i++) {
            cin >> f;
            if (dist[f] != INF && dist[f] >= 3) {
                cout << dist[f] << endl;
            } else {
                cout << "?" << endl;
            }
        }
        
    }
    return 0;
}