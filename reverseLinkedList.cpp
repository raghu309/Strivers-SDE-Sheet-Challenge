#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *p, *q, *r;
    p = NULL;
    q = head;
    r = head?head->next:head;
    while(q) {
        q->next = p;
        p = q;
        q = r;
        r = r?r->next:r;
    }
    return p;
}















