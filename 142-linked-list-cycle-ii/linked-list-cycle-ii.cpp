class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;

        while (head) {
            if (seen.find(head) != seen.end()) {
                return head;
            }
            seen.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};