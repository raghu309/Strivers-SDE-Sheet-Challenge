#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto &v:vec) {
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
    }
    vector<int> dist(n, INT_MAX);
    vector<int> vis(n, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while(pq.size()) {
        int cur = pq.top().second;
        int curWt = pq.top().first;
        pq.pop();

        if(vis[cur])
            continue;
        vis[cur] = 1;
        for(auto &pr:adj[cur]) {
            int nxt = pr.first;
            int wt = pr.second;

            if(vis[nxt])
                continue;
            if(curWt+wt < dist[nxt]) {
                dist[nxt] = curWt+wt;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}






