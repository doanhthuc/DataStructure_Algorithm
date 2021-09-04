#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/kagain */

const int MAXN = 30011;
int a[MAXN];
pair<int, int> lr[MAXN];

int main()
{
    int ntest;
    cin >> ntest;
    while (ntest--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        a[0] = 0;
        a[n + 1] = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= n; i++)
        {
            while (a[st.top()] >= a[i])
                st.pop();
            lr[i].first = st.top() + 1;
            st.push(i);
        }
        while (!st.empty())
        {
            st.pop();
        }

        st.push(n + 1);
        for (int i = n; i >= 1; i--)
        {
            while (a[st.top()] >= a[i])
            {
                st.pop();
            }
            lr[i].second = st.top() - 1;
            st.push(i);
        }
        int pos = 0;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] * (lr[i].second - lr[i].first + 1) > res)
            {
                res = a[i] * (lr[i].second - lr[i].first + 1);
                pos = i;
            }
        }
        cout << res << " " << lr[pos].first << " " << lr[pos].second << endl;
    }
    return 0;
}