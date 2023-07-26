#include <bits/stdc++.h>

int getAns(string &f, string &t, int i, int j, vector<vector<int>> &dp) {
    if(i >= f.size()) {
        return t.size()-j;
    }
    if(j >= t.size()) {
        return f.size()-i;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(f[i] == t[j]) {
        return getAns(f, t, i+1, j+1, dp);
    }
    // remove
    int ans1 = 1 + getAns(f, t, i+1, j, dp);
    int ans2 = 1 + getAns(f, t, i, j+1, dp);
    int ans3 = 1 + getAns(f, t, i+1, j+1, dp);
    return dp[i][j] = min({ans1, ans2, ans3});
}

int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
    return getAns(str1, str2, 0, 0, dp);
}





