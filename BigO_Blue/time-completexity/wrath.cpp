#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    int f[n];
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    int j = n - 1, lastPos = 0, killed = 0;

    for (int i = n - 1; i >= 0; i--) {
        j = min(j, i);
        lastPos = max(0, i - f[i]);
        if (j > lastPos) {
            killed += j - lastPos;
            j = lastPos;
        }
    }

    cout << n - killed << endl;

    return 0;
}