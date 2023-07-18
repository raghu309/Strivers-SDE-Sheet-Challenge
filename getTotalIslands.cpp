int N, M;

int dirx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int diry[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs(int** arr, int i, int j) {
   if(i<0 || j<0 || i>=N || j>=M || arr[i][j] == 0) {
      return;
   }
   arr[i][j] = 0;
   for(int k=0; k<8; k++) {
      bfs(arr, i+dirx[k], j+diry[k]);
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   N = n;
   M = m;
   int ans = 0;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(arr[i][j] == 1) {
            bfs(arr, i, j);
            ans++;
         }
         
      }
   }
   return ans;
}
