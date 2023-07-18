#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    int l=0, r=0;
    vector<int> ans;
    unordered_map<int, int> mpp;
    while(r < n) {
        mpp[arr[r++]]++;
        if(r-l>k) {
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0)
                mpp.erase(arr[l]);
            l++;
        }
        if(r-l==k)
            ans.push_back(mpp.size());
    }
    return ans;
}
