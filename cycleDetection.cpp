#include <bits/stdc++.h>

bool hasCycle(vector<vector<int>> &adj, int cur, int prev, vector<int> &vis) {
    vis[cur] = 1;
    for(auto &nxt:adj[cur]) {
        if(nxt == prev)
            continue;
        if(vis[nxt])
            return true;
        if(hasCycle(adj, nxt, cur, vis))
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> vis(n+1, 0);
    vector<vector<int>> adj(n+1);

    for(auto pr:edges) {
        adj[pr[0]].push_back(pr[1]);
        adj[pr[1]].push_back(pr[0]);
    }

    for(int i=1; i<=n; i++) {
        if(vis[i])
            continue;
        if(hasCycle(adj, i, -1, vis))
            return "Yes";
    }
    return "No";
}

