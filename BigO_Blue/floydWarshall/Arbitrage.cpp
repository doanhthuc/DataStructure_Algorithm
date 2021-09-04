#include "bits/stdc++.h"

using namespace std;

const int MAX = 40;

map<string, int> curencies;
double dist[MAX][MAX];
int n, m;

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == 0) continue;
            for (int j = 0; j < n; j++) {
                dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
            }
        }
    }
}

int main() {
    int nCases = 1;
    string u, v;
    double w;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 0;
                if (i == j) dist[i][j] = 1;
            }
        }
        string curency;
        for (int i = 0; i < n; i++) {
            cin >> curency;
            curencies[curency] = i;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> w >> v;
            dist[curencies[u]][curencies[v]] = w;
        }  
        floydWarshall();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] > 1) {
                flag = true;
                break;
            }
        }
        cout << "Case " << nCases++ << ": " << (flag ? "Yes" : "No") << "\n";
    }
    return 0;
}