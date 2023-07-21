#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> pgi(n, 0);
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(st.size() && price[st.top()] <= price[i]) {
            st.pop();
        }
        pgi[i] = st.size()>0?st.top():-1;
        st.push(i);
    }
    vector<int> ans(n, 1);
    for(int i=0; i<n; i++) {
        if(pgi[i] == -1) {
            ans[i] = i+1;
            continue;
        }
        ans[i] = i-pgi[i];
    }
    return ans;
}