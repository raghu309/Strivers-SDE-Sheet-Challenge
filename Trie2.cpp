#include <bits/stdc++.h> 

struct Node {
Node* arr[26];
int count;
int ends;

Node() {
    count = 0;
    ends = 0;
}

bool containsKey(char ch) {
    if(arr[ch-'a'] != NULL) {
        return arr[ch-'a']->count > 0;
    }
    return arr[ch-'a']!=NULL;
}

void set(char ch) {
    arr[ch-'a'] = new Node();
}

Node* get(char ch) {
    return arr[ch-'a'];
}

};

class Trie{
Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                cur->set(ch);
            }
            cur = cur->get(ch);
            cur->count++;
        }
        cur->ends++;
    }

    int countWordsEqualTo(string &word){
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                return 0;
            }
            cur = cur->get(ch);
        }
        return max(0, cur->ends);
    }

    int countWordsStartingWith(string &word){
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                return 0;
            }
            cur = cur->get(ch);
        }
        return max(0, cur->count);
    }

    void erase(string &word){
        Node* cur = root;
        for(auto &ch:word) {
            if(!cur->containsKey(ch)) {
                return;
            }
            cur = cur->get(ch);
            cur->count--;
        }
        cur->ends--;
    }
};







