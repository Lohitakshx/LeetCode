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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) return head;
        ListNode* curr = head;
        ListNode* dummy  = new ListNode(0, head);
        ListNode* pre = dummy;
        
        unordered_set<int> st(nums.begin(), nums.end());
        while(curr){
            ListNode* next = curr->next;
            if(st.find(curr->val)!=st.end()){
                pre->next = next;
                curr = pre->next;
            }
            else{
                pre = pre->next;
                curr = curr->next;
            }
            
            

        }
        return dummy->next;
    }
};