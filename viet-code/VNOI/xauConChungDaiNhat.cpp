#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/qbstr */

int f[2011][2011];

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int la = a.size();
        int lb = b.size();

        a = " " + a + " ";
        b = " " + b + " ";

        // f[i][j] = max subseq a[1...i] & b[1...j]
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= la; i++)
        {
            for (int j = 1; j <= lb; j++)
            {
                if (a[i] == b[j])
                {
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                else
                {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        cout << f[la][lb] << endl;
    }

    return 0;
}