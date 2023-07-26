#include <bits/stdc++.h> 

int isPal[101][101];

bool check(string &s, int l, int r) {
    if(l==r || l==r-1) {
        return isPal[l][r] = (s[l]==s[r]);
    }
    if(isPal[l][r] != -1) 
        return isPal[l][r];
    if(s[l] != s[r]) {
        return isPal[l][r] = false;
    }
    return isPal[l][r] = check(s, l+1, r-1);
}

int getAns(string &str, int idx, vector<int> &dp) {
    if(idx >= str.size())
        return -1;
    if(dp[idx] != -1)
        return dp[idx];
    int ans = 1e9;
    for(int i=str.size()-1; i>=idx; i--) {
        if(check(str, idx, i)) {
            ans = min(ans, 1+getAns(str, i+1, dp));
        }
    }
    return dp[idx] = ans;
}

int palindromePartitioning(string str) {
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            isPal[i][j] = -1;
        }
    }
    vector<int> dp(str.size()+1, -1);
    return getAns(str, 0, dp);
}
