#include <bits/stdc++.h>

int getAns(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
	if(i >= s.size() || j >= t.size())
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(s[i] == t[j])
		return dp[i][j] = 1 + getAns(s, t, i+1, j+1, dp);
	return dp[i][j] = max(getAns(s, t, i+1, j, dp), getAns(s, t, i, j+1, dp));
}

int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
	return getAns(s, t, 0, 0, dp);
}