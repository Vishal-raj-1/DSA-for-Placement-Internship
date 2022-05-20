// Iterative Solution

ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// Recursive Solution

ListNode* reverseList(ListNode* head){
    if(!head || !head->next)
        return head;
        
    ListNode* temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return temp;
}