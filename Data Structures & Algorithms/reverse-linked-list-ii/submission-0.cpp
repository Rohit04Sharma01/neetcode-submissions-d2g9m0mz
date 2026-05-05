class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Move prev to node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // Move to 'right'
        ListNode* tail = curr;
        for (int i = left; i < right; i++) {
            tail = tail->next;
        }

        ListNode* nextPart = tail->next;
        tail->next = nullptr;

        // Reverse sublist
        prev->next = reverseList(curr);
        curr->next = nextPart;

        return dummy.next;
    }
};