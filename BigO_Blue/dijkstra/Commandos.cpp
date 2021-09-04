#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;

const int MAX = 111;
const int INF = 1e9;
vector<Vii> graph;

struct sortWay {
    bool operator() (const ii &a, const ii &b) {
        return a.second > b.second;
    }
};

vector<int> dijkstra(int s, int N) {
    vector<int> dist(N, INF);
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

        for (auto v: graph[u]) {
            if (w + v.second < dist[v.first]) {
                dist[v.first] = w + v.second;
                pq.push(make_pair(v.first, dist[v.first]));
            }
        }
    }
    return dist;
} 

int main() {
    int T, N, R, s, d, nCase = 1;
    cin >> T;
    while (T--) {
        cin >> N >> R;
        graph = vector<Vii>(N, Vii());
        int u, v, w;
        for (int i = 0; i < R; i++) {
            cin >> u >> v;
            graph[u].push_back(make_pair(v, 1));
            graph[v].push_back(make_pair(u, 1));
        }
        cin >> s >> d;
        vector<int> distS = dijkstra(s, N);
        vector<int> distD = dijkstra(d, N);
        int res = 0;

        for (int i = 0; i < N; i++) {
            res = max({res, distS[i] + distD[i]});
        }
        cout << "Case " << nCase++ << ": " << res << endl;
    }
    return 0;
}