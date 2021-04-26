#include <iostream>
using namespace std;

int countKdivPairs(int A[], int n, int K)
{
    int freq[1000] = {0};

    // Count occurrences of all remainders
    for (int i = 0; i < n; i++)
        ++freq[A[i] % K];

    // If both pairs are divisible by 'K'
    int sum = freq[0] * (freq[0] - 1) / 2;

    // count for all i and (k-i)
    // freq pairs
    for (int i = 1; i <= K / 2 && i != (K - i); i++)
        sum += freq[i] * freq[K - i];
    // If K is even
    if (K % 2 == 0)
        sum += (freq[K / 2] * (freq[K / 2] - 1) / 2);
    return sum;
}

void taoMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}

int main()
{

    int A[100000], T[101][2];
    int n, k, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> T[i][0];
        cin >> T[i][1];
    }

    for (int j = 0; j < t; j++)
    {
        taoMang(A, T[j][0]);
        n = T[j][0];
        k = T[j][1];
        cout << countKdivPairs(A, n, k) << endl;
    }

    return 0;
}