#include <bits/stdc++.h> 
int compare(string &s1, string &s2) {
    if(s1.size()>s2.size())
        return 1;
    if(s2.size()>s1.size())
        return -1;
    for(int i=0; i<s1.size(); i++) {
        if(s1[i] > s2[i]) {
            return 1;
        }
        if(s2[i] > s1[i]) {
            return -1;
        }
    }
    return 0;
}

int compareVersions(string a, string b) 
{
    int i=0, j=0;
    while(i < a.size() || j < b.size()) {
        string v1 = "";
        while(i<a.size() && a[i] !='.') {
            v1 += a[i];
            i++;
        }
        i++;
        if(v1=="0")v1 = "";
        string v2 = "";
        while(j<b.size() && b[j] != '.') {
            v2 += b[j];
            j++;
        }
        j++;
        if(v2 == "0")v2 = "";

        int curAns = compare(v1, v2);
        if(curAns == 0)
            continue;
        return curAns;
    }
    return 0;
}