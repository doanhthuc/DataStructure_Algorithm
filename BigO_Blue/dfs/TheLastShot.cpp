#include "bits/stdc++.h"

using namespace std;

const int MAX = 1e4 + 5;
int n, m;
vector<int> graph[MAX];
bool visited[MAX];

int dfs(int u) {
    int res = 1;
    visited[u] = true;
    for (int v: graph[u]) {
        if (!visited[v]) {
            res += dfs(v);
        }
    }
    return res;
}


int main() {
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int maxBombs = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        maxBombs = max(maxBombs, dfs(i));
    }

    cout << maxBombs << endl;
    return 0;
}