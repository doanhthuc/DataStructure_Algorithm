#include "bits/stdc++.h"

using namespace std;

const int MAX = 2e4 + 5;
const int INF = 1e9;
vector<int> dist;
struct Edge;
vector<Edge> graph;
int n, m;

struct Edge
{
    int source;
    int target;
    int weight;

    Edge(int source = 0, int target = 0, int weight = 0)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

bool bellmanFord(int s) {
    dist = vector<int>(n + 1, INF);
    dist[s] = 0;
    int u, v, w;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    int nTest = 0;
    cin >> nTest;
    while (nTest--) {
        graph.clear();
        cin >> n >> m;
        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph.push_back(Edge(u, v, w));
        }
        cout << (!bellmanFord(0) ? "possible" : "not possible") << endl;
    }

    return 0;
}