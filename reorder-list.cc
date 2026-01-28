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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* curr_next = head;
        ListNode* prev = NULL;

        while(curr_next) {
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        return prev;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        while(curr1 && curr2) {
            ListNode* temp1 = curr1->next; 
            ListNode* temp2 = curr2->next; 
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
        return head1;
    }


    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) { // find mid point to reverse later half
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = slow->next;
        slow->next = NULL;

        h2 = reverse(h2);

        head = merge(h1,h2);
        return;
    }
};
