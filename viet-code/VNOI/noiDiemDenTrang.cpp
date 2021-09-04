#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/bwpoints */

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(2 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i + n].first;
        v[i + n].second = 0;
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 1; i < 2 * n; i++)
    {
        if (v[i].second != v[i - 1].second)
        {
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}