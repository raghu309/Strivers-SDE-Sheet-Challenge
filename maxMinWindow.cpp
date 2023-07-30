#include <bits/stdc++.h> 

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> pgi(n);
    vector<int> ngi(n);
    stack<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty() && a[q.top()]>=a[i]){
            q.pop();
        }
        pgi[i] = q.empty()?-1:q.top();
        q.push(i);
    }
    while(!q.empty())q.pop();
    for(int i=n-1;i>=0;i--){
        while(!q.empty() && a[q.top()]>=a[i]){
            q.pop();
        }
        ngi[i] = q.empty()?n:q.top();
        q.push(i);
    }
    vector<int> ans(n, INT_MIN);
    for(int i=0;i<n;i++){
        int l = pgi[i]+1;
        int r = ngi[i]-1;
        ans[r-l] = ans[r-l]<a[i]?a[i]:ans[r-l];
    }
    for(int i=n-2;i>=0;i--){
        ans[i] = max(ans[i], ans[i+1]);
    }
    return ans;
}