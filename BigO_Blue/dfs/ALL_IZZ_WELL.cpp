#include "bits/stdc++.h"

using namespace std;

const int MAX = 101;
const string key = "ALLIZZWELL";
int R, C;
bool found = false;
int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool visited[MAX][MAX];
char table[MAX][MAX];

bool isValid(int r, int c)
{
    return (r >= 0 && r < R && c >= 0 && c < C);
}

void dfs(int sr, int sc, int count)
{
    if (count == key.length())
    {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int r = sr + dr[i];
        int c = sc + dc[i];

        if (isValid(r, c) && table[r][c] == key[count] && !visited[r][c]) {
            visited[r][c] = true;
            dfs(r, c, count + 1);
            visited[r][c] = false;
        }
    }
}

int main()
{
    int ntests = 0;
    cin >> ntests;

    while (ntests--)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> table[i][j];
                visited[i][j] = false;
            }
        }

        found = false;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (table[i][j] == key[0])
                {
                    dfs(i, j, 1);
                }
                if (found) break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}