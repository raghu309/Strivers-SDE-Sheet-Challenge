#include <bits/stdc++.h> 
static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    double e1 = double(p1.second)/p1.first;
    double e2 = double(p2.second)/p2.first;
    return e1>e2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double ans = 0;
    sort(items.begin(), items.end(), comp);
    for(int i=0; i<n && w; i++) {
        if(w >= items[i].first) {
            ans += items[i].second;
            w -= items[i].first;
        }else {
            ans += (double(items[i].second)/items[i].first)*w;
            w = 0;
        }
    }
    return ans;
}