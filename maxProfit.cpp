

int func(vector<int> &values, vector<int> &weights, int idx, int w, vector<vector<int>> &dp) {
	if(idx >= values.size())
		return 0;
	if(dp[idx][w] != -1)
		return dp[idx][w];
	int ans = func(values, weights, idx+1, w, dp);
	if(weights[idx] <= w) {
		ans = max(ans, values[idx]+func(values, weights, idx+1, w-weights[idx], dp));
	}
	return dp[idx][w] = ans;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return func(values, weights, 0, w, dp);
}