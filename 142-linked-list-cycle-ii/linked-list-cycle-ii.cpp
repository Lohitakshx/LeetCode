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
    ListNode *detectCycle(ListNode *head) {
      
        ListNode* slow  = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast= fast->next->next;
            slow = slow->next;
            if(fast==slow) break; //funfact : this collsion point distance from the head is the length of the cycle
        }
        if (!fast || !fast->next) return nullptr;
        fast = head; // ans now when you ake fast to head: they will meet at collion only
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};