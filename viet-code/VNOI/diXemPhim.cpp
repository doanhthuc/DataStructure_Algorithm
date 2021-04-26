#include "bits/stdc++.h"
using namespace std;

/* https://oj.vnoi.info/problem/vcowflix */

int solve(int arr[], int n, int limit)
{
    int f[n + 1][limit + 1];
    int res = 0;

    memset(f[0], 0, sizeof(f[0])); // Khởi tạo trường hợp không có con bò nào thì xe chở 0 kg
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0; // Trường hợp có bò nhưng xe có limit = 0 thì cũng k chở đc con nào
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= limit; j++)
        {
            f[i][j] = f[i - 1][j]; // Giả sử không lấy còn bò đang xét
            /* 
            Nếu khối lượng con bò đang xét nhỏ hơn giới hạn còn lại xe có
            thể chở và tổng sau khi cộng vào lớn hơn tổng khi không lấy con
            bò hiện tại thì sẽ lấy thêm con bò hiện tại cho lên xe
            */
            if (arr[i] <= j && f[i][j] < f[i - 1][j - arr[i]] + arr[i])
            {
                f[i][j] = f[i - 1][j - arr[i]] + arr[i];
                /*  Đã chọn con bò thứ i rồi thì chỉ có thể chở thêm được 
                    trọng lượng limit - arr[i] */
            }
        }
    }
    res = f[n][limit];
    return res;
}

int main()
{
    int n, limit;
    while (cin >> limit >> n)
    {
        // vector<int> a(n);
        // for (auto &&x : a)
        // {
        //     cin >> x;
        // }
        // int res = 0;
        // for (int mask = 0; mask < (1 << n); mask++)
        // {
        //     int sum = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if ((mask >> i) & 1)
        //         {
        //             sum += a[i];
        //         }
        //         if (sum <= limit)
        //             res = max(res, sum);
        //     }
        // }

        // cout << res << endl;
        int weight[n + 1];
        weight[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i];
        }
        int res = solve(weight, n, limit);
        cout << res << endl;
    }
    return 0;
}