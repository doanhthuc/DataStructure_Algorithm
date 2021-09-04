#include "bits/stdc++.h"

using namespace std;

#define X first
#define Y second

const int MAX = 111;
const int INF = 2050; // Max distance is from (0, 0) to (1024, 1024)
double dist[MAX][MAX];
vector<pair<int, int>> loc;
int n;

double getDistance(int i, int j) {
    return sqrt(pow(loc[i].X - loc[j].X, 2) + pow(loc[i].Y - loc[j].Y, 2));
}

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int ntests = 0;
    cin >> ntests;
    for (int t = 1; t <= ntests; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }
        int xCoordinate, yCoordinate;
        loc.clear();
        for (int i = 0; i < n; i++) {
            cin >> xCoordinate >> yCoordinate;
            loc.push_back({xCoordinate, yCoordinate});
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double d = getDistance(i, j);
                if (d <= 10) {
                    dist[i][j] = d;
                }
            }
        }
        floydWarshall();
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dist[i][j]);
            }
        }
        cout << "Case #" << t << ":" << endl;
        if (res != INF)
        {
            cout << fixed << setprecision(4) << res << endl;
        }
        else
        {
            cout << "Send Kurdy" << endl;
        }

        cout << endl;
    }

    return 0;
}