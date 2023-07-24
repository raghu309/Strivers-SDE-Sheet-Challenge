#include <bits/stdc++.h> 

static bool comp(vector<int> &v1, vector<int> &v2) {
	return v1[2] < v2[2];
}

int par[10001];

int Find(int a) {
	if(par[a] == a)
		return a;
	return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if(a != b) {
		par[b] = a;
	}
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(), graph.end(), comp); 
	for(int i=1; i<=n; i++)
		par[i] = i;
	int mstSum = 0;

	for(auto vec:graph) {
		int u = Find(vec[0]);
		int v = Find(vec[1]);
		if(u == v)
			continue;
		mstSum += vec[2];
		Union(u, v);
	}
	return mstSum;
}
















