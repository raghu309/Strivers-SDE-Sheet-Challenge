#include <bits/stdc++.h> 

bool check(string &s, int idx, string &str) {
    if(s.size()-idx < str.size())
        return false;
    int l=0;
    while(idx < s.size() && l < str.size()) {
        if(s[idx] != str[l])
            return false;
        idx++;
        l++;
    }
    return true;
}

void getAns(string &s, int idx, vector<string> &dict, string &ds, vector<string> &ans) {
    if(idx >= s.size()) {
        ans.push_back(ds);
        return;
    }
    for(auto &str:dict) {
        if(check(s, idx, str)) {
            if(idx != 0)
                ds += " ";
            ds += str;
            getAns(s, idx+str.size(), dict, ds, ans);
            while(ds.size() && ds.back() != ' ')
                ds.pop_back();
            if(ds.size())
                ds.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dict)
{
    unordered_set<string> stt;
    for(auto &str:dict)
        stt.insert(str);
    vector<string> d;
    for(auto &str:stt)
        d.push_back(str);
    vector<string> ans;
    string ds = "";
    getAns(s, 0, d, ds, ans);
    return ans;
}