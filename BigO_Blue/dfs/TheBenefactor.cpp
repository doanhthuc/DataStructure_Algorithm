#include "bits/stdc++.h"

using namespace std;

struct Node {
    int v, w;
};

const int MAX = 50000 + 5;
int V, E, leaf;
long long max_dist;
long long dist[MAX];
vector<Node> graph[MAX];

void dfs(int src) {
    memset(dist, -1, sizeof(dist));
    stack<int> s;
    dist[src] = 0;
    s.push(src);

    while(!s.empty()) {
        int u = s.top();
        s.pop();

        for (Node neighbour: graph[u]) {
            int v = neighbour.v;
            int w = neighbour.w;

            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                s.push(v);
                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    leaf = v;
                }
            }
        }
    }
}

int main() {
    int ntests, u, v, w;
    cin >> ntests;
    while (ntests--) {
        cin >> V;
        E = V - 1;
        for (int i = 0; i <= V; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            graph[u].push_back((Node) {v, w});
            graph[v].push_back((Node) {u, w});
        }

        max_dist = 0;
        dfs(1);
        dfs(leaf);

        cout << max_dist << endl;
    }
    return 0;
}