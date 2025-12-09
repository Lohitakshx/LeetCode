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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = head;
        ListNode* end = head;
        while(end->next && end->next->next){
            mid = mid->next;
            end = end->next->next;
        }
        ListNode* midNext = mid->next;
        mid ->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(midNext);
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(left && right){
            if(left -> val <= right -> val){
                temp -> next = left;
                left = left->next;
            }
            else{
                temp -> next = right;
                right = right -> next;
            }
            temp = temp->next;
        }
        temp->next = left ? left : right;
        return dummy->next;
    }
};