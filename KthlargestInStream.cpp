#include <bits/stdc++.h> 
class Kthlargest {
    int K;
public:
priority_queue<int, vector<int>, greater<int>> right;
priority_queue<int> left;
    Kthlargest(int k, vector<int> &arr) {
        K = k;
        for(auto &el:arr) {
            add(el);
        }
    }

    void rebalance() {
        while(right.size() > K) {
            left.push(right.top());
            right.pop();
        }
    }

    void add(int num) {
        right.push(num);
        rebalance();
    }

    int getKthLargest() {
       return right.top();
    }

};