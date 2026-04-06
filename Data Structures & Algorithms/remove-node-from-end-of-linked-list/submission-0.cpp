class Solution {
private: 
    int llLength(ListNode* head) {
        if (head == nullptr) return 0;
        return 1 + llLength(head->next);
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = llLength(head);
        int cut = length - n;
        if (cut == 0) return head->next;
        ListNode* it = head;
        while (--cut > 0) {
            it = it->next;
        }
        it->next = it->next->next;
        return head;
    }
};