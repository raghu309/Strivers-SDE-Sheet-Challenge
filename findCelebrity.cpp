#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> st;
	for(int i=0; i<n; i++)
		st.push(i);

	while(st.size()>1) {
		int cur = st.top();
		st.pop();
		
		if(knows(cur, st.top())) {
			continue;
		}else {
			st.pop();
			st.push(cur);
		}
	}
	int ans = st.top();
	for(int i=0; i<n; i++) {
		if(i == ans)
			continue;
		if(knows(ans, i))
			return -1;
		if(!knows(i, ans))
			return -1;
	}
	return ans;
}