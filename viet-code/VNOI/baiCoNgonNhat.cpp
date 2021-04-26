#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/vbgrass */

char a[111][111];

int main()
{
    int nRow, nCol;
    while (cin >> nRow >> nCol)
    {
        int res = 0;
        memset(a, '.', sizeof(a));
        for (int i = 1; i <= nRow; i++)
        {
            for (int j = 1; j <= nCol; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= nRow; i++)
        {
            for (int j = 1; j <= nCol; j++)
            {
                if (a[i][j] == '#')
                {
                    if (a[i - 1][j] == '.' && a[i][j - 1] == '.')
                        res++;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}