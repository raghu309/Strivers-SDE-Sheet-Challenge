class Queue {
    stack<int> st1;
    stack<int> st2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        st1.push(val);
    }

    int deQueue() {
        if(isEmpty())
            return -1;
        if(st2.size()==0) {
            while(st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int rv = st2.top();
        st2.pop();
        return rv;
    }

    int peek() {
        if(isEmpty())
            return -1;
        if(st2.size()==0) {
            while(st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool isEmpty() {
        return st1.size() + st2.size() == 0;
    }
};