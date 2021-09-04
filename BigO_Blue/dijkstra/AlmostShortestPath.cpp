#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;

const int MAX = 511;
const int INF = 1e9;
vector<Vii> graph(MAX, Vii()), graphS(MAX, Vii()), graphD(MAX, Vii());
vector<int> dist(MAX), distS(MAX), distD(MAX);

struct sortWay {
    bool operator() (const ii &a, const ii &b) {
        return a.second > b.second;
    }
};

void dijkstra(int s, vector<int> &dist, vector<Vii> &graph) {
    priority_queue<ii, Vii, sortWay> pq;
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
        for (auto &v : graph[u]) {
            if (w + v.second < dist[v.first]) {
                dist[v.first] = w + v.second;
                pq.push(make_pair(v.first, dist[v.first]));
            }
        }
    }
}

int main() {
    int N, M, S, D;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (int i = 0; i < N; i++) {
            graph[i].clear();
            graphS[i].clear();
            graphD[i].clear();
            dist[i] = INF;
            distS[i] = INF;
            distD[i] = INF;
        }
        cin >> S >> D;
        int u, v, w;
        for (int i = 0; i < M; i++) {
            cin >> u >> v >> w;
            graphS[u].push_back(make_pair(v, w));
            graphD[v].push_back(make_pair(u, w));
        }
        dijkstra(S, distS, graphS);
        dijkstra(D, distD, graphD);
        int shotestPath = distS[D];
        for (int u = 0; u < N; u++) {
            for (auto &neighbour: graphS[u]) {
                int v = neighbour.first;
                int w = neighbour.second;
                if (distS[u] + w + distD[v] != shotestPath) {
                    graph[u].push_back(make_pair(v, w));
                } 
            }
        }
        dijkstra(S, dist, graph);
        cout << (dist[D] != INF ? dist[D] : -1) << endl;
    }
    return 0;
}