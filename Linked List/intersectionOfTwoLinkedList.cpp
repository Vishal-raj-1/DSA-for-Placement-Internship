// Better Solution

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> st;
    ListNode* curr = headA;
    while(curr){
        st.insert(curr);
        curr = curr->next;
    }
    
    curr = headB;
    while(curr){
        if(st.find(curr) != st.end())
            return curr;
        curr = curr->next;
    }
    return NULL;
}

// Optimal Solution 1

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tempA = headA, *tempB = headB;
    int Asize = 0, Bsize = 0;
    while(tempA){
        Asize++;
        tempA = tempA->next;
    }
    
    while(tempB){
        Bsize++;
        tempB = tempB->next;
    }
    tempA = headA, tempB = headB;
    while(tempA && Asize > Bsize){
        Asize--;
        tempA = tempA->next;
    }
    while(tempB && Bsize > Asize){
        Bsize--;
        tempB = tempB->next;
    }
    while(tempA && tempB){
        if(tempA == tempB)
            return tempA;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}

// Optimal Solution

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(headA == NULL || headB == NULL)
        return NULL;

    ListNode *a = headA, *b = headB;

    while(a != b){
        a = a == NULL ? headB: a->next;
        b = b == NULL ? headA: b->next;
    }
    return a;
}