#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    if(k == 1)
        return nums;
    if(k >= nums.size()) {
        return {*max_element(nums.begin(), nums.end())};
    }
    deque<pair<int, int>> dq;
    for(int i=0; i<k-1; i++) {
        while(dq.size() && dq.back().first <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back({nums[i], i});
    }
    int r = k-1;
    vector<int> ans;
    while(r < nums.size()) {
        while(dq.size() && dq.back().first <= nums[r]) {
            dq.pop_back();
        }
        dq.push_back({nums[r], r});
        r++;
        if(dq.size() && dq.front().second+k < r) {
            dq.pop_front();
        }
        ans.push_back(dq.front().first);
    }
    return ans;
}