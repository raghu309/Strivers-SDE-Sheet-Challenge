/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node {
    Node* arr[26];

public:
    bool flag = false;
    bool containsKey(char ch) {
        return arr[ch-'a'];
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

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        root->flag = true;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                cur->set(ch);
            }
            cur = cur->get(ch);
        }
        cur->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                return false;
            }
            cur = cur->get(ch);
        }
        return cur->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                return false;
            }
            cur = cur->get(ch);
        }
        return true;
    }
};