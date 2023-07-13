class Stack {
	queue<int> q1;
    queue<int> q2;

   public:
    Stack() {

    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size()+q2.size();
    }

    bool isEmpty() {
        return q1.size()+q2.size() == 0;
    }

    void push(int element) {
        q1.push(element);
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
        int rv = q1.front();
        q1.pop();
        swap(q1, q2);
        return rv;
    }

    int top() {
        if(isEmpty()) {
            return -1;
        }
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
        int rv = q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
        return rv;
    }
};




