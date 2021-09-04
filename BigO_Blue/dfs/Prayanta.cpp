#include "bits/stdc++.h"

using namespace std;

const int MAX = 10e5;
bool visited[MAX];
vector<vector<int> > graph(MAX);

void dfs(int s) {
    visited[s] = true;
    for(int v: graph[s]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main () {
    int ntests = 0;
    cin >> ntests;
    while (ntests--)
    {
        int n, e;
        cin >> n >> e;
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            graph[i].clear();
        }

        int u, v;
        for (int i = 0; i < e; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i);
            }
        }
        cout << count << endl;
    }
    
    return 0;
}