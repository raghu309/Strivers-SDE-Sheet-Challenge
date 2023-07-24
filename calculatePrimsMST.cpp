#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<pair<int, int>>> adj(n+1);

    for(auto pr:g) {
        adj[pr.first.first].push_back({pr.first.second, pr.second});
        adj[pr.first.second].push_back({pr.first.first, pr.second});
    }

    vector<int> vis(n+1, 0);
    vis[1] = 1;
    vector<pair<pair<int, int>, int>> ans;
    for(auto pr:adj[1]) {
        pq.push({pr.second, 1, pr.first});
    }

    while(ans.size() < n-1) {
        int prev = pq.top()[1];
        int cur = pq.top()[2];
        int wt = pq.top()[0];
        pq.pop();
        if(vis[cur])
            continue;
        vis[cur] = 1;
        ans.push_back({{prev, cur}, wt});

        for(auto pr:adj[cur]) {
            if(vis[pr.first])
                continue;
            pq.push({pr.second, cur, pr.first});
        }
    }
    return ans;
}





