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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;

        ListNode* first = new_head;
        ListNode* second = new_head;

        for(int i=0; i<=n; i++) first = first->next;

        while(first) {
            first = first->next;
            second = second->next;
        }

        ListNode* node_to_be_deleted = second->next;
        second->next = second->next->next;
        delete node_to_be_deleted;
        return new_head->next;
    }
};
