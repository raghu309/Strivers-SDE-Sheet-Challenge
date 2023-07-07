#include <bits/stdc++.h>
static bool comp(vector<int> &v1, vector<int> &v2) {
    return v1[1]>v2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comp);
    vector<int> hsh(3001, 0);
    hsh[0] = 1;

    for(auto v:jobs) {
        int idx = v[0];
        while(idx>0 && hsh[idx]>0) {
            idx--;
        }
        hsh[idx] = v[1];
    }
    hsh[0] = 0;
    return accumulate(hsh.begin(), hsh.end(), 0);
}
