#include "bits/stdc++.h"
using namespace std;

/* hhttps://oj.vnoi.info/problem/vratf */
int solve(int n, int k)
{
    if (n <= k)
        return 1;
    if ((n + k) % 2)
        return 1;

    int a = (n + k) / 2;
    int b = n - a;

    return solve(a, k) + solve(b, k);
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        cout << solve(n, k) << endl;
    }
    return 0;
}