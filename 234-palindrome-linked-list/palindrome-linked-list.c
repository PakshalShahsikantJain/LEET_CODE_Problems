struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // 1. Find middle
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse second half
    struct ListNode* right = reverse(slow);

    // 3. Compare both halves
    struct ListNode* left = head;
    while (right != NULL) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}