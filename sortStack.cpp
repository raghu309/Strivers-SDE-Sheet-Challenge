#include <bits/stdc++.h> 

void sortedInsert(stack<int> &st, int val) {
	if(st.size()==0 || val >= st.top()) {
		st.push(val);
		return;
	}
	int cur = st.top();
	st.pop();
	sortedInsert(st, val);
	st.push(cur);
}

void sortStack(stack<int> &st)
{
	if(st.size() == 0)
		return;
	int cur = st.top();
	st.pop();
	sortStack(st);
	sortedInsert(st, cur);
}