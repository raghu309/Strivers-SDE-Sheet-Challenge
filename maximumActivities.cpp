#include <bits/stdc++.h>

static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second < p2.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> data;
    for(int i=0; i<start.size(); i++) {
        data.push_back({start[i], finish[i]});
    }
    sort(data.begin(), data.end(), comp);

    int prev = -1;
    int ans = 0;

    for(auto pr:data) {
        if(pr.first >= prev) {
            ans++;
            prev = pr.second;
        }
    }
    return ans;
}