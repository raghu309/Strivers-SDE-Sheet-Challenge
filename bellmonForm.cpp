#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    for(int i=0; i<n-1; i++) {
        for(auto &v:edges) {
            int f=v[0];
            int t=v[1];
            int wt=v[2];
            if(dist[f] != 1e9 && dist[f]+wt < dist[t]) {
                dist[t] = dist[f] + wt;
            }
        }
    }

    // for(auto v:edges) {
    //     int f=v[0];
    //     int t=v[1];
    //     int wt=v[2];
    //     if(dist[f]+wt < dist[t]) {
    //         dist[t] = dist[f] + wt;
    //     }
    // }
    return dist[dest];
}