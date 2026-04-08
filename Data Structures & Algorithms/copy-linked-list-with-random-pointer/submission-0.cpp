/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ump;
        Node* head1 = head;
        Node* head2 = new Node(0);
        Node* temp = head2;
        while (head1) {
            Node* n = new Node(head1->val);
            head2->next = n;
            head2 = n;
            ump[head1] = n;
            head1 = head1->next;
        }
        head1 = head;
        head2 = temp->next;
        while (head1) {
            head2->random = ump[head1->random];
            head1 = head1->next;
            head2 = head2->next;
        }
        return temp->next;
    }
};