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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        // ListNode* start = head;
        ListNode* temp = head;
        ListNode* tempNext = head->next;
        ListNode* tempAnd2 = head;
        ListNode* siz = head;
        int n = 1;
        while(siz->next!=NULL) {
            n++;
            siz = siz->next;}
        if(n==0 || n==1) return head;
        if(k>n) k = k%n;
        if(k==0) return head;
        if(k==n) return head;
        for(int i = 0; i<k; i++) tempAnd2 = tempAnd2->next;
        while(tempAnd2->next!=NULL){
            tempAnd2 = tempAnd2->next;
            temp = temp->next;
            tempNext = tempNext->next;
        }
        temp->next = NULL;
        tempAnd2->next = head;
        return tempNext;
    }
};