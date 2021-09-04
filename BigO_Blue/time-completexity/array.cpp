#include "bits/stdc++.h"
using namespace std;
const int MAX = 10e5 + 5;

int freq[MAX];

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int j = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 0)
        {
            count++;
        }

        freq[arr[i]]++;

        while (count == k)
        {
            freq[arr[j]]--;
            if (freq[arr[j]] == 0)
            {
                cout << j + 1 << " " << i + 1;
                return 0;
            }
            j++;
        }
    }

    cout << "-1 -1";

    return 0;
}