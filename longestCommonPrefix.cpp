string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    bool f = true;
    for(int i=0; i<arr[0].size(); i++) {
        char cur = arr[0][i];
        
        for(int j=0; j<n && f; j++) {
            if(i>=arr[j].size() || arr[j][i] != cur) {
                f = false;
                break;
            }
        }
        if(f)
        ans += cur;
    }
    return ans;
}


