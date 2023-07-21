#include <bits/stdc++.h>

struct Node {
	Node* arr[2];

	bool containsKey(int bit) {
		return arr[bit] != NULL;
	}

	void set(int bit) {
		arr[bit] = new Node();
	}

	Node* get(int bit) {
		return arr[bit];
	}
};

class Trie {
	Node* root;

public:
	Trie() {
		root = new Node();
	}

	void insert(long num) {
		Node* cur = root;
		for(int i=32; i>=0; i--) {
			int bit = (num>>i)&1;
			if(!cur->containsKey(bit)) {
				cur->set(bit);
			}
			cur = cur->get(bit);
		}
	}

	long getAns(long num) {
		Node* cur = root;
		long ans = 0;
		for(int i=32; i>=0; i--) {
			int bit = (num>>i)&1;
			if(cur->containsKey(bit^1)) {
				ans += pow(2, i);
				cur = cur->get(bit^1);
			}else {
				cur = cur->get(bit);
			}
		}
		return ans;
	}
};

static bool comp(vector<int> &v1, vector<int> &v2) {
	return v1[1]<v2[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie t;
	sort(arr.begin(), arr.end());

	int idx = 0;
	for(int i=0; i<queries.size(); i++) {
		queries[i].push_back(i);
	}
	sort(queries.begin(), queries.end(), comp);

	vector<int> ans(queries.size());
	for(auto &pr:queries) {
		long bound = pr[1];
		long el = pr[0];
		long i = pr[2];

		while(idx < arr.size() && arr[idx] <= bound) {
			t.insert(arr[idx++]);
		}
		if(idx == 0) {
			ans[i] = -1;
		}else {
			ans[i] = t.getAns(el);
		}
	}
	return ans;
}












