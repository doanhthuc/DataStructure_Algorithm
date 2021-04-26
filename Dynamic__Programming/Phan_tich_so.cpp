#include <bits/stdc++.h>
using namespace std;

#define MAX 101

long phantichso(int n) {
    long a[MAX][MAX];   // bảng phương án
    int m, v;           //chỉ số dòng m, chỉ số cột v
    for (int j = 0; j <= n; j++)
    {
        a[0][j] = 0;
    }
    a[0][0] = 1;
    for (m = 0; m <= n; m++)
    {
        for (v = 0; v <= n; v++) {
            if (m > v) a[m][v] = a[m-1][v];
            else a[m][v] = a[m-1][v] + a[m][v-m];
        }
    }
    return a[n][n];
}

int main() {

    cout << phantichso(5) << endl;
    cout << phantichso(100) << endl;

    return 0;
}