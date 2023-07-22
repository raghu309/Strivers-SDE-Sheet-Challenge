const long long mod = 1e9+7;

bool isSame(string &s, int l, string &p) {
	int idx = 0;
	while(idx < p.size()) {
		if(s[l++] != p[idx++])
			return false;
	}
	return true;
}

vector<int> stringMatch(string text, string pattern) {
	int n = pattern.size();
	long long patternHsh = 0;
	for(auto &el:pattern) {
		patternHsh = (patternHsh*26 + (el-'a') + mod)%mod;
	}
	if(patternHsh < 0)
		patternHsh += mod;
	int r = 0;
	long long curHsh = 0;
	long long pwr = 1;
	for(r=0; r<pattern.size()-1; r++) {
		pwr = (pwr*26)%mod;
		curHsh = (curHsh*26 + (text[r]-'a') + mod)%mod;
	}
	int l=0;
	vector<int> ans;
	while(r < text.size()) {
		curHsh = (curHsh*26 + (text[r]-'a'))%mod;
		r++;
		if(curHsh == patternHsh && isSame(text, l, pattern)) {
			ans.push_back(l+1);
		}
		curHsh = (curHsh - (pwr*(text[l]-'a')) + mod)%mod;
		l++;
		if(curHsh < 0) {
			curHsh += mod;
		}
	}

	return ans;
}
