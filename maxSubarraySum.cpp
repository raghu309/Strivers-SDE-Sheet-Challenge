#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans = 0;
    long long curSum = 0;

    for(int i=0; i<n; i++) {
        curSum += arr[i];
        ans = max(curSum, ans);
        if(curSum < 0)
            curSum = 0;
    }

    return ans;
}