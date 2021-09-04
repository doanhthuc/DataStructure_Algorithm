#include "bits/stdc++.h"

using namespace std;

int binarySearch(const vector<int> &a, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            right = mid - 1;
        } else if (a[mid] < x) {
            left = mid + 1;
        }
    }
    return -1;
}

int bsFirst(const vector<int> &a, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if ((mid == left || x > a[mid - 1]) && a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int bsLast(const vector<int> &a, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if ((mid == right || x < a[mid + 1]) && a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int lowerBound(const vector<int> &a, int left, int right, int x) {
    int pos = right;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= x) {
            pos = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return pos;
}

int upperBound(const vector<int> &a, int left, int right, int x) {
    int pos = right;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > x) {
            pos = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return pos;
}

int main() {
    vector<int> a;
    int n, x, value;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> value;
        a.push_back(value);
    }
    int res = binarySearch(a, 0, n - 1, x);
    cout << res << endl;
    return 0;
}