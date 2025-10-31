class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle (slow = mid)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        // Step 3: Compare both halves
        ListNode* temp = secondHalf;
        while (temp) {
            if (firstHalf->val != temp->val)
                return false;
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // (Optional) Step 4: Restore list if needed
        // reverseList(secondHalf);

        return true;
    }
};
