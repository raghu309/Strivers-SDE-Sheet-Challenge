#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());

	priority_queue<vector<int>> pq;
	pq.push({a[0]+b[0], 0, 0});
	set<pair<int, int>> stt;
	stt.insert({0, 0});
	vector<int> ans;
	while(ans.size() < k) {
		auto v = pq.top(); pq.pop();
		ans.push_back(v[0]);
		int x = v[1];
		int y = v[2];

		if(x+1 < a.size() && !stt.count({x+1, y})) {
			pq.push({a[x+1]+b[y], x+1, y});
			stt.insert({x+1, y});
		}
		if(y+1 < b.size() && !stt.count({x, y+1})) {
			pq.push({a[x]+b[y+1], x, y+1});
			stt.insert({x, y+1});
		}
	}
	return ans;
}