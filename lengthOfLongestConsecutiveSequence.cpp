#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> stt;
    for(auto el:arr)
        stt.insert(el);

    int ans = 1;

    for(auto el:stt) {
        if(stt.count(el-1)==0) {
            int curCnt = 1;
            for(int j=el+1; stt.count(j); j++) {
                curCnt++;
            }
            ans = max(ans, curCnt);
        }
    }
    return ans;
}