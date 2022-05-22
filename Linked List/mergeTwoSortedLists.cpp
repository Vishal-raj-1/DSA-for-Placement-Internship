// Iterative Solution without dummy node

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    ListNode* head, *curr;
    if(l1->val> l2->val){
        head = l2;
        l2 = l2->next;
    }
    else{
        head = l1;
        l1 = l1->next;
    }
    
    curr = head;
    while(l1 && l2){
        if(l1->val> l2->val){
            curr->next = l2;
            l2 = l2->next;
        }
        else{
            curr->next = l1;
            l1 = l1->next;
        }
        curr = curr->next;
    }
    if(l1)
        curr->next = l1;
    if(l2)
        curr->next = l2;
    
    return head;
}

// iterative solution with dummy node

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy, *curr;
    dummy = new ListNode();
    curr = dummy;

    while(l1 && l2){
        if(l1->val> l2->val){
            curr->next = l2;
            l2 = l2->next;
        }
        else{
            curr->next = l1;
            l1 = l1->next;
        }
        curr = curr->next;
    }
    if(l1) curr->next = l1;
    if(l2) curr->next = l2;
    return dummy->next;
}

// Recursive Solution

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(!l1)
        return l2;

    if(!l2)
        return l1;

    ListNode* node = new ListNode();

    if(l1->val < l2->val)
    {
        node->val = l1->val;
        node->next = mergeTwoLists(l1->next,l2);
    }
    else
    {
        node->val = l2->val;
        node->next = mergeTwoLists(l1,l2->next);
    }
    return node;
}