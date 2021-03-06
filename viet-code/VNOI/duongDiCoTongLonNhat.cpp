#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/qbmax */

const int MN = 111;
int a[MN][MN], f[MN][MN];

int main()
{
    int nRow, nCol;
    while (cin >> nRow >> nCol)
    {
        for (int i = 1; i <= nRow; i++)
        {
            for (int j = 1; j <= nCol; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int col = 1; col <= nCol; col++)
        {
            if (col == 1)
            {
                for (int i = 1; i <= nRow; i++)
                {
                    f[i][col] = a[i][col];
                }
            }
            else
            {
                for (int i = 1; i <= nRow; i++)
                {
                    f[i][col] = f[i][col - 1] + a[i][col];

                    if (i > 1)
                    {
                        f[i][col] = max(f[i][col], f[i - 1][col - 1] + a[i][col]);
                    }
                    if (i < nRow)
                    {
                        f[i][col] = max(f[i][col], f[i + 1][col - 1] + a[i][col]);
                    }
                }
            }
        }

        int res = f[1][nCol];
        for (int i = 1; i <= nRow; i++)
        {
            res = max(res, f[i][nCol]);
        }
        cout << res << endl;
    }

    return 0;
}