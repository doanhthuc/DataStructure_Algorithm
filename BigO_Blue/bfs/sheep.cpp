#include "bits/stdc++.h"

using namespace std;

const int MAX = 255;
const int offset[] = {0, 1, 0, -1, 0};
char f[MAX][MAX];
int N, M, nSheep = 0, nWolf = 0;

struct Cell
{
    int r, c;
};

bool isValid(int r, int c)
{
    return (r >= 0 && r < N && c >= 0 && c < M);
}

void bfs(Cell s)
{
    queue<Cell> q;
    int sheep = f[s.r][s.c] == 'k' ? 1 : 0;
    int wolf = f[s.r][s.c] == 'v' ? 1 : 0;
    q.push(s);
    f[s.r][s.c] = '#';
    bool outGarden = false;

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = u.r + offset[i];
            int c = u.c + offset[i + 1];

            if (!isValid(r, c))
            {
                outGarden = true;
                continue;
            }

            if (f[r][c] != '#')
            {
                sheep += (f[r][c] == 'k');
                wolf += (f[r][c] == 'v');
                f[r][c] = '#';
                q.push((Cell){r, c});
            }
        }
    }

    if (outGarden)
    {
        nSheep += sheep;
        nWolf += wolf;
    }
    else
    {
        sheep > wolf ? nSheep += sheep : nWolf += wolf;
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> f[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (f[i][j] != '#') {
                bfs((Cell) {i, j});
            }
        }
    }

    cout << nSheep << " " << nWolf << endl;

    return 0;
}