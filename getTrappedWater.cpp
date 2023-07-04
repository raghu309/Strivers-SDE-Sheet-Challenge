#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> pre(arr, arr+n);
    vector<long> suf(arr, arr+n);

    for(int i=1; i<n; i++)
        pre[i] = max(pre[i], pre[i-1]);
    for(int i=n-2; i>=0; i--)
        suf[i] = max(suf[i], suf[i+1]);
    
    long long ans = 0;
    for(int i=1; i<n-1; i++) {
        ans += max(0l ,min(pre[i], suf[i])-arr[i]);
    }
    return ans;
}