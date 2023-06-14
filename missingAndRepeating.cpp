#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int v1 = accumulate(arr.begin(), arr.end(), 0) - (n)*(n+1)/2;
	int v2 = 0;
	for(int i=0; i<n; i++) {
		v2 += arr[i]*arr[i];
		v2 -= (i+1)*(i+1);
	}

	int ans1 = (v2+v1*v1)/(2*v1);
	int ans2 = ans1 - v1;
	pair<int, int> p;
	for(int i=0; i<n; i++) {
		if(arr[i] == ans1) {
			p = {ans2, ans1};
			break;
		}
		if(arr[i] == ans2) {
			p = {ans1, ans2};
			break;
		}
	}
	return p;
}
