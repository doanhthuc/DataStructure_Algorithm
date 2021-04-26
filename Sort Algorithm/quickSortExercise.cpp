#include <iostream>

using namespace std;
#define MAXN 100001

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArr(int arr[], int n){
    for(int i =0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[MAXN], b[MAXN];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            b[k++] = arr[i];
        }
    }
    quickSort(b, 0, k-1);
    printArr(b, k);
    cout << endl;
    k = 0;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] < 0){
            arr[i] = b[k++];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            arr[i] = b[k++];
        }
    }
    printArr(arr, n);
    return 0;
}