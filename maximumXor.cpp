#include <bits/stdc++.h> 

struct Node {
    Node* arr[2];

    bool containsKey(int bit) {
        return arr[bit] != NULL;
    }

    void set(int bit) {
        arr[bit] = new Node();
    }

    Node* get(int bit) {
        return arr[bit];
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(long num) {
        Node* cur = root;

        for(int i=32; i>=0; i--) {
            int bit = (num>>i)&1;
            if(!cur->containsKey(bit)) {
                cur->set(bit);
            }
            cur = cur->get(bit);
        }
    }

    long getAns(long num) {
        Node* cur = root;
        long ans = 0;
        for(int i=32; i>=0; i--) {
            int bit = (num>>i)&1;
            if(cur->containsKey(bit^1)) {
                ans = ans + pow(2, i);
                cur = cur->get(bit^1);
            }else {
                cur = cur->get(bit);
            }
        }
        return ans;
    }
};

int maximumXor(vector<int> A)
{
    Trie t;
    for(auto &el:A) {
        t.insert(el);
    }
    long ans = 0;
    for(auto &el:A) {
        ans = max(ans, t.getAns(el));
    }
    return ans;
}