// Two Passes solution: By Calculating size 

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* temp = head;
    while(temp){
        size++;
        temp = temp->next;
    }
    n = size-n;
    temp = head;
    while(temp && --n)
        temp = temp->next;

    if(temp == NULL){
        return head->next;
    }
    ListNode* temp1 = temp->next;
    temp->next = temp->next->next;
    delete temp1;
    return head;
}

// Single Pass Solution

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head, *fast = head;
    while(n--){
        fast = fast->next;
    }
    if(fast == NULL)
        return head->next;
    
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}