#include <bits/stdc++.h>

void rebalance(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right) {
    while(left.size()-right.size()>1) {
        right.push(left.top());
        left.pop();
    }
    if(right.size()==0)
        return;
    while(left.top() > right.top()) {
        right.push(left.top());
        left.pop();
        left.push(right.top());
        right.pop();
    }
}

void findMedian(int *arr, int n)
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    for(int i=0; i<n; i++) {
        left.push(arr[i]);
        rebalance(left, right);
        if(left.size() == right.size()) {
            cout << (left.top()+right.top())/2 << " ";
        }else {
            cout << left.top() << " ";
        }
    }
}