#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int ans = *max_element(arr.begin(), arr.end());
	int maxProd = 1;
	int minProd = 1;

	for(auto el:arr) {
		if(el == 0) {
			maxProd = 1;
			minProd = 1;
			continue;
		}
		int temp = maxProd*el;
		maxProd = max({el, el*minProd, el*maxProd});
		minProd = min({el, el*minProd, temp});
		ans = max(ans, maxProd);
	}
	return ans;
}
