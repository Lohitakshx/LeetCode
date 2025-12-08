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
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* fast = dummy;
        while(n){
            fast = fast->next;
            n--;
        }
        ListNode* temp = dummy;
        while(fast && fast->next){
            temp = temp->next;
            fast = fast->next;
        }
        temp ->next = temp->next->next;
        return dummy->next;
    }
};