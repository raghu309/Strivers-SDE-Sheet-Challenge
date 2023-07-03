int longestSubSeg(vector<int> &arr , int n, int k){
    int l=0, r=0;
    int zeroUsed = 0;
    int ans = 0;
    while(r < n) {
        r++;
        zeroUsed += (arr[r-1]==0);

        while(zeroUsed > k) {
            if(arr[l]==0) {
                zeroUsed--;
                l++;
            }else {
                l++;
            }
        }
        ans = max(ans, r-l);
    }
    return ans;
}
