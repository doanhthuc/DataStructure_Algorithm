#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9;
const int MAX = 100111;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);

struct option {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option > pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.first;
        int w = p.second;

        if (u == f) {
            break;
        }

        for (auto v: graph[u]) {
            if (w + v.second < dist[v.first]) {
                dist[v.first] = v.second + w;
                pq.push(make_pair(v.first, dist[v.first]));
            }
        }
    }
}


int main() {
    int s;
    cin >> s;
    while (s--) {
        int n;
        string name, sCity, fCity;
        cin >> n;
        graph = vector<vector<pair<int, int> >>(MAX, vector<pair<int, int> >());
        map<string, int> map;
        int p;
        for (int i = 1; i <= n; i++) {
            cin >> name >> p;
            map[name] = i;
            int v, w;
            for (int j = 0; j < p; j++) {
                cin >> v >> w;
                graph[i].push_back(make_pair(v, w));
            }
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> sCity >> fCity;
            dist = vector<int>(MAX, INF);
            dijkstra(map[sCity], map[fCity]);
            cout << dist[map[fCity]] << endl;
        }

    }
    return 0;
}