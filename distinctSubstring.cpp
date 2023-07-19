#include <bits/stdc++.h> 

struct Node {
    Node* arr[26];
    bool flag = false;

    bool containsKey(char ch) {
        return arr[ch-'a'] != NULL;
    }

    void set(char ch) {
        arr[ch-'a'] = new Node();
    }

    Node* get(char ch) {
        return arr[ch-'a'];
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &s, int i) {
        Node* cur = root;
        for(; i<s.size(); i++) {
            char ch = s[i];
            if(!cur->containsKey(ch)) {
                cur->set(ch);
            }
            cur = cur->get(ch);
        }
        cur->flag = true;
    }

    int dfs(Node* t) {
        int ans = 1;
        for(int i=0; i<26; i++) {
            if(t->containsKey(i+'a')) {
                ans += dfs(t->get(i+'a'));
            }
        }
        return max(ans, 1);
    }

    int getAns() {
        return dfs(root);
    }
};



int distinctSubstring(string &word) {
    Trie t;
    for(int i=0; i<word.size(); i++) {
        t.insert(word, i);
    }
    return t.getAns()-1;
}
