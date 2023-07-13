
string reverseString(string &str){
	int n = str.size();
	int l=0, r=0;
	vector<string> vec;
	while(r < n) {
		while(l < n && str[l]==' ')
			l++;
		string t = "";
		r = l;
		while(r<n && str[r]!=' '){
			t += str[r];
			r++;
		}
		l = r;
		if(t != "")
			vec.push_back(t);
	}
	reverse(vec.begin(), vec.end());
	string ans = "";
	for(auto &s:vec) {
		ans += s;
		ans += " ";
	}
	ans.pop_back();
	return ans;
}