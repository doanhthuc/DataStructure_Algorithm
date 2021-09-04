#include "bits/stdc++.h"

using namespace std;
// src: codeforces

#define left _left
#define right _right

const int MAX = 10011;
const int MAX_A = 1000;
int n, k, A[MAX];
double sumEnergy, sumTransfer, left, right, mid;

int main() {
    cin >> n >> k;
    sumEnergy = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sumEnergy += A[i];
    }

    left = 0;
    right = MAX_A;

    while (right - left > 1e-7) {
        mid = (left + right) / 2;
        sumTransfer = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > mid) {
                sumTransfer += A[i] - mid;
            }
        }
        if (mid * n < sumEnergy - sumTransfer * k / 100) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.9f", left);
    return 0;
}