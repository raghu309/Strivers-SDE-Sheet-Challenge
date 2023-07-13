#include <bits/stdc++.h> 

struct Node {
    int val;
    Node* next;
    
    Node(int v) {
        val = v;
    }
};

class Queue {
Node* head;
Node* tail;
public:
    Queue() {
        head = tail = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int data) {
        Node* nn = new Node(data);
        if(head == NULL)
            head = tail = nn;
        else {
            tail->next = nn;
            tail = nn;
        }
    }

    int dequeue() {
        if(!head)
            return -1;
        Node* t = head;
        int rv = head->val;
        head = head->next;
        t->next = NULL;
        if(!head)
            tail = NULL;
        delete t;
        return rv;
    }

    int front() {
        if(!head) {
            return -1;
        }
        return head->val;
    }
};