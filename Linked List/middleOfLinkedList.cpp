// Solution 1: Calculate size of list, then return (n/2 + 1)th node

ListNode* middleNode(ListNode* head) {
    ListNode* curr = head;
    int size = 0;
    while(curr != NULL){
        curr = curr->next;
        size++;
    }
    
    curr = head;
    size /= 2;
    while(curr != NULL && size--){
        curr = curr->next;
    }
    return curr;
}

// Solution 2: Two pointer approach

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}