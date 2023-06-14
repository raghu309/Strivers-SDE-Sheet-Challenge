#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	for(int i=0; i<n; i++) {
		int val = abs(arr[i]);
		if(arr[val] < 0) {
			return val;
		}
		arr[val] *= -1;
	}
	return 0;
}
