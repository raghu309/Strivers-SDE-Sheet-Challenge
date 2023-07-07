#include <bits/stdc++.h>

void getAns(vector<int> &arr, int idx, int k, vector<int> &ds, vector<vector<int>> &ans) {
    if(idx == arr.size()) {
        if(k==0) {
            ans.push_back(ds);
        }
        return;
    }

    getAns(arr, idx+1, k, ds, ans);
    ds.push_back(arr[idx]);
    getAns(arr, idx+1, k-arr[idx], ds, ans);
    ds.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> ds;
    vector<vector<int>> ans;
    getAns(arr, 0, k, ds, ans);
    return ans;
}