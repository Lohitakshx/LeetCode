class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;

        // Step 1: Push first half using slow-fast pointers
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: If odd length, skip the middle element
        if (fast != nullptr) slow = slow->next;

        // Step 3: Compare with stack
        while (slow) {
            if (st.top() != slow->val) return false;
            st.pop();
            slow = slow->next;
        }

        return true;
    }
};
