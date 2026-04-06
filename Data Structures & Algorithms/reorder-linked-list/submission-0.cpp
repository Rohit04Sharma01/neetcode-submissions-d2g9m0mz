/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* l1 = head;
        ListNode* l2 = reverseList(slow);
        bool turn = true;
        while (l1 != nullptr && l2 != nullptr) {
            if(turn){
                ListNode* temp = l1->next;
                l1->next = l2;
                l1 = temp;
            } else {
                ListNode* temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
            turn = !turn;
        }
    }
};