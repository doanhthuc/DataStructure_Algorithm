#include <bits/stdc++.h>
using namespace std;

#define MAX 100

long fibonaci(int n) {
    if (n <= 2) return 1;
    long F[MAX];          // Dùng mảng 1 chiều để lưu các kết quả trung gian
    F[1] = F[2] = 1;      // 2 phần tử đầu của dãy
    for (int i = 3; i <= n; i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

// Cách 2: Dùng 3 biến
// F2 = Fibo(i-2), F1 = Fibo(i-1), F = F(i)

long fibo2(int n) {
    if (n <= 2) return 1;
    long f2, f1, f;
    f2 = f1 = 1;
    for (int i = 3; i <= n; i++)
    {
        f = f1 + f2;
        f2 = f1;
        f1 = f;
    }
    return f;
}

int main() {
    cout << fibonaci(10) << endl;
    cout << fibo2(10) << endl;
    return 0;
}