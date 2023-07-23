#include <bits/stdc++.h>

int gte(vector<int> &v, int b) {
    if(v.size()==0)
        return -1;
    int lo = 0, hi = v.size()-1;
    while(hi-lo > 1) {
        int mid = (lo+hi)/2;

        if(v[mid] <= b) {
            lo = mid;
        }else {
            hi = mid;
        }
    }
    if(v[lo] >= b) {
        return lo;
    }else if(v[hi] >= b) {
        return hi;
    }
    return -1;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> lis;
    for(int i=0; i<n; i++) {
        int cur = arr[i];
        int idx = gte(lis, cur);
        if(idx == -1) {
            lis.push_back(arr[i]);
        }else {
            lis[idx] = arr[i];
        }
    }
    return lis.size();
}
