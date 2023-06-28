

Node *firstNode(Node *head)
{
    if(!head || !head->next)
        return NULL;

    Node *s, *f;
    s = f = head;

    do {
        s = s->next;
        f = f?f->next:f;
        f = f?f->next:f;
    }while(s && f && s!=f);
    
    if(!s || !f)
        return NULL;
    
    f = head;
    while(s != f) {
        s = s->next;
        f = f->next;
    }
    return s;
}


















