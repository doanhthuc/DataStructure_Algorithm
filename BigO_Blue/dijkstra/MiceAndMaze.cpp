#include "bits/stdc++.h"

using namespace std;

const int MAX = 101;
const int INF = 1e9 + 5;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct options
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};


void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, options> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w) {
            continue;
        }
        for (auto v: graph[u]) {
            if (w + v.second < dist[v.first]) {
                dist[v.first] = w + v.second;
                pq.push(make_pair(v.first, dist[v.first]));
                path[v.first] = u;
            }
        }
    } 
}

int main() {
    int N, E, T, M;
    cin >> N >> E >> T >> M;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[v].push_back(make_pair(u, w));
    }

    dijkstra(E);
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= T) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}