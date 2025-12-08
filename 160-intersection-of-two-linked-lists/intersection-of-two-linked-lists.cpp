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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st;

        for (ListNode* a = headA; a; a = a->next)
            st.insert(a);

        for (ListNode* b = headB; b; b = b->next)
            if (st.count(b)) return b;

        return nullptr;
    }

};