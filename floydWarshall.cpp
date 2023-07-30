

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> grid(n+1, vector<int>(n+1, 1e9));
    for(int i=1; i<=n; i++)
        grid[i][i] = 0;
    for(auto &v:edges) {
        grid[v[0]][v[1]] = v[2];
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(grid[i][k] != 1e9 && grid[k][j] != 1e9)
                grid[i][j] = min(grid[i][j], grid[i][k]+grid[k][j]);
            }
        }
    }
    return grid[src][dest];
}