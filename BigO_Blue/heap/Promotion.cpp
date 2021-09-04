#include "bits/stdc++.h"

using namespace std;

const int MAX = 1e6 + 5;

struct Bill {
    int number, price;
};

struct BillAscendingPrice {
    bool operator() (const Bill &a, const Bill &b) {
        return a.price < b.price;
    }
};

struct BillDescendingPrice {
    bool operator() (const Bill &a, const Bill &b) {
        return a.price > b.price;
    }
};

int main() {
    int n, k, x, nBills = 0;
    long long money = 0;
    bool taken[MAX] = {};
    priority_queue<Bill, vector<Bill>, BillAscendingPrice> max_pq;
    priority_queue<Bill, vector<Bill>, BillDescendingPrice> min_pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            nBills++;
            max_pq.push((Bill) {nBills, x});
            min_pq.push((Bill) {nBills, x});
        }
        while (taken[max_pq.top().number]) {
            max_pq.pop();
        }
        while (taken[min_pq.top().number]) {
            min_pq.pop();
        }

        money += max_pq.top().price - min_pq.top().price;
        taken[max_pq.top().number] = taken[min_pq.top().number] = true;
        max_pq.pop();
        min_pq.pop();
    }
    cout << money << endl;

    return 0;
}