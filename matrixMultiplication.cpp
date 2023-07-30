#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    int dp[N][N];
    for(int i=0; i<N; i++)
        dp[i][i] = 0;

    for(int i=N-1; i>=1; i--) {
        for(int j=i+1; j<N; j++) {
            int curAns = 1e9;
            for(int k=i; k<j; k++) {
                curAns = min(curAns, arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
            }
            dp[i][j] = curAns;
        }
    }
    return dp[1][N-1];
}