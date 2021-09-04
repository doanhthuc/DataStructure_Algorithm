#include "bits/stdc++.h"

using namespace std;

const int MAX = 1011;
vector<vector<int>> graph;
vector<int> dist(MAX);

void dfs(int u, int parent) {
    dist[u] = dist[parent] + 1;
    for (int v: graph[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }
}


int main() {
    int n;
    cin >> n;
    graph.resize(n + 1);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    int q, cid, min_dist = MAX, res;
    cin >> q;
    

    for (int i = 0; i < q; i++) {
        cin >> cid;
        if (dist[cid] < min_dist || (dist[cid] == min_dist && cid < res))
        {
            min_dist = dist[cid];
            res = cid;
        }
    }

    cout << res << endl;
    return 0;
}