#include <bits/stdc++.h> 

bool getAns(string &target, int idx, unordered_set<string> &stt, vector<int> &dp) {
    if(idx >= target.size()) {
        return true;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    string cur = "";
    for(int i=idx; i<target.size(); i++) {
        cur += target[i];
        if(stt.count(cur) && getAns(target, i+1, stt, dp)) {
            return dp[idx] = true;
        }
    }
    return dp[idx] = false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    vector<int> dp(target.size()+1, -1);
    unordered_set<string> stt;
    for(auto &str:arr) {
        stt.insert(str);
    }
    return getAns(target, 0, stt, dp);
}





