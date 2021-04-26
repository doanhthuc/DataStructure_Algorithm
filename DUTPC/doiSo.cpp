#include "bits/stdc++.h"
using namespace std;

char chuyen(int d)
{
    return (char)d;
}
int main()
{
    long long arr[100];
    long long a, b, c, i, d;
    string s;
    string res;
    printf("Nhap so a: ");
    cin >> s;
    c = 16;
    i = 0;
    bool isNegative = false;
    if (a < 0)
    {
        a = -a;
        isNegative = true;
    }
    while (a != 0)
    {
        b = a % c;
        a = a / c;
        if (b > 9)
        {
            b = 65 - 10 + b;
        }
        arr[i] = b;
        i++;
    }
    printf("%d\n", i % 4);
    int extraZeros = 4 - (i % 4);
    for (int j = 0; j < extraZeros; j++)
    {
        arr[i] = 0;
        i++;
    }
    int count = 0;
    if (isNegative)
    {
        printf("-");
    }
    for (; i > 0; i--)
    {
        if (count == 4)
        {
            printf(" ");
            i++;
            count = 0;
            continue;
        }
        if (arr[i - 1] > 9)
        {
            printf("%c", arr[i - 1]);
            count++;
        }
        else
        {
            printf("%lld", arr[i - 1]);
            count++;
        }
    }
}