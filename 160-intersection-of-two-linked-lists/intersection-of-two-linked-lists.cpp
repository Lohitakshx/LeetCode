/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow = headA;
        ListNode* fast  = headB;
        while(slow){
            fast = headB;
            while(fast){
                if(slow==fast) return slow;
                fast = fast->next;
            }
            slow = slow->next; 
        }
        return NULL;
    }
};