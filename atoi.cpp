#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;
    for(auto &ch:str) {
        if(ch >= '0' && ch <= '9') {
            ans = ans*10 + (ch-'0');
        }
    }
    if(str[0] == '-') {
        ans *= -1;
    }
    return ans;
}