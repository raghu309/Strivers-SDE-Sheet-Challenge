#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int arr[1005];
    int t;
    int cap;
public:
    
    Stack(int capacity) {
        cap = capacity;
        t = -1;
    }

    void push(int num) {
        if(t == cap-1)
            return;
        arr[++t] = num;
    }

    int pop() {
        if(t == -1)
            return -1;
        int rv = arr[t--];
        return rv;
    }
    
    int top() {
        return t==-1?-1:arr[t];
    }
    
    int isEmpty() {
        return t==-1;
    }
    
    int isFull() {
        return t==cap-1;
    }
    
};