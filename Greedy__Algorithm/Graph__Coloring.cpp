#include <bits/stdc++.h>
using namespace std;

#define MAX 8

//1. Hàm dùng 1 màu tô cho tất cả các đỉnh có thể tô
// --> Hàm trả về số đỉnh đã được tô
int to1mau(int a[][MAX], int n, int v[], int color);

//2. Hàm tô màu tất cả các đỉnh của đồ thị
// --> Hàm trả về số lượng màu được sử dụng
int toMau(int a[][MAX], int n, int v[]);

//Hàm bổ trợ: Kiểm tra đỉnh i có tô được màu c hay không
int toDuoc(int a[][MAX], int n, int v[], int i, int c);

int main() {
    int a[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0}
    };
    int n = 8;
    int kq;
    int v[MAX];
    kq = toMau(a, n, v);
    cout << "So mau su dung: " << kq << endl;
    cout << "Ket qua to mau\n";
    for (int i = 0; i < n; i++)
    {
        cout.width(4);
        cout << v[i];
    }
    cout << endl;
    return 0;
}

//1. Hàm dùng 1 màu tô cho tất cả các đỉnh có thể tô
// --> Hàm trả về số đỉnh đã được tô
int to1mau(int a[][MAX], int n, int v[], int color) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && toDuoc(a, n, v, i, color)) {
            v[i] = color;
            count++;
        }
    }
    return count;
}

//2. Hàm tô màu tất cả các đỉnh của đồ thị
// --> Hàm trả về số lượng màu được sử dụng
int toMau(int a[][MAX], int n, int v[]) {
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    int soMau = 0; // Số màu đã sử dụng
    int count = 0; // Số đỉnh đã được tô
    while (count < n)    // Đảm bảo hết các đỉnh
    {
        soMau++;
        count += to1mau(a, n, v, soMau);
    }
    return soMau;
}

//Hàm bổ trợ: Kiểm tra đỉnh i có tô được màu c hay không
int toDuoc(int a[][MAX], int n, int v[], int i, int c) {
    for (int j = 0; j < n; j++)
    {
        if (a[i][j] && v[j] == c) return 0;
    }
    return 1;    
}