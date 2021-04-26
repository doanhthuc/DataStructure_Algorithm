#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[200111];

int main()
{
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i * i <= 200000; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j <= 200000; j += i)
        {
            isPrime[j] = false;
        }
    }
    isPrime[1] = false;

    int l, r;
    while (cin >> l >> r)
    {
        for (int i = l; i <= r; i++)
        {
            if (isPrime[i])
            {
                cout << i << "\n";
            }
        }
    }
}