#include <bits/stdc++.h> 

bool check(vector<int> &pos, int players, int minFocus) {
	int prev = pos[0];
	players--;
	for(int i=1; i<pos.size(); i++) {
		if(pos[i]-prev >= minFocus) {
			players--;
			prev = pos[i];
		}
	}
	return players <= 0;
}

int chessTournament(vector<int> pos , int n ,  int c){
	sort(pos.begin(), pos.end());
	int lo = 0;
	int hi = pos[n-1]-pos[0];

	while(hi-lo>1) {
		int mid = (hi+lo)/2;

		if(check(pos, c, mid)) {
			lo = mid;
		}else {
			hi = mid;
		}
	}
	if(check(pos, c, hi)) {
		return hi;
	}else if(check(pos, c, lo)) {
		return lo;
	}
	return 0;
}