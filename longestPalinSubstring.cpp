string longestPalinSubstring(string str)
{
    string ans = "";
    for(int i=0; i<str.size(); i++) {
        int l=i;
        int r=i;
        while(l>=0 && r<str.size() && str[l]==str[r]) {
            if(r-l+1 > ans.size()) {
                ans = str.substr(l, r-l+1);
            }
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<str.size() && str[l]==str[r]) {
            if(r-l+1 > ans.size()) {
                ans = str.substr(l, r-l+1);
            }
            l--;
            r++;
        }
    }
    return ans;
}