#include "bits/stdc++.h"

using namespace std;

const int MAX = 85;
const int INF = 1e9;
int dist[MAX][MAX];
int maxCost[MAX][MAX];
int cost[MAX];
int C, R;

void floydWarshall_2() {
    /* Need to run Floyd-Warshall's Algorithm twice. This is because of the interaction
    of the worstFeastCosts  */
    int time = 2;
    while (time--) {
        for (int k = 1; k <= C; k++) {
            for (int i = 1; i <= C; i++) {
                for (int j = 1; j <= C; j++) {
                    int maxFeast = max(maxCost[i][k], maxCost[k][j]);
                    if (dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + maxFeast) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        maxCost[i][j] = maxFeast;
                    }
                }
            }
        }
    }
}

int main() {
    int u, v, w, Q, nCases = 1;
    while (cin >> C >> R >> Q, C != 0) {
        for (int i = 1; i <= C; i++) {
            cin >> cost[i];
        }
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                dist[i][j] = INF;
                maxCost[i][j] = max(cost[i], cost[j]);
            }
        }
        for (int i = 0; i < R; i++) {
            cin >> u >> v >> w;
            dist[u][v] = dist[v][u] = w;
        }

        floydWarshall_2();
        if (nCases > 1) cout << endl;
        cout << "Case #" << nCases++ << endl;

        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            cout << (dist[u][v] == INF ? -1 : dist[u][v] + maxCost[u][v]) << endl;
        }
    }
    return 0;
}