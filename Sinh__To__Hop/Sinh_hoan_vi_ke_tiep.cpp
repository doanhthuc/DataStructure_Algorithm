#include <iostream>
#include<iomanip>
using namespace std;

void tao(int a[], int &n) {
    cout << "\nNhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}

int sinh(int a[], int n, int &ok) {
    int i = n - 1; // xuất phát từ vị trí n-1
    while (i > 0 && a[i] > a[i+1])
    {
        i--; // Tìm a[i] đầu tiên < a[i+1] 
    }
    if (i > 0)
    {
        int k = n; // Xuất phát từ phần tử cuối
        while (a[i] > a[k])
        {
            k--;   // Tìm a[k] đầu tiên thỏa mãn a[i] < a[k]
        }
        int t = a[i];
        a[i] = a[k];
        a[k] = t;   // Đổi chỗ a[i] & a[k];
        int r = i + 1, s = n;
        while (r <= s)  // Đảo vị trí các phần tử a[i+1] đến a[n]
        {
            int tmp = a[r]; a[r] = a[s]; a[s] = tmp;
            r++;
            s--;
        }
    } else ok = 0; // ok = 0 khi chương trình đã sinh đủ n!
}

void xuat(int a[], int n) {
    for( int i = 1; i <= n; i++ )
		cout<< setw( 3 ) << a[i];
	cout<< endl;
}

void next(int a[], int n, int ok) {
    while (ok)
    {
        xuat(a, n);
        sinh(a, n, ok);
    }
}

int main(){
	int a[100], n, ok =1; // khoi tao ok = 1
	tao( a, n );
	next( a, n, ok );
	return 0;
}