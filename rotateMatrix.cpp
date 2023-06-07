#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int l=0, r=m-1, t=0, b=n-1;

    while(l<r && t<b) {
        int prev=0;
        for(int col=l; col<=r; col++) {
            int temp = mat[t][col];
            mat[t][col] = prev;
            prev = temp;
        }
        for(int row=t+1; row<=b; row++) {
            int temp = mat[row][r];
            mat[row][r] = prev;
            prev = temp;
        }
        for(int col=r-1; col>=l; col--) {
            int temp = mat[b][col];
            mat[b][col] = prev;
            prev = temp;
        }
        for(int row=b-1; row>=t; row--) {
            int temp = mat[row][l];
            mat[row][l] = prev;
            prev = temp;
        }
        l++;
        r--;
        t++;
        b--;
    }
}
















