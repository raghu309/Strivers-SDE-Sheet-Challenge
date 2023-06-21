/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    K--;
    Node* t = head;
    while(K) {
        t = t->next;
        K--;
    }
    Node* d = head;
    Node* p = NULL;
    while(t->next) {
        p = d;
        d = d->next;
        t = t->next;
    }
    if(p == NULL)
        return head->next;
    
    p->next = p->next->next;
    return head;
}














