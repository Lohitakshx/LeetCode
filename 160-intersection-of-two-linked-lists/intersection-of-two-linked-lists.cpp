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
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1){
            st1.push(temp1);
            temp1 = temp1 -> next;
        }
        while(temp2){
            st2.push(temp2);
            temp2 = temp2 -> next;
        }
        ListNode* temp = NULL;
        while(!st1.empty() && !st2.empty()){
            // cout<<st1.top()->val<<" "<< st2.top()->val<<endl;
            if(st1.top()==st2.top()){
                temp = st1.top();
                st1.pop(), st2.pop();
            } 
            else break;
        
        }
        return temp;
    }
};