#include <bits/stdc++.h>
using namespace std;

#define MAX 6

int timDuong(int a[][MAX], int n, int start, int path[], int &np) {
    np = 0;               // Ban đầu chưa đi qua đỉnh nào
    int mark[MAX];        // Mảng cờ hiệu đánh dấu các đỉnh đã được đi qua
    int cur = start;      // Đỉnh hiện tại đang đứng
    int next;             // Cờ hiệu ghi nhận xem có đi tiếp được hay không
    int tongCP = 0;       // Tổng chi phí đường đi
    // Ban đầu, xử lý đỉnh xuất phát
    path[np++] = start;   // Thêm đỉnh này vào danh sách đường đi
    for (int i = 0; i < n; i++)
    {
        mark[i] = 0;       // Khởi tạo mảng đánh dấu đường đi là chưa đi
    }
    mark[start] = 1;
    do
    {
        // Tìm đỉnh đầu tiên có thể đi được từ đỉnh cur
        int i = 0;
        while (i < n && (a[cur][i] == 0 || mark[i] == 1))
        {
            i++;
        }
        // Xét kết quả
        if (i >= n) next =-1;     // Hết đường đi rồi
        else
        {
            next = i;             // Đỉnh i sẽ là đỉnh tiếp theo có thể tới
            // Tìm đỉnh có thể đi được có chi phí thấp nhất
            for (; i < n; i++)
            {
                if (mark[i] == 0 && a[cur][i] < a[cur][next])
                {
                    next = i;
                }
            }
            // Đi tới đỉnh next
            path[np++] = next;
            mark[next] = 1;
            tongCP += a[cur][next]; // Cập nhật lại tổng chi phí
            cur = next;             // Lúc này đỉnh next trở thành đỉnh hiện tại
            /*
            cout << tongCP << " " << next << endl;
            */
        }                     
    } while (next != -1);  // next == -1 tức là đã hết đường đi
    // Xem xét để kết luận
    
    if (np < n) return 0;   // không tìm được đường đi
    if (a[cur][start])     // Có đường đi từ đỉnh cuối đến đỉnh đầu
    {
        tongCP += a[cur][start];
        return tongCP;     // Trả kết quả tổng chi phí thực hiện chu trình
    }
    return 0; // Trường hợp từ đỉnh cuối không có đường đi về đỉnh đầu
}

int main() {
    int a[MAX][MAX] = {
        {0, 5, 8, 3, 2, 4},
        {5, 0, 7, 9, 11, 2},
        {8, 7, 0, 4, 6, 9},
        {3, 9, 4, 0, 2, 7},
        {2, 11, 6, 2, 0, 3},
        {4, 2, 9, 7, 3, 0}
    };
    int n = 6;
    int tongCP;
    int path[MAX];
    int np;
    tongCP = timDuong(a, n, 0, path, np);
    if (tongCP == 0) cout << "Khong tim duoc duong di";
    else
    {
        cout << "Tim duoc duong di: ";
        for (int i = 0; i < np; i++)
        {
            cout << path[i] << "-->";
        }
        cout << "0" << endl; // Đỉnh xuất phát cũng là đỉnh cuối cùng
        cout << "Tong chi phi: " << tongCP << endl;
    }
    
    
    return 0;
}