#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int start = arr[0][0];
    int end = arr[0][1];
    vector<vector<int>> ans;

    for(int i=1; i<n; i++) {
        if(arr[i][0] <= end) {
            end = max(end, arr[i][1]);
        }else {
            ans.push_back({start, end});
            start = arr[i][0];
            end = arr[i][1];
        }
    }
    ans.push_back({start, end});

    return ans;
}
