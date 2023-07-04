#include <bits/stdc++.h> 

bool getAns(vector<int> &arr, int idx, int k, vector<vector<int>> &dp) {
    if(k==0)
        return true;
    if(idx >= arr.size())
        return false;
    if(dp[idx][k] != -1)
        return dp[idx][k];

    bool ans = getAns(arr, idx+1, k, dp);
    if(k-arr[idx]>=0)
        ans = ans | getAns(arr, idx+1, k-arr[idx], dp);

    return dp[idx][k] = ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return getAns(arr, 0, k, dp);
}