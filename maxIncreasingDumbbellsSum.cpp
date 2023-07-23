#include <bits/stdc++.h> 
int getAns(vector<int> &rack, int idx, int prev, vector<vector<int>> &dp) {
	if(idx >= rack.size())
		return 0;
	if(dp[idx][prev+1] != -1)
		return dp[idx][prev+1];
	int ans = getAns(rack, idx+1, prev, dp);
	int prevWt = prev==-1?0:rack[prev];
	if(rack[idx] > prevWt)
		ans = max(ans, getAns(rack, idx+1, idx, dp) + rack[idx]);
	return dp[idx][prev+1] = ans;	
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return getAns(rack, 0, -1, dp);
}