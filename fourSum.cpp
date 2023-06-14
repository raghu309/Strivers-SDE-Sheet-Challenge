#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int twoSum = arr[i]+arr[j];
            int req = target - twoSum;

            int l=j+1;
            int r=n-1;
            while(l<r) {
                if(arr[l]+arr[r]<req) {
                    l++;
                }else if(arr[l]+arr[r]>req) {
                    r--;
                }else {
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
