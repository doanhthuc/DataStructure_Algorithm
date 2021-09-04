#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9;
const int MAX = 500 + 5;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct option {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w) {
            continue;
        }
        for (auto v: graph[u]) {
            if (v.second + w < dist[v.first]) {
                dist[v.first] = v.second + w;
                pq.push(make_pair(v.first, dist[v.first]));
                path[v.first] = u;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    graph = vector<vector<pair<int, int> > >(MAX, vector<pair<int, int> >());
    int u, v, w;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    cin >> u;
    dijkstra(u);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        cout << (dist[v] != INF ? to_string(dist[v]) : "NO PATH") << endl;
    }

    return 0;
}