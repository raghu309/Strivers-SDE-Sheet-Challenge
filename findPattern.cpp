#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    vector<int> lps(p.size(), 0);
    int prevLPS = 0;
    for(int i=1; i<p.size();) {
        if(p[prevLPS] == p[i]) {
            lps[i] = prevLPS+1;
            prevLPS += 1;
            i++;
        }else if(prevLPS == 0) {
            lps[i] = 0;
            i++;
        }else {
            prevLPS = lps[prevLPS-1];
        }
    }

    int j=0, i=0;
    while(i < s.size()) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }else if(j == 0) {
            i++;
        }else {
            j = lps[j-1];
        }
        if(j == p.size()) {
            return true;
        }
    }
    return false;
}