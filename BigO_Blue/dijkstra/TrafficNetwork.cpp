#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;

const int MAX = 1e4 + 5;
const int INF = 1e9;
vector<Vii > graphS, graphT;
vector<int> distS, distT;

struct sortWay {
    bool operator() (const ii &a, const ii &b) {
        return a.second > b.second;
    }
};

void dijkstra(int s, vector<int> &dist, vector<Vii> graph) {
    priority_queue<ii, Vii, sortWay> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;

        if (w != dist[u]) {
            continue;
        }

        for (auto v: graph[u]) {
            if (w + v.second < dist[v.first]) {
                dist[v.first] = w + v.second;
                pq.push(make_pair(v.first, dist[v.first]));
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio;
    cin.tie(0);

    int nTest, n, m, k, s, t;
    cin >> nTest;
    while (nTest--) {
        cin >> n >> m >> k >> s >> t;
        distS = vector<int>(n + 1, INF);
        distT = vector<int>(n + 1, INF);
        graphS = vector<Vii>(n + 1, Vii());
        graphT = vector<Vii>(n + 1, Vii());
        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graphS[u].push_back(make_pair(v, w));
            graphT[v].push_back(make_pair(u, w));
        }
        dijkstra(s, distS, graphS);
        dijkstra(t, distT, graphT);
        int res = distS[t];

        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            int a = distS[u] + w + distT[v];
            int b = distS[v] + w + distT[u];
            res = min({res, a, b});
        }

        cout << (res != INF ? res : -1) << endl;
    }
    return 0;
}