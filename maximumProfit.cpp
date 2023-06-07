#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int prev = INT_MAX;
    int ans = 0;

    for(auto el:prices) {
        ans = max(ans, el-prev);
        prev = min(prev, el);
    }

    return ans;
}