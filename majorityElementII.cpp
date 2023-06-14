#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int el1 = -1;
    int cnt1 = 0;
    int el2 = -1;
    int cnt2 = 0;

    for(int i=0; i<n; i++) {
        if(cnt1 == 0 && el2 != arr[i]) {
            el1 = arr[i];
        }
        if(cnt2 == 0 && el1 != arr[i]) {
            el2 = arr[i];
        }
        if(arr[i] == el1) {
            cnt1++;
        }else if(arr[i] == el2) {
            cnt2++;
        }else {
            cnt1--;
            cnt2--;
        }
    }

    int c1 = 0, c2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == el1) {
            c1++;
        }else if(arr[i] == el2) {
            c2++;
        }
    }
    vector<int> ans;
    if(c1 > arr.size()/3) {
        ans.push_back(el1);
    }
    if(c2 > arr.size()/3) {
        ans.push_back(el2);
    }
    return ans;
}












