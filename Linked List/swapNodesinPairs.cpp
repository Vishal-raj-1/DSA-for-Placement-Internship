// Recursive

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    
    return next;
}

// Iterative

ListNode* swapPairs(ListNode *head){
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *curr = head;
    ListNode *newHead = head->next;
    while(curr && curr->next){
        ListNode *temp = curr;
        curr = temp->next;
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
        if(curr && curr->next)
            temp->next = curr->next;
    }
    return newHead;
}