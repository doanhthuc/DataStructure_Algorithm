#include <iostream>

using namespace std;
#define MAXN 100

int main(){
    int arr[MAXN], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    bool kt = true;
    if (n > 2)
    {
        for (int i = 2; i < n; i++)
        {
            if ((arr[i] - arr[i-1]) * (arr[i-1] - arr[i-2]) <= 0)
            {
                kt = false; 
            }
            
        }
        
    }
    if (kt) cout << "YES";
    else cout << "NO";
    return 0;
}