#include "bits/stdc++.h"

using namespace std;

typedef vector<int> Vi;
const int MAX = 51 * 51;
const int INF = 1e9;
vector<string> graph(MAX);
vector<Vi> dist(MAX, Vi(MAX)); 
int M;

void floydWarshall() {
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < M; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int ntests = 0;
    string s;
    cin >> ntests;
    while (ntests--) {
        cin >> s;
        M = s.length();
        for (int i = 0; i < M; i++) {
            if (i == 0) {
                graph[0] = s;
            } else {
                cin >> graph[i];
            }
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 'Y') {
                    dist[i][j] = 1;
                } else {
                    dist[i][j] = (i == j ? 0 : INF);
                }
            }
        }
        floydWarshall();
        int nfriends = 0, index = 0;
        for (int i = 0; i < M; i++) {
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (dist[i][j] == 2) {
                    count++;
                }

                if (count > nfriends) {
                    nfriends = count;
                    index = i;
                }
            }
        }
        cout << index << " " << nfriends << endl;
    }

    return 0;
}