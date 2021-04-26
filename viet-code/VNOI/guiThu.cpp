#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    string s1, s2;
    int l1, l2, n;
    bool isSame = false;
    while (cin >> s1 >> s2)
    {
        n = l1 = s1.length();
        l2 = s2.length();
        for (int i = 0; i < l1; i++)
        {
            isSame = true;
            for (int j = i; j < l1; j++)
            {
                if (s1[j] != s2[j - i])
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
            {
                n = i;
                break;
            }
        }
        cout << n + l2 << endl;
    }
}