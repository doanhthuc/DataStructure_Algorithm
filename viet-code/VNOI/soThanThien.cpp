#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/nknumfre */
int reverse(int n)
{
    int res = 0;
    while (n > 0)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int l, r;
    while (cin >> l >> r)
    {
        int count = 0;
        for (int i = l; i <= r; i++)
        {
            if (__gcd(i, reverse(i)) == 1)
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}