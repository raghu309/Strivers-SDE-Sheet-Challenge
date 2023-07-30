#include <bits/stdc++.h> 

struct Node {
    int height;
    int leftIdx;
    int rightIdx;

    Node(int h, int li, int ri) {
        height = h;
        leftIdx = li;
        rightIdx = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N) {
    int ans = 0;
    queue<Node> q;

    if (N >= 1) {
        Node node(0, 0, N - 1);
        q.push(node);
    }
    unordered_map<int, int> map;
    for (int i = 0; i < N; i++) {
        map[inorder[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        Node node = q.front();
        q.pop();

        ans = max(node.height, ans);

        int li = node.leftIdx;
        int ri = node.rightIdx;
        int rootIndex;

        rootIndex = map[levelOrder[i]];

        if (rootIndex - 1 >= li) {
            Node leftSubTree(node.height + 1, li, rootIndex - 1);
            q.push(leftSubTree);
        }

        if (rootIndex + 1 <= ri) {
            Node rightSubTree(node.height + 1, rootIndex + 1, ri);
            q.push(rightSubTree);
        }
    }

    return ans;
}