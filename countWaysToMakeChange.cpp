#include <bits/stdc++.h>

long dfs(int *d, int idx, int value, vector<vector<long>> &dp) {
    if(value == 0)
        return 1;
    if(idx < 0)
        return 0;
    if(dp[idx][value] != -1)
        return dp[idx][value];
    
    long ans = dfs(d, idx-1, value, dp);
    if(d[idx] <= value) {
        ans += dfs(d, idx, value-d[idx], dp);
    }
    return dp[idx][value] = ans;
}

long countWaysToMakeChange(int *d, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return dfs(d, n-1, value, dp);
}