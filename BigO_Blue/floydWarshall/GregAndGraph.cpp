#include "bits/stdc++.h"

using namespace std;

// src: codeforces
const int MAX = 511;
int dist[MAX][MAX];
int middleV[MAX];
int res[MAX];

int main() {
    int n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> middleV[i];
    }
    
    for (int index = n - 1; index >= 0; index--) {
        int k = middleV[index];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }    
        int u, v;
        for (int i = index; i < n; i++) {
            u = middleV[i];
            for (int j = index; j < n; j++) {
                v = middleV[j];
                res[index] += dist[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}

/* Nhận xét: Nếu làm theo thứ tự bình thường như mô tả của đề 
thì việc khi xóa đi một đỉnh sẽ làm mất rất nhiều cạnh, 
gây ảnh hưởng lớn đến đồ thị và khiến việc tính lại đường đi ngắn nhất 
giữa mọi cặp đỉnh là rất khó khăn.

-> Duyệt ngược thứ tự các đỉnh và giả sử như ta đang thêm dần 
các đỉnh vào đồ thị để xử lý dễ dàng hơn.
Ứng dụng Floyd Warshall vào bài này, 
ta nhận xét rằng bản chất của việc xóa các đỉnh 
(thêm các đỉnh nếu xét theo chiều người lại) chính là 
đang chọn đỉnh đó làm một đỉnh trung gian mới. 
Từ đó ta chạy thuật toán với đỉnh trung gian được chọn 
và tính tổng khoảng cách ngắn nhất lúc bấy giờ, 
lưu vào mảng kết quả */