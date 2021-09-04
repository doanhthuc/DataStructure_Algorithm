#include "bits/stdc++.h"

using namespace std;

const int MAX = 10e5 + 5;
int hasCat[MAX], cats[MAX];
vector<vector<int> > graph;
int maxCat = 0;

int dfs(int u, int parent = 0) {

    if (cats[parent] > maxCat) return 0;
    
    int res = 0;
    if (hasCat[u]) {
        cats[u] = 1 + cats[parent];
    } else {
        cats[u] = 0;
    }


    bool isLeaf = true;

    for(int v: graph[u]) {
        if (v != parent) {
            isLeaf = false;
            res += dfs(v, u);
        }
    }
    if (isLeaf && cats[u] <= maxCat) return 1 + res;
    return res;
}

int main(int argc, char **argv) {
    int n;
    cin >> n >> maxCat;

    graph.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> hasCat[i];
    }

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dfs(1);
    cout << dfs(1);
    return 0;	
}