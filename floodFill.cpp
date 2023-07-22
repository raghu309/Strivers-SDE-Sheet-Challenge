#include <bits/stdc++.h>

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int color = image[x][y];
    if(color == newColor)
        return image;
    queue<pair<int, int>> q;
    image[x][y] = newColor;
    q.push({x, y});

    while(q.size()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int du = u + dirx[i];
            int dv = v + diry[i];

            if(du<0 || dv<0 || du>=image.size() || dv>=image[0].size() || image[du][dv] != color)
                continue;
            image[du][dv] = newColor;
            q.push({du, dv});
        }
    }
    return image;
}



