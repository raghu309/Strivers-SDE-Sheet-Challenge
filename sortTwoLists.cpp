#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first) return second;
    if(!second) return first;

    Node<int> *dummy = new Node<int>(0);
    Node<int> *t = dummy;
    while(first && second) {
        if(first->data < second->data) {
            t->next = first;
            t = first;
            first = first->next;
        }else {
            t->next = second;
            t = second;
            second = second->next;
        }
        t->next = NULL;
    }
    if(first) t->next = first;
    if(second) t->next = second;
    return dummy->next;
}













