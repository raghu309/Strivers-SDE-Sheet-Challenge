

Node* sortedMerge(Node* p1, Node* p2) {
	Node* dummy = new Node(0);
	Node* t = dummy;

	while(p1 && p2) {
		if(p1->data < p2->data) {
			t->child = p1;
			t = p1;
			p1 = p1->child;
		}else {
			t->child = p2;
			t = p2;
			p2 = p2->child;
		}
	}
	if(p1)
		t->child = p1;
	if(p2)
		t->child = p2;
	return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(!head) return head;
	Node *ret;
	Node *t = head->next;
	head->next = NULL;
	while(t) {
		head = sortedMerge(head, t);
		ret = t;
		t = t->next;
		ret->next = NULL;
	}
	return head;
}








