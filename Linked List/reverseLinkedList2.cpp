// Without a dummy node

ListNode* reverseList(ListNode* head, int size){
    ListNode *next, *curr = head, *prev = NULL;
    while(curr && size--){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(curr)
        head->next = curr;
    head = prev;
    return head;
}
ListNode* reverseBetween(ListNode* head, int left, int right)     {
    if(!head || !head->next || left == right)
        return head;
    ListNode *curr = head, *prev = NULL;
    int size = right-left+1;
    while(--left){
        prev = curr;
        curr = curr->next;
    }
    if(!prev)
        return reverseList(curr, size);
    
    prev->next = reverseList(curr, size);
    return head;
}

//With a dummy node

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *leftPrev  = dummy, *curr = head;
    int size = right - left + 1;

    while(--left){
        leftPrev = curr;
        curr = curr->next;
    }
    ListNode *prev = NULL, *nex;
    while(curr && size--){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    leftPrev->next->next = curr;
    leftPrev->next = prev;
    return dummy->next;
}