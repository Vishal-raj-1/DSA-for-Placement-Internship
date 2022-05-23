// Solution

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode *odd = head, *even = head->next, *evenHead = even;
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenHead;
    return head;
}