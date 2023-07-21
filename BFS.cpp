#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj(vertex);
    for(auto &pr:edges) {
        adj[pr.first].push_back(pr.second);
        adj[pr.second].push_back(pr.first);
    }
    for(auto &v:adj) {
        sort(v.begin(), v.end());
    }

    queue<int> q;
    
    vector<int> vis(vertex, 0);
    vector<int> ans;
    for(int i=0; i<vertex; i++) {
    if(vis[i])
        continue;
    q.push(i);
    vis[i] = 1;
    while(q.size()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(auto &nxt:adj[cur]) {
            if(vis[nxt])
                continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }
    }
    
    return ans;
}