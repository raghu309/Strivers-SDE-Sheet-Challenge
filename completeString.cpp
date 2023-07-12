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

    void insert(string &s) {
        Node* cur = root;
        for(auto &ch:s) {
            if(!cur->containsKey(ch)) {
                cur->set(ch);
            }
            cur = cur->get(ch);
        }
        cur->flag = true;
    }

    bool check(string &s) {
        Node* cur = root;
        for(auto &ch:s) {
            if(!cur->containsKey(ch)) {
                return false;
            }
            cur = cur->get(ch);
            if(!cur->flag)
                return false;
        }
        return cur->flag;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;
    for(auto &str:a) {
        t.insert(str);
    }
    string ans = "";
    for(auto &str:a) {
        if(str.size() < ans.size() || !t.check(str))
            continue;
        if(str.size() >= ans.size()) {
            ans = str;
        }else if(str.size() == ans.size() && str < ans) {
            ans = str;
        }
    }
    return ans==""?"None":ans;
}












