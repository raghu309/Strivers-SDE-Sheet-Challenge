#include <bits/stdc++.h> 

LinkedListNode<int>* rev(LinkedListNode<int>* head) {
    LinkedListNode<int> *p = NULL, *q = head, *r = head->next;
    while(q) {
        q->next = p;
        p = q;
        q = r;
        r = r?r->next:r;
    }
    return p;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next) return true;
    LinkedListNode<int> *s = head;
    LinkedListNode<int> *f = head;
    LinkedListNode<int> *p = head;
    while(f && f->next) {
        p = s;
        s = s->next;
        f = f->next;
        f = f->next;
    }
    p->next = NULL;
    s = rev(s);
    f = s;
    p = head;
    bool flag = true;
    while(s && p) {
        if(s->data != p->data) {
            flag = false;
            break;
        }
        s = s->next;
        p = p->next;
    }
    f = rev(f);
    s = head;
    while(s->next)
        s = s->next;
    s->next = f;
    return flag;
}