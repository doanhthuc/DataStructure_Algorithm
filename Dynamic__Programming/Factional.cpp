#include <bits/stdc++.h>
using namespace std;

#define MAX 100

long fact(int n) {
    if (n <= 0) return 1;
    long F[MAX];
    F[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        F[i] = F[i-1] * i;
    }
    return F[n];
}

long fact2(int n) {
    if (n <= 0) return 1;
    long F1, F;
    F1 = 1;
    for (int i = 1; i <= n; i++)
    {
        F = F1 * i;
        F1 = F;
    }
    return F;
}

long fact3(int n) {
    if (n <= 0) return 1;
    long F = 1;
    for (int i = 1; i <= n; i++)
    {
        F = F*i;
    }
    return F;
}

int main() {
    cout << fact(6) << endl;
    cout << fact2(6) << endl;
    cout << fact3(6) << endl;
    return 0;
}