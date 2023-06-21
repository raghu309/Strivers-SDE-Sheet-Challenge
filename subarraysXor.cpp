#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mpp;
    mpp[0]++;
    int ans = 0;
    int cur = 0;
    for(auto el:arr) {
        cur = cur^el;
        if(mpp[cur^x]) {
            ans += mpp[cur^x];
        }
        mpp[cur]++;
    }
    return ans;
}