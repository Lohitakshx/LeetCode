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
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        for(int i = 1; i<left; i++) pre = pre->next;
        ListNode* tail = pre->next;
        for(int i = 0; i<right-left; i++) tail = tail->next;
        ListNode * end = tail->next;
        tail ->next = NULL;
        ListNode* newHead = reverse(pre->next);
        pre->next = newHead;
        ListNode* temp = head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }
        while(temp&&temp->next){
            temp = temp->next;
            cout<<temp->val<<" ";
        }
        temp->next = end;
        return dummy->next;
    }
};