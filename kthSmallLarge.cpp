#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(), arr.end());
	int el1 = *(arr.begin()+k-1);
	int el2 = *(arr.end()-k);
	return {el1, el2};
}