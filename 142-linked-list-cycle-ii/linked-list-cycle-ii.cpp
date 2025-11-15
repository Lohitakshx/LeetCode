class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        return find(head, seen);
    }

private:
    ListNode* find(ListNode* node, std::unordered_set<ListNode*>& seen) {
        if (!node) return nullptr;
        if (seen.find(node) != seen.end()) return node;
        seen.insert(node);
        return find(node->next, seen);
    }
};