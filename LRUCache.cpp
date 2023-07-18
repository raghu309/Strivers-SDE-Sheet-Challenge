#include <bits/stdc++.h>

struct Node {
    int key, val;
    Node *next, *prev;

    Node(int k, int v) {
        key = k;
        val = v;
    }
};

class LRUCache
{
Node *head, *tail;
int cap;

public:
unordered_map<int, Node*> mpp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void insertFront(Node *t) {
        t->next = head->next;
        t->prev = head;
        head->next = t;
        t->next->prev = t;
    }

    void remove(Node *t) {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        t->next = t->prev = NULL;
    }

    int get(int key)
    {
        if(mpp.count(key)==0) {
            return -1;
        } 
        remove(mpp[key]);
        insertFront(mpp[key]);
        return mpp[key]->val;
    }



    void put(int key, int value)
    {
        if(mpp.count(key)) {
            remove(mpp[key]);
        }
        mpp[key] = new Node(key, value);
        insertFront(mpp[key]);
        if(mpp.size() > cap) {
            mpp.erase(tail->prev->key);
            Node *t = tail->prev;
            remove(tail->prev);
            delete t;
        }
    }
};
