#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/nkabd */
int sum[100111];

int main()
{
    // init
    for (int n = 1; n <= 100000; n++)
    {
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i * i == n)
                {
                    sum[n] += i;
                }
                else
                {
                    sum[n] += i + n / i;
                }
            }
        }
    }

    int l, r;
    while (cin >> l >> r)
    {
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            if (sum[i] - i > i)
            {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}