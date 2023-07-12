#include <bits/stdc++.h> 

void getAns(vector<int> &v, int idx, vector<int> &ds, vector<vector<int>> &ans) {
    if(idx >= v.size()) {
        ans.push_back(ds);
        return;
    }
    ds.push_back(v[idx]);
    getAns(v, idx+1, ds, ans);
    ds.pop_back();
    getAns(v, idx+1, ds, ans);
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    ans.push_back({});
    vector<int> ds;
    getAns(v, 0, ds, ans);
    ans.pop_back();
    return ans;
}