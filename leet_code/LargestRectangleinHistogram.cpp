#include "bits/stdc++.h"
using namespace std;

int arr[100];

int solve(int n, int arr[])
{
    int f[n];
    stack<int> stack;
    int res = 0;
    for (int i = n; i > 0; i++)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = 0;
    arr[n + 1] = 0;
    stack.push(0);
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && arr[i] <= arr[stack.top()])
        {
            stack.pop();
            f[i] = stack.empty() ? -1 : stack.top();
            res = max(res, arr[i] * (i - f[i] - 1));
        }
        // cout << f[i] << endl;
        stack.push(i);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(n, arr);
}