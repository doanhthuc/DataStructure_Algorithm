#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> top_review;
    priority_queue<int> rest;
    int type, review, nReviews = 0;
    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == 1) {
            nReviews++;
            cin >> review;
            if (!top_review.empty() && review > top_review.top()) {
                rest.push(top_review.top());
                top_review.pop();
                top_review.push(review);
            } else {
                rest.push(review);
            }
            if (nReviews % 3 == 0) {
                top_review.push(rest.top());
                rest.pop();
            }
        } else {
            if (top_review.empty()) {
                cout << "No reviews yet" << endl;
            } else {
                cout << top_review.top() << endl;
            }
        }
    }
    return 0;
}