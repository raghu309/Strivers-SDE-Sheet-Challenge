#include <bits/stdc++.h>

bool isOpen(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isMatch(char c1, char c2) {
    return (c1=='(' && c2==')') || (c1=='[' && c2==']') || (c1=='{' && c2=='}');
}

bool isValidParenthesis(string s)
{
    stack<char> st;
    for(auto el:s) {
        if(isOpen(el)) {
            st.push(el);
            continue;
        }
        if(st.size() == 0)
            return false;
        
        if(!isMatch(st.top(), el))
            return false;
        st.pop();
    }
    return st.size() == 0;
}