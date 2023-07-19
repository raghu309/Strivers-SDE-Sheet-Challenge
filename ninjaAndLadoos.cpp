#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m > n) {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
    int l = max(0, k-n);
    int h = min(k, n);

    while(l <= h) {
        int c1 = (l+h)/2;
        int c2 = k - c1;

        int l1 = c1==0?INT_MIN:row1[c1-1];
        int l2 = c2==0?INT_MIN:row2[c2-1];
        int r1 = c1==m?INT_MAX:row1[c1];
        int r2 = c2==n?INT_MAX:row2[c2];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }else if(l1 > r2){
            h = c1-1;
        }else {
            l = c1+1;
        }
    }
    return 1;
}