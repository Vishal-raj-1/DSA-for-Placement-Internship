// Solution of Remove Duplicate From Sorted List

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while(curr && curr->next){
        if(curr->val == curr->next->val){
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
            curr = curr->next;
    }
    return head;
}

// Solution of Remove Duplicate From Sorted List II 
 
ListNode *deleteDuplicates(ListNode *head){
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;
    while (head)
    {
        if(head->next && (head->val == head->next->val)){
            while (head->next && (head->val == head->next->val))
                head = head->next;
            
            prev->next = head->next;
        }
        else{
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
}