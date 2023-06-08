#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int k = arr1.size()-1;
	int i = m-1;
	int j = n-1;

	while(i>=0 || j>=0) {
		int val1 = i>=0?arr1[i]:INT_MIN;
		int val2 = j>=0?arr2[j]:INT_MIN;

		if(val1 > val2) {
			arr1[k--] = arr1[i--];
		}else {
			arr1[k--] = arr2[j--];
		}
	}

	return arr1;
}