#include <bits/stdc++.h>

Node* rev(Node *head) {
	Node *p = NULL, *q = head, *r = head->next;
	while(q) {
		q->next = p;
		p = q;
		q = r;
		r = r?r->next:r;
	}
	return p;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(!head) return NULL;
	vector<Node*> vec;
	Node *t = head;
	Node *p;
	for(int i=0; i<n && t; i++) {
		int bs = b[i];
		if(bs == 0)
			continue;
		vec.push_back(t);
		for(int j=1; j<bs && t; j++) {
			t = t?t->next:t;
		}
		p = t?t->next:t;
		if(t)
			t->next = NULL;
		t = p;
	}
	if(vec.size() == 0)
		return head;
	for(auto &h:vec) {
		h = rev(h);
	}
	head = vec[0];
	t = head;
	for(int i=1; i<vec.size(); i++) {
		while(t->next)
			t = t->next;
		t->next = vec[i];
	}
	if(p) {
		while(t->next)
			t = t->next;
		t->next = p;
	}
	
	
	return head;
}









