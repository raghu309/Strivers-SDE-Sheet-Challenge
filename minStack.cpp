#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<pair<int, int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(st.size() == 0) {
				st.push({num, num});
			}else {
				st.push({num, min(num, st.top().second)});
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.size() == 0)
				return -1;
			int rv = st.top().first;
			st.pop();
			return rv;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.size() == 0)
				return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.size() == 0)
				return -1;
			return st.top().second;
		}
};