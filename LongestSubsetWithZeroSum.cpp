#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  unordered_map<int, int> mpp;
  int curSum = 0;
  mpp[0] = -1;
  int ans = 0;
  for(int i=0; i<arr.size(); i++) {
    curSum += arr[i];

    if(mpp.count(curSum)) {
      ans = max(ans, i-mpp[curSum]);
    }else {
      mpp[curSum] = i;
    }
  }
  return ans;
}