#include <bits/stdc++.h> 

bool check(vector<int> &time, long long days, long long t) {
	long long curTime = 0;
	long long curDays = 0;
	for(auto &el:time) {
		if(el > t) {
			return false;
		}
		curTime += el;
		if(curTime > t) {
			curDays++;
			curTime = el;
		}
	}
	if(curTime)
		curDays++;
	return curDays <= days;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long lo=0, hi=2e18;
	while(hi-lo > 1) {
		long long mid = (lo+hi)/2;

		if(check(time, n, mid)) {
			hi = mid;
		}else {
			lo = mid;
		}
	}
	if(check(time, n, lo)) {
		return lo;
	}else if(check(time, n, hi)) {
		return hi;
	}
	return 0;
}