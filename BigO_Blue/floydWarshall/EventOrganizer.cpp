#include "bits/stdc++.h"

using namespace std;
// src: codechef
/* Sử dụng thuật toán Floyd Warshall để giải quyết bài toán. 
• Xây dựng ma trận với dist[i][j]dist[i][j] là chi phí thu về lớn nhất trong thời gian từ i đến j. 
Nếu có nhiều sự kiện tổ chức cùng lúc thì chọn ra sự kiện có mức giá cao nhất. 
• Sau khi sử dụng Floyd Warshall, kết quả bài toán sẽ nằm trong dist[0][48]dist[0][48] tương ứng với chi phí thu về lớn nhất trong thời gian từ giờ thứ 00 đến giờ thứ 4848. */

const int MAX = 48;
int dist[MAX + 1][MAX + 1];

void floydWarshall()
{
    for (int k = 0; k <= MAX; k++)
    {
        for (int i = 0; i <= MAX; i++)
        {
            for (int j = 0; j <= MAX; j++)
            {
                if (i <= k && k <= j) {
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int T, N, S, E, C;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i <= MAX; i++)
        {
            for (int j = 0; j <= MAX; j++)
            {
                dist[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++)
        {
            cin >> S >> E >> C;
            if (C > dist[S][E])
            {
                dist[S][E] = C;
            }
        }
        floydWarshall();
        cout << dist[0][MAX] << endl;
    }
    return 0;
}