void getAns(vector<int> &num, int idx, int curSum, vector<int> &ans) {
	if(idx == num.size()) {
		ans.push_back(curSum);
		return;
	}
	getAns(num, idx+1, num[idx]+curSum, ans);
	getAns(num, idx+1, curSum, ans);
	
}

vector<int> subsetSum(vector<int> &num){	
	vector<int> ans;
	getAns(num, 0, 0, ans);
	sort(ans.begin(), ans.end());
	return ans;
}