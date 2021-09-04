#include "bits/stdc++.h"

using namespace std;

const int MAX = 1e5 + 5;

vector<int> freq(MAX);

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int j = 0, unique = 0;
    int longest = 0;
    for (int i = 0; i < n; i++) {
        if (freq[v[i]] == 0) {
            unique++;
        }
        freq[v[i]]++;

        while(j < n && unique > 2) {
            if (freq[v[j]] == 1) {
                unique--;
            }
            freq[v[j]]--;
            j++;
        }
        longest = max(longest, i - j + 1);
    }
    cout << longest << endl;
    return 0;
}