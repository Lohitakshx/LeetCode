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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sList = new ListNode(0, NULL);
        ListNode* bList = new ListNode(0, NULL);
        ListNode* sHead = sList;
        ListNode* bHead = bList;

        while(head){
            if(head->val < x) {
                sHead->next = head;
                sHead = sHead->next;
            }
            else {
                bHead->next = head;
                bHead = bHead->next;
            }
            head = head->next;
        }
        bHead->next = NULL;
        sHead ->next = bList->next;
        return sList->next;
    }
};