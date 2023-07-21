#include <bits/stdc++.h> 

struct Node {
    int key;
    int val;
    int cnt;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        cnt = 1;
    }
};

struct List {
Node *head, *tail;
int size;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = NULL;
        size--;
    }
};

class LFUCache
{
unordered_map<int, Node*> keyNode;
unordered_map<int, List*> freqList;
int maxSize;
int curSize;
int minFreq;

public:
    LFUCache(int capacity)
    {
        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node* t) {
        freqList[t->cnt]->removeNode(t);
        if(freqList[t->cnt] == 0 && t->cnt == minFreq) {
            minFreq++;
        }
        t->cnt+=1;
        if(freqList.count(t->cnt) == 0) {
            freqList[t->cnt] = new List();
        }
        freqList[t->cnt]->addFront(t);
    }

    int get(int key)
    {
        if(!keyNode.count(key)) {
            return -1;
        }
        Node* t = keyNode[key];
        int val = t->val;
        updateFreq(t);
        return val;
    }

    void put(int key, int value)
    {
        if(maxSize == 0)
            return;
        if(keyNode.count(key)) {
            Node *t = keyNode[key];
            t->val = value;
            updateFreq(t);
        }else {
            if(curSize == maxSize) {
                List *l = freqList[minFreq];
                keyNode.erase(l->tail->prev->key);
                l->removeNode(l->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            if(freqList.count(minFreq) == 0) {
                freqList[minFreq] = new List();
            }
            Node* nn = new Node(key, value);
            freqList[minFreq]->addFront(nn);
            keyNode[key] = nn;
        }
    }
};
