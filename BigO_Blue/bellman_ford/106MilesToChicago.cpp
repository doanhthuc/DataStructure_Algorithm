#include "bits/stdc++.h"

using namespace std;

const int MAX = 111;
const int MAX_E = 111 * 50;
int n, m;
double prob[MAX];
struct Edge;
vector<Edge> graph(MAX_E);

struct Edge
{
    int source;
    int target;
    double weight;

    Edge(int source = 0, int target = 0, double weight = 0)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

void bellmanFord(int s)
{
    fill(prob, prob + n + 1, -1.0);
    prob[s] = 1.0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = graph[j].source;
            int v = graph[j].target;
            double w = graph[j].weight;

            prob[u] = max(prob[u], prob[v] * w);
            prob[v] = max(prob[v], prob[u] * w);
        }
    }
}

int main()
{
    int u, v, w;
    while (cin >> n, n != 0)
    {
        cin >> m;
        graph.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            graph.push_back(Edge (u, v, w / 100.0));
        }
        bellmanFord(1);
        cout << fixed << setprecision(6) << prob[n] * 100.0 << " percent" << endl;
    }
    return 0;
}