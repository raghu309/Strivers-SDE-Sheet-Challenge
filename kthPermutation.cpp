int fact(int x) {
    int ans = 1;
    while(x) {
        ans *= x;
        x--;
    }
    return ans;
}

string kthPermutation(int n, int k) {
    string s = "";
    for(int i=1; i<=n; i++) {
        s += to_string(i);
    }
    k--;
    int cur = fact(n);
    k %= cur;
    

    string ans = "";
    while(k) {
        int block = fact(s.size()-1);
        int idx = k/block;
        ans += s[idx];
        k %= block;
        s = s.erase(idx, 1);
    }
    if(s.size())
        ans += s;
    return ans;
}





