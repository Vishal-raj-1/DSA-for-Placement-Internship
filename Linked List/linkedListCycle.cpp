// Two Pointer approach for Linked List Cycle

bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast)
            return true;
    }
    return false;
}

// Two Pointer approach for Linked List Cycle II

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
