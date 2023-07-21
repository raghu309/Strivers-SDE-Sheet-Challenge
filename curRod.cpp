int dfs(vector<int> &price, int l, vector<int> &dp) {
	if(l == 1)
		return price[0];
	if(dp[l] != -1)
		return dp[l];
	int ans = 0;
	if(l < price.size())
		ans = price[l-1];

	for(int i=1; i<l; i++) {
		ans = max(ans, dfs(price, i, dp)+dfs(price, l-i, dp));
	}
	return dp[l] = ans;
}

int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1, -1);
	return dfs(price, n, dp);
}
