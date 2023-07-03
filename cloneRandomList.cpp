#include <bits/stdc++.h>

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    map<LinkedListNode<int>*, LinkedListNode<int>*> mpp;
    LinkedListNode<int>* cur = head;

    while(cur) {
        LinkedListNode<int>* nn = new LinkedListNode<int>(cur->data);
        mpp[cur] = nn;
        cur = cur->next;
    }
    cur = head;

    while(cur) {
        mpp[cur]->next = mpp[cur->next];
        mpp[cur]->random = mpp[cur->random];
        cur = cur->next;
    }

    return mpp[head];
}




