#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int ans = 0;
    int l=0, r=0;
    unordered_set<int> stt;
    while(r < s.size()) {
        if(stt.count(s[r])) {
            while(stt.count(s[r])) {
                stt.erase(s[l]);
                l++;
            }
        }
        stt.insert(s[r]);
        r++;
        ans = max(ans, r-l);
    }
    return ans;
}