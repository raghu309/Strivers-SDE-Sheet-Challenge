

bool detectCycle(Node *head)
{
    if(!head || !head->next)
        return false;
	Node *s, *f;
    s = f = head;

    do {
        s = s->next;
        f = f?f->next:f;
        f = f?f->next:f;
    }while(s && f && s!=f);
    if(!f) return false;
    return true;
}













