#include <bits/stdc++.h> 

bool isPal(string &s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void getAns(string &s, int idx, vector<string> &ds, vector<vector<string>> &ans) {
    if(idx>=s.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i=idx; i<s.size(); i++) {
        if(isPal(s, idx, i)) {
            string temp = s.substr(idx, i-idx+1);
            ds.push_back(temp);
            getAns(s, i+1, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<string> ds;
    vector<vector<string>> ans;
    getAns(s, 0, ds, ans);
    return ans;
}