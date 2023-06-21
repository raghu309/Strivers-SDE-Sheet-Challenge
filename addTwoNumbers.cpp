/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *t1=num1, *t2=num2;
    Node *dummy = new Node(0);
    Node *t = dummy;
    int carry = 0;
    while(t1 || t2) {
        int res = (t1?t1->data:0) + (t2?t2->data:0) + carry;
        t->next = new Node(res % 10);
        carry = res / 10;
        t = t->next;
        t1 = t1?t1->next:t1;
        t2 = t2?t2->next:t2;
    }
    while(carry) {
        t->next = new Node(carry % 10);
        carry /= 10;
    }
    t = dummy->next;
    dummy->next = NULL;
    return t;
}










