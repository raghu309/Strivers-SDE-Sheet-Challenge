#include <bits/stdc++.h>

void dfs(vector<vector<int>> &adj, int cur, int prev, vector<int> &vis, vector<int> &ans) {
    vis[cur] = 1;
    ans.push_back(cur);

    for(auto nxt:adj[cur]) {
        if(vis[nxt])
            continue;
        dfs(adj, nxt, cur, vis, ans);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(auto &pr:edges) {
        adj[pr[0]].push_back(pr[1]);
        adj[pr[1]].push_back(pr[0]);
    }

    vector<vector<int>> ans;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++) {
        if(vis[i])
            continue;
        vector<int> t;
        dfs(adj, i, -1, vis, t);
        ans.push_back(t);
    }
    return ans;
}