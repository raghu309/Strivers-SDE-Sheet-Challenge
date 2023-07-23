#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            if(i == n-1 && j == m-1) continue;
            int down = i+1<n?grid[i+1][j]:1e9;
            int right = j+1<m?grid[i][j+1]:1e9;

            grid[i][j] = grid[i][j]+min(down, right);
        }
    }
    return grid[0][0];
}