#include <bits/stdc++.h>

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int fresh = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
            if(grid[i][j] == 1)
                fresh++;
        }
    }
    int ans = 0;
    while(q.size()) {
        int sz = q.size();
        bool f = false;

        for(int j=0; j<sz; j++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int dx = x + dirx[i];
                int dy = y + diry[i];

                if(dx<0 || dy<0 || dx>=n || dy>=m || grid[dx][dy] != 1)
                    continue;
                f = true;
                grid[dx][dy] = 2;
                fresh--;
                q.push({dx, dy});
            }
        }
        ans += f;
    }
    return fresh==0?ans:-1;
}




