#include <bits/stdc++.h>

void rebalance(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right) {
	while(left.size()-right.size()>1) {
		right.push(left.top());
		left.pop();
	}
	if(right.size()==0)
		return;
	while(left.top()>right.top()) {
		right.push(left.top());
		left.pop();
		left.push(right.top());
		right.pop();
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	vector<int> ans;
	for(auto el:arr) {
		left.push(el);
		rebalance(left, right);
		if(left.size() == right.size()) {
			ans.push_back((left.top()+right.top())/2);
		}else {
			ans.push_back(left.top());
		}
	}
	return ans;
}
