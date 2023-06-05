#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long>> ans = {{1}};
  for(int i=1; i<n; i++) {
    vector<long long> t(i+1, 1);
    for(int j=1; j<t.size()-1; j++) {
      t[j] = ans[i-1][j-1] + ans[i-1][j];
    }
    ans.push_back(t);
  }
  return ans;
}
