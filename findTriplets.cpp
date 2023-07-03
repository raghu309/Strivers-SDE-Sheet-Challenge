#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(), arr.end());
	int i=0;
	vector<vector<int>> ans;
	while(i<n) {
		int l=i+1;
		int r=n-1;

		int reqSum = K - arr[i];
		while(l < r) {
			if(arr[l]+arr[r]>reqSum) {
				r--;
			}else if(arr[l]+arr[r]<reqSum) {
				l++;
			}else {
				ans.push_back({arr[i], arr[l], arr[r]});
				l++;
				while(l<r && arr[l]==arr[l-1])
					l++;
			}
		}
		i++;
		while(i<n && arr[i]==arr[i-1])
			i++;
	}
	return ans;
}