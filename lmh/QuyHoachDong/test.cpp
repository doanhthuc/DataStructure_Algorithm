#include <iostream>
//#include <unordered_map>
using namespace std;

// bool subArraySum(int arr[], int n, int sum)
// {
//     // create an empty map
//     unordered_map<int, int> map;

//     // Maintains sum of elements so far
//     int curr_sum = 0;

//     for (int i = 0; i < n; i++)
//     {
//         // add current element to curr_sum
//         curr_sum = curr_sum + arr[i];

//         // if curr_sum is equal to target sum
//         // we found a subarray starting from index 0
//         // and ending at index i
//         if (curr_sum == sum)
//         {
//             return true;
//         }

//         // If curr_sum - sum already exists in map
//         // we have found a subarray with target sum
//         if (map.find(curr_sum - sum) != map.end())
//         {
//             return true;
//         }

//         map[curr_sum] = i;
//     }

//     // If we reach here, then no subarray exists
//     return false;
// }

bool isSubSet(int arr[], int n, int sum, int target, bool &res)
{
    if (sum == target)
    {
        res = true;
        return res;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        sum += arr[i];
        // cout << sum << "\n";
        if (sum == target)
        {
            res = true;
            return res;
        }
        isSubSet(arr, n - 1, sum, target, res);
        sum -= arr[i];
    }
    return res;
}

int main()
{
    int a[100];
    int n, s;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    int sum = 0;
    cout << "\n\n";
    bool res = false;
    bool k = isSubSet(a, n, sum, s, res);
    if (!k)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    return 0;
}