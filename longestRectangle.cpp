 #include <bits/stdc++.h>
 
 int largestRectangle(vector < int > & v) {
   vector<int> h(v);
   h.push_back(-1);
   reverse(h.begin(), h.end());
   h.push_back(-1);
   reverse(h.begin(), h.end());

   int n = h.size();
   vector<int> lsi(n);
   vector<int> rsi(n);

   stack<int> st;
   for(int i=0; i<n; i++) {
     while(st.size() && h[st.top()] >= h[i]) {
       st.pop();
     }
     if(st.size()) {
       lsi[i] = st.top();
     }else {
       lsi[i] = -1;
     }
     st.push(i);
   }
   while(st.size()) st.pop();

   for(int i=n-1; i>=0; i--) {
     while(st.size() && h[st.top()] >= h[i]) {
       st.pop();
     }
     if(st.size()) {
       rsi[i] = st.top();
     }else {
       rsi[i] = -1;
     }
     st.push(i);
   }
  int ans = 0;
   for(int i=1; i<n-1; i++) {
     int curAns = (rsi[i] - lsi[i] - 1)*h[i];
     ans = max(ans, curAns);
   }
   return ans;
 }