#include <iostream>

using namespace std;
#define MAXN 50

int main(){
    int a[MAXN], b[MAXN], c[MAXN];
    int n, m;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int i = 0, j = 0,k = 0;
    while (i < n && j < m)
    {
        if(a[i] > b[j]) c[k++] = b[j++];
        else c[k++] = a[i++];
    }
    while(i < n) c[k++] = a[i++];
    while(j < m) c[k++] = b[j++];

    for (int i = 0; i < n + m; i++)
    {
        cout << c[i] << " ";
    }
    

    return 0;
}