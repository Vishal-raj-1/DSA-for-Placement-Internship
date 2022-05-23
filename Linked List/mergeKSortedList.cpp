// Solution of Merge two sorted lists 

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

// Solution 1: K-1 times Merge 2 Sorted lists

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if(k == 0)
        return NULL;
    if(k == 1)
        return lists[0];
    ListNode* curr = mergeList(lists[k-1], lists[k-2]);
    for(int i=k-3; i>= 0; i--){
        curr = mergeList(lists[i], curr);
    }
    return curr;
}

// Solution 2: logK times Merge 2 Sorted lists

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int length = lists.size(), interval = 1;
    while(interval < length){
        for(int i=0; i<length-interval; i += interval*2){
            lists[i] = mergeList(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    return length > 0 ? lists[0] : NULL;
}

// Solution 3: Using Priority Queue

struct compare{
    bool operator()(const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<ListNode*, vector<ListNode*>, compare> q;
    for(auto l : lists){  
            if(l)
            q.push(l);
    }
    ListNode pre(0);
    ListNode *node = &pre;
    while (q.size()){
        ListNode *top = q.top();
        q.pop();
        node->next = top;
        node = node->next;
        if(top->next)
            q.push(top->next);

    }
    return pre.next;
}