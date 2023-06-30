
Node *rotate(Node *head, int k) {
     if(!head)
          return head;
     Node* t = head;
     int n = 1;
     while(t && t->next) {
          t = t->next;
          n++;
     }
     t->next = head;
     k = k%n;
     k = n-k;
     while(k) {
          head = head->next;
          t = t->next;
          k--;
     }
     t->next = NULL;
     return head;
     
}