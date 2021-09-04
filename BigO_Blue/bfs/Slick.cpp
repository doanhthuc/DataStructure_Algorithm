#include "bits/stdc++.h"

using namespace std;

const int MAX = 255;
int f[MAX][MAX];
int N, M;
int offset[] = {0, 1, 0, -1, 0};

struct Cell
{
    int r, c;
};

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < N && c < M;
}

int bfs(Cell s)
{
    int area = 1;
    queue<Cell> q;
    q.push(s);
    f[s.r][s.c] = 0;
    while (!q.empty())
    {
        Cell tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = tmp.r + offset[i];
            int c = tmp.c + offset[i + 1];
            if (isValid(r, c) && f[r][c] == 1)
            {
                area++;
                f[r][c] = 0;
                q.push((Cell){r, c});
            }
        }
    }
    return area;
}

int main()
{
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> f[i][j];
            }
        }
        int area = 0;
        int isLand = 0;
        map<int, int> res;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (f[i][j] == 1)
                {
                    isLand++;
                    area = bfs((Cell){i, j});

                    res[area]++;
                }
            }
        }

        cout << isLand << endl;
        for (auto p : res)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}