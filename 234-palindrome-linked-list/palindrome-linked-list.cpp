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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        int n = 1;
        while(fast!=NULL && fast->next != NULL){
            n++;
            fast = fast->next;
        }
        if(n==1) return true;
        for(int i = 0; i<n/2; i++){
            st.push(slow->val);
            slow = slow->next;
        }
        if(n%2==1) slow = slow->next;
        for(int  i =0; i<n/2 ; i++){
            if(st.top()!=slow->val) return false;
            st.pop();
            slow = slow->next;
        }
        return true;
    }
};