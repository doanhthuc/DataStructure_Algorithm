#include "bits/stdc++.h"
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    char mat[r][c];
    int res[5];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            if (mat[i][j] == '#')
                continue;
        }
    }
    return 0;
}