
bool isPalindrome(string &s, int l, int r){
    while(l<=r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int minCharsforPalindrome(string str) {
	int n = str.size()-1;
    int ans = -1;
    for(int i=0;i<=n;i++){
        int r = n-i;
        int l = 0;
        if(isPalindrome(str, l, r)){
            ans = i;
            break;
        }
    }
    return ans;
}
