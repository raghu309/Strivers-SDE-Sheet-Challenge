#include <bits/stdc++.h> 

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

void getAns(vector<vector<int>> &maze, int i, int j, vector<vector<int>> &vis, vector<vector<int>> &ans) {
  if(i == maze.size()-1 && j == maze[0].size()-1) {
    vector<int> t;
    for(auto &v:vis) {
      for(auto &el:v) {
        t.push_back(el);
      }
    }
    ans.push_back(t);
    return;
  }

  for(int k=0; k<4; k++) {
    int di = i+dirx[k];
    int dj = j+diry[k];
    if(di<0 || di>=maze.size() || dj<0 || dj>=maze[0].size() || vis[di][dj] || !maze[di][dj])
      continue;
    vis[di][dj] = 1;
    getAns(maze, di, dj, vis, ans);
    vis[di][dj] = 0;
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  if(maze[0][0]==0)
    return {};
  vector<vector<int>> vis(maze.size(), vector<int>(maze[0].size(), 0));
  vector<vector<int>> ans;
  vis[0][0] = 1;
  getAns(maze, 0, 0, vis, ans);
  return ans;
}





