#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/mink */
const int MN = 40111;
const int INF = 2000111000;

int a[MN];
int minRange[MN];
list<int> dq;

int main()
{
    ios::sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        memset(minRange, 0, sizeof(minRange));
        dq.clear();

        for (int i = 1; i <= n; i++)
        {
            while (dq.size() && a[dq.back()] >= a[i])
                dq.pop_back();

            dq.push_back(i);

            if (dq.front() + k <= i)
                dq.pop_front();

            if (i >= k)
                minRange[i] = a[dq.front()];
        }

        for (int i = k; i <= n; i++)
        {
            cout << minRange[i] << " ";
        }
    }
    return 0;
}