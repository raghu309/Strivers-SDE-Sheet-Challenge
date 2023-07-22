#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<int> indeg(v);
    vector<vector<int>> adj(v);

    for(auto pr:edges) {
        adj[pr[0]].push_back(pr[1]);
        indeg[pr[1]]++;
    }

    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indeg[i] == 0)
            q.push(i);
    }
    while(q.size()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for(auto nxt:adj[cur]) {
            indeg[nxt]--;
            if(indeg[nxt] == 0)
                q.push(nxt);
        }
    }
    return ans;
}