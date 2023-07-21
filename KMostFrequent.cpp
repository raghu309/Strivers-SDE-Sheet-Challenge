#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> arr)
{
    unordered_map<int, int> mpp;
    for(auto el:arr) {
        mpp[el]++;
    }
    map<int, vector<int>> sm;
    for(auto pr:mpp) {
        sm[pr.second].push_back(pr.first);
    }
        
    vector<int> ans;
    for(auto pr:sm) {
        for(auto el:pr.second)
            ans.push_back(el);
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() > k)
        ans.pop_back();
        
    return ans;
}