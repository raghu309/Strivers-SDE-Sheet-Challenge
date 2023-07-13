#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> ans(n, 0);
    for(int i=n-1; i>=0; i--) {
        while(st.size() && st.top() <= arr[i]) {
            st.pop();
        }
        ans[i] = st.size()>0?st.top():-1;
        st.push(arr[i]);
    }
    return ans;
}