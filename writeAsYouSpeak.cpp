#include <bits/stdc++.h> 

string getAns(string s) {
	string ans = "";
	char cur = s[0];
	int cnt = 0;
	for(int i=0; i<s.size();) {
		while(s[i]==cur) {
			cnt++;
			i++;
		}
		ans += to_string(cnt);
		ans += cur;
		if(i<s.size())
			cur = s[i];
		cnt = 0;
	}
	return ans;
}

string writeAsYouSpeak(int n) 
{
	string ans = "1";
	for(int k=2; k<=n; k++) {
		ans = getAns(ans);
	}
	return ans;
}