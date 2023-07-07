#include <bits/stdc++.h> 

void getAns(vector<int> &arr, int idx, vector<int> &ds, set<vector<int>> &stt) {
    if(idx >= arr.size()) {
        stt.insert(ds);
        return;
    }
    getAns(arr, idx+1, ds, stt);
    ds.push_back(arr[idx]);
    getAns(arr, idx+1, ds, stt);
    ds.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> stt;
    vector<int> ds;
    getAns(arr, 0, ds, stt);
    vector<vector<int>> ans;
    for(auto &v:stt)
        ans.push_back(v);
    return ans;
}