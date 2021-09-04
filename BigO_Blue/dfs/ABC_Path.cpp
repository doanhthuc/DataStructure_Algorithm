#include "bits/stdc++.h"

using namespace std;

const int MAX = 51;
const int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
int h, w;
char table[MAX][MAX];
int visited[MAX][MAX];

bool isValid(int r, int c) {
    return (r >= 0 && r < h && c >= 0 && c < w);
}

int dfs(int sr, int sc) {
    int count = 0;

    for (int i = 0; i < 8; i++) {
        int r = sr + dr[i];
        int c = sc + dc[i];

        if (isValid(r, c) && table[r][c] - table[sr][sc] == 1 && visited[r][c] == 0) {
            dfs(r, c);
            count = max(count, visited[r][c]);
        }
    }

    visited[sr][sc] = count + 1;
    return visited[sr][sc];   
}

int main() {
    int t = 1;
    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> table[i][j];
                visited[i][j] = 0;
            }
        }
        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (table[i][j] == 'A') {
                    res = max(res, dfs(i, j));
                }
            }
        }

        cout << "Case " << t++ << ": " << res << endl;
    }

    return 0;
}