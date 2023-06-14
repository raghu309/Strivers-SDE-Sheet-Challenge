#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int el = -1;
	int cnt = 0;

	for(int i=0; i<n; i++) {
		if(cnt == 0) {
			el = arr[i];
		}
		if(arr[i]==el) {
			cnt++;
		}else {
			cnt--;
		}
	}
	int actualCnt = 0;
	for(int i=0; i<n; i++) 
		actualCnt += (el == arr[i]);
	return actualCnt>(n/2)?el:-1;
}