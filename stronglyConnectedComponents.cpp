#include <bits/stdc++.h>

int dt = 1;

void dfs(vector<vector<int>>& adj, int node, vector<int>& disc, vector<int>& low, vector<bool>& st, vector<int>& ns, vector<vector<int>>& ans) {
    disc[node] = dt;
    low[node] = dt;
    dt++;

    ns.push_back(node);
    st[node] = true;

    for (int v : adj[node]) {
        if (disc[v] == -1) {
            dfs(adj, v, disc, low, st, ns, ans);
            low[node] = min(low[node], low[v]);
        } else if (st[v]) {
            low[node] = min(low[node], disc[v]);
        }
    }

    if (low[node] == disc[node]) {
        vector<int> comp;
        int u = 0;

        while (ns.back() != node) {
            u = ns.back();
            ns.pop_back();
            st[u] = false;
            comp.push_back(u);
        }

        u = ns.back();
        ns.pop_back();
        st[u] = false;
        comp.push_back(u);

        ans.push_back(comp);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<int> ns;
    vector<bool> st(n, false);
    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(adj, i, disc, low, st, ns, ans);
        }
    }

    return ans;
}