#include <bits/stdc++.h>

void getAns(vector<int> &arr, int idx, int k, vector<int> &ds, vector<vector<int>> &ans, int prev) {
	if(idx >= arr.size()) {
		if(k == 0)
			ans.push_back(ds);
		return;
	}
	if(k-arr[idx] >= 0 && arr[idx] != prev) {
		ds.push_back(arr[idx]);
		getAns(arr, idx+1, k-arr[idx], ds, ans, prev);
		ds.pop_back();
	}
	getAns(arr, idx+1, k, ds, ans, arr[idx]);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	vector<int> ds;
	getAns(arr, 0, target, ds, ans, -1);
	
	return ans;
}
