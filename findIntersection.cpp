Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node *n1, *n2;
    n1 = firstHead;
    n2 = secondHead;

    while(n1 && n2 && n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
        if(!n1) n1 = secondHead;
        if(!n2) n2 = firstHead;
    }
    return n1;
}
