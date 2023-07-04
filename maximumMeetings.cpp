#include <bits/stdc++.h> 
static bool comp(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1])
        return v1[2] < v2[2];
    return v1[1] < v2[1];
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<vector<int>> data;
    for(int i=0; i<n; i++) {
        data.push_back({start[i], end[i], i+1});
    }

    sort(data.begin(), data.end(), comp);
    int prev = -1;
    vector<int> ans;

    for(auto &pr:data) {
        if(pr[0] > prev) {
            prev = pr[1];
            ans.push_back(pr[2]);
        }
    }
    return ans;
}