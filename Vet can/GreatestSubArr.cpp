#include <iostream>
using namespace std;

int maxSubArr(int arr[], int n, int &strart, int &len){
    int max = INT_MIN;
    //lan luot xet cac mang con co do dai k (k = 1 --> n)
    for (int k = 1; k <= n; k++)
    {
        // mang con co do dai k bat dau tu vi tri (i = 0 --> n-k)
        for (int i = 0; i < n - k; i++)
        {
            // tinh tong mang con tu vi tri i, do dai k
            int sum = 0;
            for (int j = i; j < i + k; j++)
            {
                sum += arr[j];
            }
            // cap nhat lai max neu can thiet
            if (sum > max)
            {
                max = sum;
                strart = i;
                len = k;
            }
            
        }
        
    }
    return max;
}

int main(){
    int arr[10] = {-2, 1, 4, -3, 9, -8, 4};
    int n = 7;
    int max, start, len;
    max = maxSubArr(arr, n, start, len);
    cout << "Max sum: " << max << endl;
    cout << "Max sub array: \n";
    for (int i = start; i < start + len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
