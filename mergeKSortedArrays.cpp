#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    for(auto &v:kArrays) {
        for(auto &el:v) {
            ans.push_back(el);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
