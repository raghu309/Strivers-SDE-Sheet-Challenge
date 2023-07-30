#include <bits/stdc++.h>

int getAns(int k, int n, vector<vector<int>> &dp) {
    if(n == 0 || n == 1)
        return n;
    if(k == 1)
        return n;
    if(dp[k][n] != -1)
        return dp[k][n];
    int ans = 1e9;
    int l=0, h=n, t=0;

    while(l <= h) {
        int m = (l+h)/2;
        int left = getAns(k-1, m-1, dp);
        int right = getAns(k, n-m, dp);
        t = 1 + max(left, right);

        if(left < right) {
            l = m+1;
        }else {
            h = m-1;
        }
        ans = min(ans, t);
    }
    return dp[k][n] = ans;
}


int cutLogs(int k, int n)
{
    vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
    return getAns(k, n, dp);
}
