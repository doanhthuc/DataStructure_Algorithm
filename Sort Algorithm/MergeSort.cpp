#include <iostream>
using namespace std;
#define MAX 50

void splitHalfArr(int a[], int n, int T1[], int &n1, int T2[], int &n2){
    n1 = n / 2;
    n2 = n - n1;
    for (int i = 0; i < n1; i++)
    {
        T1[i] = a[i];
    }
    for (int j = 0; j < n2; j++)
    {
        T2[j] = a[n1 + j];
    }
}

void combineArr(int T1[], int n1, int T2[], int n2, int arr[], int &n){
    n = n1 + n2;
    int i, j, k;
    i = j = k = 0;
    while (i < n1 && j < n2) //khi ca 2 sub array deu con element
    {
        if(T1[i] < T2[j]) arr[k++] = T1[i++];
        else arr[k++] = T2[j++];
    }
    // khi 1 trong 2 sub-array het element
    while(i < n1) arr[k++] = T1[i++];
    while(j < n2) arr[k++] = T2[j++];
}

void mergeSort(int arr[], int n){
    if(n <= 1) return;
    int T1[MAX], T2[MAX];
    int n1, n2;
    splitHalfArr(arr, n, T1, n1, T2, n2);
    mergeSort(T1, n1);
    mergeSort(T2, n2);
    combineArr(T1, n1, T2, n2, arr, n);
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}