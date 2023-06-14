#include <bits/stdc++.h>

long long pwr(long long X, long long N, long long M) {
	long long ans = 1;

	while(N) {
		if(N%2 == 0) {
			X = (X*X)%M;
			N /= 2;
		}else {
			ans = (ans*X)%M;
			N--;
		}
	}
	return ans;
}

int modularExponentiation(int x, int n, int m) {
	return pwr(x, n, m);
}