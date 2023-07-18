bool dfs(vector<vector<int>> &adj, int cur, vector<int> &vis, vector<int> &pro) {
  vis[cur] = 1;
  pro[cur] = 1;
  for(auto nxt:adj[cur]) {
    if(vis[nxt])
      return true; 
    if(dfs(adj, nxt, vis, pro))
      return true;  
  }
  vis[cur] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n+1);
  for(auto pr:edges) {
    adj[pr.first].push_back(pr.second);
  }

  vector<int> vis(n+1, 0);
  vector<int> pro(n+1, 0);

  for(int i=1; i<=n; i++) {
    if(pro[i])
      continue;
    if(dfs(adj, i, vis, pro)) {
      return 1;
    }
  }
  return 0;
}










